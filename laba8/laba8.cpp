#include <iostream>
using namespace std;

class Flat {
private:
    string address;
    int floor;
    int rooms;
    double area;

public:
    //constructor za zamovciuvani
    Flat() : address(""), floor(0), rooms(2), area(55.0) {}

    Flat(string addr, int fl, int rm, double ar) : address(addr), floor(fl), rooms(rm), area(ar) {}

    //metotd vvoda danyh
    void input() 
	{
        cout<<"Vediti adress: ";
        cin>>address;
        cout<<"Vediti etaj: ";
        cin>>floor;
        cout<<"Vediti kilkisti kimnat: ";
        cin>>rooms;
        cout<<"Vediti ploshad': ";
        cin>>area;
    }

    //metod cout
    void display() const 
	{
        cout<<"Adress: "<<address<<", Etaj: "<<floor<<", Kimnata: "<<rooms<<", Ploshad': "<<area<<" m^2"<<endl;
    }

    //gets
    int getRooms() const { return rooms; }
    double getArea() const { return area; }
    int getFloor() const { return floor; }

    //destructor
    ~Flat() 
	{
        cout<<"Vydalenia obiecta Flat: "<<address<<endl;
    }
};

void filt(Flat flats[], int size, int rooms, double maxArea, int minFloor, int maxFloor) 
{
    cout<<"Kvartyry s "<<rooms<<" kimnatamy, ploshadiu <= "<<maxArea<<" m^2, na etajah "<<minFloor<<"-"<<maxFloor<<":"<<endl;
    for (int i=0;i<size;i++) 
	{
        if(flats[i].getRooms()==rooms && flats[i].getArea() <= maxArea && flats[i].getFloor() >= minFloor && flats[i].getFloor() <= maxFloor) 
		{
            flats[i].display();
        }
    }
}

int main() 
{
    int n;
    cout<<"Vediti kilkisti kvartyr: ";
    cin>>n;
    Flat flats[n];

    cout<<"Vediti dani: "<<endl;
    for (int i=1;i<n;i++) 
	{
		flats[0]=Flat();
        cout<<"Kvartira "<<i+1<<":"<<endl;
        flats[i].input();
    }

    cout<<"\nSpysok usih kvartyr:\n";
    for (int i=0;i<n;i++) 
	{
        flats[i].display();
    }

    cout<<"\nFiltr po kvartyram:\n";
    filt(flats, n, 2, 40.0, 1, 5);
    cout<<endl;
    return 0;
}

