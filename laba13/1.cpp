#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;


class Pracivnyk 
{
protected:
    int vik;
    int stazhVodinnya;

public:
	string prizvyshche;
    Pracivnyk(string p="",int v=0,int s=0)
    : prizvyshche(p), vik(v), stazhVodinnya(s) {}

    void zmintyDani(string p, int v, int s) 
	{
        if (v<0 || s<0)
            throw invalid_argument("Vik abo Staj ne mojuti buty vid'iemnymy!");
        prizvyshche=p;
        vik=v;
        stazhVodinnya=s;
    }
    
    int Stazh() const 
	{return 2025-stazhVodinnya;}
	
    void vyvestyInfo() const 
	{
        cout<<"prizvyshche: "<<prizvyshche<<", vik: "<<vik<<",staj vodinnya: "<<stazhVodinnya<<" rokiv, "<<"Rik pochatku staju: "<<Stazh()<<" rokiv"<<endl;
    }

};


class Avtomobil 
{
protected:
    int rikVypusku;
    int probig;

public:
	string reestrNom;
    string marka;
    
    Avtomobil(string rn="", string m="", int rv=0, int p=0)
        : reestrNom(rn), marka(m), rikVypusku(rv), probig(p) {}

    void zmintyDani(string rn, string m, int rv, int p) 
	{
        if(rv<0 || p<0)
            throw invalid_argument("Rik vypusku abo probig ne mojuti buty vid'iemnymy!");
        reestrNom = rn;
        marka = m;
        rikVypusku = rv;
        probig = p;
    }
    
	int ser() const 
	{return probig/(2025-rikVypusku);}
	
    void vyvestyInfo() const 
	{
        cout<<"Nomer: "<<reestrNom<<", Marka: "<<marka<<", Rik vypusku: "<<rikVypusku<< ", Probig: "<<probig<<" km,"<<" Serednioricinyi probig: "<<ser()<<endl;
    }

};


class Vodiy : public Pracivnyk, public Avtomobil 
{
private:
    int rikvyk;
    bool shtrafy;

public:
    Vodiy(string p="",int v=0,int s=0,
          string rn="",string m="",int rv=0,int pbg=0,
          int rpv=0,bool sh=false)
        : Pracivnyk(p, v, s),Avtomobil(rn, m, rv, pbg),rikvyk(rpv), shtrafy(sh) {}

    void zmintyDani(string p, int v, int s,
                    string rn, string m, int rv, int pbg,
                    int rpv, bool sh) 
	{
        if (v<0||s<0||rv<0||pbg<0||rpv<0)
            throw invalid_argument("Ne mojuti buty vid'iemnymy!");
        prizvyshche=p;
        vik=v;
        stazhVodinnya=s;
        reestrNom=rn;
        marka=m;
        rikVypusku=rv;
        probig=pbg;
        rikvyk=rpv;
        shtrafy=sh;
    }

    void vyvestyInfo() const 
	{
        cout<<"==== Info pro vodiya ===="<<endl;
        Pracivnyk::vyvestyInfo();
        Avtomobil::vyvestyInfo();
        cout<<"Rik pochatku vykorystania avtomobiliu: "<<rikvyk<<endl;
        cout<<"Nayavnisty shtrafiv: "<<(shtrafy?"Tak":"Ni")<<endl;
    }

    void porivnyatyVikTaStazh(int potocnyRik)const 
	{
        int vikAvto=potocnyRik-rikVypusku;
        cout<<"Vik avtomobilya: "<<vikAvto<<" rokiv"<<endl;
        cout<<"Staj vodinya: "<<stazhVodinnya<<" rokiv"<<endl;

        if(vikAvto>stazhVodinnya)
            cout<<"Avtomibily starshyi za staj vodiya"<<endl;
        else if (vikAvto<stazhVodinnya)
            cout<<"Staj vodinya bilishyi za vik avtomobilya"<<endl;
        else
            cout<<"Staj vodinya=vik avto"<<endl;
    }
};


int main() 
{
    try 
	{
        Vodiy v("Rusnak",40,20,"AT0224IH","Volkswagen",2010,200000,2015,true);
        v.vyvestyInfo();

        cout<<endl<<"Onovlenii dani:"<<endl;
        v.zmintyDani("Luhanin",35,15,"BC5678CC","Skoda",2018,90000,2019,false);
        v.vyvestyInfo();

        cout<<endl;
        v.porivnyatyVikTaStazh(2025);

    } 
	catch(const exception& e) 
	{
        cout<<"Pomylka: "<<e.what()<<endl;
    }

    return 0;
}
