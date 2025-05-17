#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
using namespace std;

class Pracivnyk 
{
protected:
    int id;
    string prizvyshche;
public:
    Pracivnyk(int id, const string& prizvyshche):id(id),prizvyshche(prizvyshche){}

    virtual double zarplata() const=0;

    int getId() const {return id;}
    string getPrizvyshche() const {return prizvyshche;}

    bool operator==(const Pracivnyk& other) const 
	{
        return this->id==other.id;
    }

    virtual ~Pracivnyk() {}
};

class Menedzher : public Pracivnyk 
{
private:
    int kilkistPidleglyh;
    const double stavka=10000.0;
public:
    Menedzher(int id,const string& prizvyshche,int kilkistPidleglyh)
        : Pracivnyk(id,prizvyshche),kilkistPidleglyh(kilkistPidleglyh) {}

    double zarplata() const override 
	{
        double bonus=(kilkistPidleglyh>5)?stavka*0.1:0.0;
        return stavka+bonus;
    }
};

class Rozrobnyk:public Pracivnyk 
{
private:
    int kilkistGodyn;
    const double pohodynnaStavka=100.0;
public:
    Rozrobnyk(int id,const string& prizvyshche,int kilkistGodyn)
        : Pracivnyk(id,prizvyshche),kilkistGodyn(kilkistGodyn) {}

    double zarplata() const override 
	{
        return kilkistGodyn*pohodynnaStavka;
    }
};

int main() 
{
	SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    vector<Pracivnyk*> pracivnyky;

    pracivnyky.push_back(new Menedzher(1,"Руснак",6));
    pracivnyky.push_back(new Menedzher(2,"Луханін",4));
    pracivnyky.push_back(new Rozrobnyk(3,"Мельник",160));
    pracivnyky.push_back(new Rozrobnyk(4,"Мірош",180));

    cout<<"Інформація про зарплати:\n";
    for(Pracivnyk* p:pracivnyky) 
	{
        cout<<"ID: "<<p->getId()<<", Прізвище: "<<p->getPrizvyshche()<<", Зарплата: "<<p->zarplata()<<" грн"<<endl;
    }

    cout<<"\nДемонстрація оператора '==':\n";
    if(*pracivnyky[0]==*pracivnyky[1])
        cout<<"Працівник 1 і 2 мають однаковий ID\n";
    else
        cout<<"Працівник 1 і 2 мають різні ID\n";
        
    for(Pracivnyk* p:pracivnyky)
        delete p;

    return 0;
}
