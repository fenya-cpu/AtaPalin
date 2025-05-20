#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <windows.h>
using namespace std;

class Tovar 
{
protected:
    string nazva;
    double tsina;
public:
    Tovar(const string& n, double t):nazva(n),tsina(t){}
    virtual double otrymatyTsyinu() const 
	{
        return tsina;
    }
    virtual void pokazaty() const 
	{
        cout<<"Назва: "<<nazva<<", Ціна: "<<tsina<<" грн"<<endl;
    }
    virtual ~Tovar(){}
};

class TovarZiZnizhkoyu :public Tovar{
private:
    double znyzhka;
public:
    TovarZiZnizhkoyu(const string& n,double t,double zn)
        : Tovar(n,t),znyzhka(zn){}

    double otrymatyTsyinu() const override 
	{
        return tsina*(1.0-znyzhka/100.0);
    }

    // Метод із лямбда-функцією
    double rozrakhZnizhku(function<double(double, double)> f) const 
	{
        return f(tsina,znyzhka);
    }

    void pokazaty() const override 
	{
        cout<<"Назва: "<<nazva<<endl;
        cout<<"Початкова ціна: "<<tsina<<" грн"<<endl;
        cout<<"Ціна зі знижкою ("<<znyzhka<<"%): "<<otrymatyTsyinu()<<" грн"<<endl;
    }
};

int main() 
{
	SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    vector<Tovar*> produkty;

    produkty.push_back(new TovarZiZnizhkoyu("Ноутбук", 30000, 15));
    produkty.push_back(new TovarZiZnizhkoyu("Навушники", 1500, 10));
    produkty.push_back(new TovarZiZnizhkoyu("Смартфон", 20000, 5));

    auto lmbd=[](double tsina, double znyzhka) -> double 
	{
        return tsina*(1.0-znyzhka/100.0);
    };

    for (Tovar* p:produkty) 
	{
        p->pokazaty();

        TovarZiZnizhkoyu* pzz=dynamic_cast<TovarZiZnizhkoyu*>(p);
        if (pzz) {
            double znizhkovaTsina=pzz->rozrakhZnizhku(lmbd);
            cout << "Ціна, розрахована через лямбду: " << znizhkovaTsina << " грн\n";
        }

        cout << "--------------------------\n";
    }

    for (Tovar* p : produkty) 
	{
        delete p;
    }

    return 0;
}
