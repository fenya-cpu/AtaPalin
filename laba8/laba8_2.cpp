#include <iostream>
#include <cstring>

using namespace std;

class People {
private:
    string surname;
    string country;
    char gender;
    string education;
    int birthYear;
    int age;

public:
    //Konstructor za zamovciuniam
    People() : surname(""), country("Ukraine"), gender('M'), education("Serednia"), birthYear(2006), age(18) {}

    //Konstructor s parametrom
    People(string sname, string cntry, char g, string edu, int bYear) 
        : surname(sname), country(cntry), gender(g), education(edu), birthYear(bYear) 
	{
        age = 2025 - birthYear;
    }

    //Metod vedenia danyh
    void input() 
	{
        cout<<"Vediti pryzvyshe: ";
		cin>>surname;
        cout<<"Vediti krainu projyvania: "; 
		cin>>country;
        cout<<"Vediti stati' (M/F): "; 
		cin>>gender;
        cout<<"Vediti osvitu:(V/S) "; 
		cin>>education;
        cout<<"Vediti rik narodjenia: "; 
		cin>>birthYear;
        age=2024-birthYear;
    }

    //metod vyvodu
    void display() const {
        cout << "Pryzvishe: " << surname << ", Kraina: " << country
             << ", Stati: " << gender << ", Osvita: " << education
             << ", Rik narodjennya: " << birthYear << ", Vik: " << age << endl;
    }

    //gets
    string getEducation() const { return education; }
    int getAge() const { return age; }
    char getGender() const { return gender; }

    //destructor
    ~People() {
    	
    }
};

//dlia vyvedenya liudei pid umovoiu
void filtr(People arr[], int size, int minAge) 
{
    cout<<"\nLiudyna z vyshoiu osvtoiu ta vikom bilishe " << minAge << ":" << endl;
    for (int i=0;i<size;i++) 
	{
        if (arr[i].getEducation() == "V" && arr[i].getAge() > minAge) 
		{
            arr[i].display();
        }
    }
}

//vydalenia osib pevnoi stati
void remove(People arr[], int &size, char g) 
{
    int newSize = 0;
    for (int i=0;i<size; i++) 
	{
        if (arr[i].getGender()!=g) 
		{
            arr[newSize++]=arr[i];
        }
    }
    size=newSize;
}

int main() 
{
    int n;
    cout<<"Vediti kilkisti liudei: ";
    cin>>n;
    People people[n];

    cout<<"Vediti dani pro liudei:\n";
    for (int i=1;i<n;i++) 
	{
		people[i]=People();
        cout<<"Liudina "<<i+1<<":\n";
        people[i].input();
    }

    cout<<"\nSpysok usih liudei:\n";
    for (int i=0;i<n;i++) 
	{
        people[i].display();
    }
    filtr(people, n, 25);
    char genderToRemove;
    cout<<"\nVediti stati dlya vydalenia (M/F): ";
    cin>>genderToRemove;
    int newSize=n;
    remove(people, newSize, genderToRemove);

    cout<<"\nNovyi spysok "<<":\n";
    for (int i=0;i<newSize;i++) 
	{
        people[i].display();
    }
    
    return 0;
}

