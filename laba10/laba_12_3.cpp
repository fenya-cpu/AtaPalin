#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Car 
{
    string name;
    int year;
    int mileage;
};

void print(Car car) 
{
    cout<<"nazva: "<<car.name<<", rik: "<<car.year<<", Probig: "<<car.mileage<<endl;
}

void insertfirst(vector<Car>& cars) 
{
    Car c;
    cout<<"Nazva avto: ";
    cin>>c.name;
    cout<<"Rik vypusku: ";
    cin>>c.year;
    cout<<"Probig: ";
    cin>>c.mileage;
    cars.insert(cars.begin(), c);
}

void insert_start(vector<Car>& cars) 
{
    insertfirst(cars);
}

void insert_end(vector<Car>& cars) 
{
    Car c;
    cout<<"Nazva avto: ";
    cin>>c.name;
    cout<<"Rik vypusku: ";
    cin>>c.year;
    cout<<"Probig: ";
    cin>>c.mileage;
    cars.push_back(c);
}

void vstvpislea(vector<Car>& cars) 
{
    string t;
    cout<<"Pisleaz yakogo avto vstavyty: ";
    cin>>t;

    int index=-1;
    for(int i=0;i<cars.size();i++) 
	{
        if(cars[i].name==t) 
		{
            index=i;
            break;
        }
    }

    if (index!=-1) 
	{
        Car newCar;
        cout<<"Nazva novoho avto: ";
        cin>>newCar.name;
        cout<<"Rik vypusku: ";
        cin>>newCar.year;
        cout<<"Probig (км): ";
        cin>>newCar.mileage;
        cars.insert(cars.begin()+index+1,newCar);
    } 
	else 
	{
        cout<<"Avtomobili z nazvoiu "<<t<<" ne znaideno.\n";
    }
}

void vstvpered(vector<Car>& cars) 
{
    string t;
    cout<<"Pered yakym avto stavyty: ";
    cin>>t;

    int index=-1;
    for (int i=0;i<cars.size();i++) 
	{
        if(cars[i].name==t) 
		{
            index=i;
            break;
        }
    }

    if(index!=-1) 
	{
        Car newCar;
        cout<<"Nazva novoho avto: ";
        cin>>newCar.name;
        cout<<"Rik vypusku: ";
        cin>>newCar.year;
        cout<<"Probig (км): ";
        cin>>newCar.mileage;
        cars.insert(cars.begin()+index+1,newCar);
    } 
	else 
	{
        cout<<"Avtomobili z nazvoiu "<<t<<" ne znaideno.\n";
    }
}

void search(vector<Car>& cars) 
{
    string name;
    cout<<"Vediti nazvu avto dlia poshuku: ";
    cin>>name;

    bool found=false;
    for (int i=0;i<cars.size();i++) 
	{
        if (cars[i].name==name) 
		{
            cout<<"Avtomobili e v spysku:\n";
            print(cars[i]);
            found=true;
            break;
        }
    }

    if (!found) 
	{
        cout<<"Avtomobilea nemae y spysku.\n";
    }
}

void del(vector<Car>& cars) 
{
    int r;
    cout<<"Vediti rik: ";
    cin>>r;

    int k=0;
    for(int i=0;i<cars.size(); ) 
	{
        if(cars[i].year<r) 
		{
            cars.erase(cars.begin() + i);
            k++;
        } 
		else 
		{
            i++;
        }
    }
    cout<<"Vydaleno "<<k<<" avto.\n";
}

void printl(vector<Car>& cars) 
{
    if(cars.empty()) 
	{
        cout<<"Spysok porojniy.\n";
    } 
	else 
	{
        cout<<"Spysok avtomobiliv:\n";
        for(int i=0;i<cars.size();i++) 
		{
            print(cars[i]);
        }
    }
}

int main() 
{
    vector<Car> cars;
    int choice;
    do 
	{
        cout<<"\n------ Meniu dlya rovboty ------\n";
        cout<<"1. VVid pershogo elementa u spysok\n";
        cout<<"2. Vstavka y pochatok spysku\n";
        cout<<"3. Vstavka y kineti spysku\n";
        cout<<"4. Vstavka elementa pislea zadanogo elementa\n";
        cout<<"5. Vstavka elementa pered zadanogo elementa\n";
        cout<<"6. poshuk potribnogo vuzla\n";
        cout<<"7. Vydalenya vuzla\n";
        cout<<"8. Perehlyad spysku\n";
        cout<<"9. exit\n";
        cout<<"----------------------------------------\n";
        cout<<"Vediti nomer operatii: ";
        cin>>choice;

        switch (choice) 
		{
            case 1: insertfirst(cars); 
			break;
            case 2: insert_start(cars); 
			break;
            case 3: insert_end(cars); 
			break;
            case 4: vstvpislea(cars); 
			break;
            case 5: vstvpered(cars); 
			break;
            case 6: search(cars); 
			break;
            case 7: del(cars); 
			break;
            case 8: printl(cars); 
			break;
            case 9:
			break;
            default:cout<<"Nevirno\n";
        }
    } while(choice!=9);

    return 0;
}
