#include "Employee.h"
#include <iostream>

using namespace std;

int main() 
{
    int n;
    std::cin>>n;
    Employee employees[n];

    for (int i = 1; i < n; ++i) 
	{
        string sur, dep;
        int year;
        double sal;

        cout << "Vediti dany pro prativnyka " << i + 1 << ":\n";
        cout << "prizvyshe: ";
        cin >> sur;
        cout << "viddil: ";
        cin >> dep;
        cout << "rik pryomu: ";
        cin >> year;
        cout << "zarplata: ";
        cin >> sal;

        employees[i] = Employee(sur, dep, year, sal);
        employees[i].calculateBonus(2025);
    }

    std::cout << "\ninformatia pro vsih:\n";
    for (int i = 0; i < n; ++i) 
	{
        employees[i].display();
    }

    // poshuk seredniogo staju
    int totalExp=0;
    for (int i=1;i<n;++i) 
	{
        totalExp+=employees[i].getExperience(2025);
    }
    cout<<"\nseredniy staj: "<<(totalExp/n) <<" rokiv\n";

    //sortuvania za stajem
    for (int i=0;i<n-1;++i) 
	{
        for (int j=i+1;j<n;++j) 
		{
            if (employees[i].getExperience(2025) < employees[j].getExperience(2025)) 
			{
                swap(employees[i], employees[j]);
            }
        }
    }

    cout << "\npislea sortuvania za stajem:\n";
    for (int i=0;i<n;++i) 
	{
        employees[i].display();
    }
    cout<<endl;
    departmentStats(employees,n);
    
    cout << "\nVidpustky:\n";
    for (int i=0;i<n;++i) 
	{
        Vacation vac(employees[i], 2025);
        vac.display();
    }
    
    cout<<endl;
    

    return 0;
}

