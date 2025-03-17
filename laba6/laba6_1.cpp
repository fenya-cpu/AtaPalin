#include <iostream>
#include <fstream>
#include <cmath>
#include <cctype>

using namespace std;


void tolow(string &slovo) 
{
    for(int i=0;i<slovo.length();i++) 
	{
    	slovo[i]=tolower(slovo[i]);
	}

}

int main() 
{
    ifstream inputFile("text.txt");
	if (!inputFile) 
	{
        cout<<"ne vidkryvaetsa"<<endl;
        return 1;
    } 

    string s[100]; 
    int ks=0;

    string slovo;
    while(inputFile>>slovo) 
	{
        s[ks++]=slovo;
    }
    inputFile.close();

    string t[100];//masyv dlia 3 liter
    string vb[100];//masyv dlia nevelykyh pershyh liter
    int tk=0,vbk=0;

    for(int i=0;i<ks;i++) 
	{
        if(s[i].length()==3) 
		{
            t[tk++]=s[i];
        }
        if (!isupper(s[i][0])) 
		{
            vb[vbk++]=s[i];
        }
    }

    cout<<"Slovo scho maiuti 3 litery: ";
    for(int i=0;i<tk;i++) 
	{
        cout<<t[i]<<" ";
    }
    cout<<endl;


    cout<<"Slova sho ne pochynaiutsea z velykoi litery: ";
    for(int i=0;i<vbk;i++) 
	{
        cout<<vb[i]<<" ";
    }
    cout<<endl;

    string search;
    cout<<"Slovo yake treba shukaty: ";
    cin>>search;
    tolow(search);

    int kilk=0;
    for (int i=0;i<ks;i++) 
	{
        string temp=s[i];
        tolow(temp);
        if(temp==search) 
		{
            kilk++;
        }
    }

    cout<< "Slovo -" <<search<<",zustrichaetsa "<<kilk<< " raz"<<endl;

return 0;
}

