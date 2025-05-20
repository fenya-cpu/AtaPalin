#include <iostream>
#include <string>
#include <functional>
#include <windows.h>
using namespace std;

class Spovishchennya 
{
protected:
    string zagolovok;
    string tekst;
public:
    Spovishchennya(const string& zag,const string& txt):zagolovok(zag),tekst(txt){}

    virtual void vyvesty() const 
	{
        cout<<"Заголовок: "<<zagolovok<<endl;
        cout<<"Текст: "<<tekst<<endl;
    }

    virtual ~Spovishchennya() {}
};

enum RivenVazhlyvosti {NYZKIY,SEREDNIY,VYSOKIY };

class VazhlyveSpovishchennya:public Spovishchennya 
{
private:
    RivenVazhlyvosti riven;
    function<void()> dodatkovaDiya;
public:
    VazhlyveSpovishchennya(const string& zag,const string& txt,RivenVazhlyvosti riv)
        : Spovishchennya(zag,txt),riven(riv),dodatkovaDiya(nullptr) {}

    void vstanovytyDodatkovuDiyu(function<void()> f) 
	{
        dodatkovaDiya = f;
    }

    void vyvesty() const override 
	{
        cout<<"ВАЖЛИВЕ СПОВІЩЕННЯ\n";
        Spovishchennya::vyvesty();
        cout<<"Рівень важливості: ";
        switch (riven) 
		{
            case NYZKIY:cout<<"Низький"; 
			break;
            case SEREDNIY:cout<<"Середній"; 
			break;
            case VYSOKIY:cout<<"Високий"; 
			break;
        }
        cout<<endl;

        if(riven==VYSOKIY&&dodatkovaDiya) 
		{
            dodatkovaDiya();
        }
    }
};

int main() 
{
	SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    VazhlyveSpovishchennya sp("Увага","Система буде перезавантажена",VYSOKIY);

    sp.vstanovytyDodatkovuDiyu([]() 
	{
        cout<<"Потрібне підтвердження!"<<endl;
    });

    sp.vyvesty();

    return 0;
}
