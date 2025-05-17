#include <iostream>
#include <vector>
#include <cmath>
#include <windows.h>
using namespace std;

class Figura 
{
public:
    virtual double ploshcha() const=0;
    virtual double perymetr() const=0;
    virtual ~Figura() {}
};

class Pryamokutnyk:public Figura 
{
private:
    double a,b;
public:
    Pryamokutnyk(double a,double b):a(a),b(b){}

    double ploshcha() const override 
	{
        return a*b;
    }

    double perymetr() const override 
	{
        return 2*(a+b);
    }
};

class Trykutnyk : public Figura 
{
private:
    double a,b,c;
public:
    Trykutnyk(double a,double b,double c):a(a),b(b),c(c){}

    double ploshcha() const override 
	{
        double p=(a+b+c)/2;
        return sqrt(p*(p-a)*(p-b)*(p-c));
    }

    double perymetr() const override
	 {
        return a+b+c;
    }
};

class Kolo:public Figura 
{
private:
    double radius;
public:
    Kolo(double radius):radius(radius) {}

    double ploshcha() const override 
	{
        return M_PI*radius*radius;
    }

    double perymetr() const override 
	{
        return 2*M_PI*radius;
    }
};

int main() 
{
	SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    vector<Figura*> figury;

    figury.push_back(new Pryamokutnyk(5,3));
    figury.push_back(new Trykutnyk(3,4,5));
    figury.push_back(new Kolo(2.5));

    for (int i=0;i<figury.size();i++) 
	{
        cout<<"Фігура "<<i+1<<":\n";
        cout<<"Площа: "<<figury[i]->ploshcha()<<endl;
        cout<<"Периметр: "<<figury[i]->perymetr()<<endl<<endl;
    }

    for (Figura* f:figury)
        delete f;

    return 0;
}
