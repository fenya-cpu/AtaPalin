#include <iostream>
using namespace std;

class schoolboy
{
	protected:
		string pib;
		int rik;
		int vik;
		string gender;
		int age;
		
	public:
	schoolboy():pib("rusnakAlinarkadiyovych"),rik(2006),gender("M") {}
	
	int getage() const
	{
		return 2025-rik;
	}
	
	void setInfo(const string& pip_, int rik_, const string& gender_) 
	{
        pib = pip_;
        rik = rik_;
        gender = gender_;
    }

    // Метод для виведення даних
    void display() const {
        cout << "PIB: " << pib << endl;
        cout << "Rik narodjenya: " << rik << endl;
        cout << "Stati': " << gender << endl;
        cout << "Vik: " << getage() << " rokiv" << endl;
    }
};

class Pratsivnyk : public schoolboy 
{
private:
    double salary;
    string workplace;

public:
    Pratsivnyk(const string& pip_, int rik_, const string& gender_,double salary_, const string& workplace_)
    {
        setInfo(pip_, rik_, gender_);
        salary=salary_;
        workplace=workplace_;
    }
    
    void display() const 
	{
        schoolboy::display();
        cout << "Mistse Roboty: " << workplace << endl;
        cout << "Zarplata: " << salary << " grn" << endl;
    }
};

int main()
{
	Pratsivnyk p("Rusnak Alin Arkadiyovych", 1990, "M", 15000, "Avtoservis");
    p.display();
return 0;
}