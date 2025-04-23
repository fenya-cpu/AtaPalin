#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <clocale>
#include <Windows.h>
#include <cwctype>

using namespace std;

// perevirka na holosnu
bool isVowel(char c) 
{
    c = tolower(c);
    return c == 'a' || c == 'i' || c == 'y' || c == 'e' || c == 'o';
}

// POvertae kilkisti holosbyh y slovi
int countVowels(const string& word) {
    int count = 0;
    for (char c : word) {
        if (isVowel(c)) count++;
    }
    return count;
}

// rozbyty riadok na slova
vector<string> splitWords(const string& line) {
    vector<string> words;
    string word;
    for (char c : line) {
        if (isalpha((unsigned char)c) || c == '-') {
            word += c;
        } else {
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        }
    }
    if (!word.empty()) words.push_back(word);
    return words;
}

// Rozbyty text na rechenya
vector<string> splitSentences(const string& text) {
    vector<string> sentences;
    string sentence;
    for (char c : text) {
        sentence += c;
        if (c == '.' || c == '!' || c == '?') {
            sentences.push_back(sentence);
            sentence.clear();
        }
    }
    if (!sentence.empty()) sentences.push_back(sentence);
    return sentences;
}

// Prochytaty fail yak edynyi riadok
string readWholeText(const string& filename) {
    ifstream in(filename);
    string text, line;
    while (getline(in, line)) {
        text += line + " ";
    }
    return text;
}

//punct a
string duplicateWordsWithVowels(string text) {
    vector<string> words = splitWords(text);
    string result;
    for (string& word : words) {
        result += word + " ";
        if (countVowels(word) > 2) {
            result += word + " ";
        }
    }
    return result;
}

// punct b
void findLongestWords(const string& text, vector<string>& longestWords, vector<int>& counts) {
    vector<string> words = splitWords(text);
    sort(words.begin(), words.end(), [](const string& a, const string& b) {
        return a.length() > b.length();
    });

    for (string& word : words) {
        if (longestWords.size() >= 3 && word.length() < longestWords.back().length()) break;

        bool found = false;
        for (int i = 0; i < longestWords.size(); ++i) {
            if (longestWords[i] == word) {
                counts[i]++;
                found = true;
                break;
            }
        }
        if (!found && longestWords.size() < 3) {
            longestWords.push_back(word);
            counts.push_back(1);
        }
    }
}

// punct c
vector<string> findSentencesWithWord(const string& text, const string& target) {
    vector<string> result;
    vector<string> sentences = splitSentences(text);
    for (string& sentence : sentences) {
        vector<string> words = splitWords(sentence);
        for (string& word : words) {
            if (word == target) {
                result.push_back(sentence);
                break;
            }
        }
    }
    return result;
}

//punct d
void findAndModifyWordBlock(const string& text, const string& word, string& result, int& count) {
    vector<int> positions;
    size_t pos = text.find(word);
    while (pos != string::npos) {
        positions.push_back(pos);
        pos = text.find(word, pos + word.length());
    }
    count = positions.size();
    if (count <= 1) throw runtime_error("Slovo ne znaydeno Abo zystrichaetsea lushe 1 raz");

    result = text;
    result.erase(positions[0] + word.length(), positions.back() - (positions[0] + word.length()));
}

// punct e
void formAndSortStrings(const string& z1text, const string& tfilename, string& s1, string& s2, string& s3) 
{
    vector<string> z1words = splitWords(z1text);
    int wordCount = z1words.size();
    ifstream in(tfilename);
    string word;
    vector<string> twords;
    while (twords.size() < wordCount && in >> word) {
        twords.push_back(word);
    }

    for (string& w : twords) s1 += w + " ";
    s2 = z1text;
    s3 = s1 + s2;
    vector<string> s3words = splitWords(s3);
    sort(s3words.begin(), s3words.end());
    s3.clear();
    for (string& w : s3words) s3 += w + " ";
}

int main() 
{
    string z1text = readWholeText("z1.txt");
    string menu;
    cout<<z1text;
    
    while (true) {
        cout << "\nMenyu:\n";
        cout << "1 - Prodybliyvatu slova z >2 holosnumu \n";
        cout << "2 - Tru naiydovshi slova ta iih kilikisti\n";
        cout << "3 - Rechenya z zadanumu slovom \n";
        cout << "4 - Vuvid y failu z2.txt \n";
        cout << "5 - Obrobka slova -> z3.txt\n";
        cout << "6 - Pobudova ryadkiv s1, s2, s3  -> z4.txt\n";
        cout << "0 - Exit\n";
        cin >> menu;

        if (menu == "1") {
            string result = duplicateWordsWithVowels(z1text);
            cout << "Rezultat:\n" << result << endl;
        }
        else if (menu == "2") {
            vector<string> longestWords;
            vector<int> counts;
            findLongestWords(z1text, longestWords, counts);
            for (int i = 0; i < longestWords.size(); ++i)
                cout << longestWords[i] << " - " << counts[i] << endl;
        }
        else if (menu == "3") {
            string word;
            cout << "Vediti slovo: ";
            cin >> word;
            vector<string> sentences = findSentencesWithWord(z1text, word);
            for (string& s : sentences)
                cout << s << endl;
        }
        else if (menu == "4") {
            string outPath;
            cout << "Vediti shliah do failu (napruklad, C:\\z2.txt): ";
            cin >> outPath;
            ofstream out(outPath);
            out << "a) " << duplicateWordsWithVowels(z1text) << "\n\n";
            vector<string> longestWords;
            vector<int> counts;
            findLongestWords(z1text, longestWords, counts);
            out << "b) ";
            for (int i = 0; i < longestWords.size(); ++i)
                out << longestWords[i] << " – " << counts[i] << "  ";
            out << "\n\n";
            out << "c) Rechenya z zadanum slovom potribno vvestu okremo (cherez meniu 3)";
            out.close();
            cout << "Zapusano y fail\n";
        }
        else if (menu == "5") {
            string word;
            cout << "Vediti slovo dlia poshuku: ";
            cin >> word;
            try {
                string result;
                int count;
                findAndModifyWordBlock(z1text, word, result, count);
                ofstream out("z3.txt");
                out << "Slovo: " << word << "\nKilikisti: " << count << "\nModufikovanuy riadok:\n" << result;
                out.close();
                cout << "Dani zapusano y z3.txt\n";
            } catch (runtime_error& e) {
                cout << "Pomulka: " << e.what() << endl;
            }
        }
        else if (menu == "6") {
            string s1, s2, s3;
            formAndSortStrings(z1text, "t.txt", s1, s2, s3);
            ofstream out("z4.txt");
            out << "s1: " << s1 << "\n\n";
            out << "s2: " << s2 << "\n\n";
            out << "s3 (vidsortovanyi): " << s3 << "\n";
            out.close();
            cout << "Riadku zapusanu y z4.txt\n";
        }
        else if (menu == "0") {
            break;
        }
        else {
            cout << "try again\n";
        }
    }
    return 0;
}
