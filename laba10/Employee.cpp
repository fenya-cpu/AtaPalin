#include "Employee.h"
#include <iostream>

Employee::Employee() : surname(""), department(""), yearOfHiring(0), salary(0), bonus(0) {}

Employee::Employee(std::string sur, std::string dep, int year, double sal)
    : surname(sur), department(dep), yearOfHiring(year), salary(sal), bonus(0) {}

const int currentYear = 2025;

std::string Employee::getSurname() const { return surname; }
std::string Employee::getDepartment() const { return department; }
int Employee::getYearOfHiring() const { return yearOfHiring; }
double Employee::getSalary() const { return salary; }
double Employee::getBonus() const { return bonus; }

void Employee::calculateBonus(int currentYear)
{
    int experience = getExperience(currentYear);
    if (experience <= 10) 
	bonus = salary * 0.1;
    else if (experience <= 25) 
	bonus = salary * 0.25;
    else 
	bonus = salary * 0.4;
}

int Employee::getExperience(int currentYear) const 
{
    return 2025 - yearOfHiring;
}

void Employee::display() const 
{
    std::cout << "Prizvyshe: " << surname << ", Viddil: " << department << ", Rik pryiomu: " << yearOfHiring << ", Zarplata: " << salary << ", Premia: " << bonus << std::endl;
}

void departmentStats(Employee employees[], int n) {
    std::string departments[10];
    int k=0;

    for (int i=0;i<n;++i) 
	{
        std::string currentdept=employees[i].getDepartment();
        bool dep=false;

        for (int j=0;j<k;++j) 
		{
            if (departments[j]==currentdept) 
			{
                dep=true;
                break;
            }
        }

        if (!dep) 
		{
            int kp = 0;
            double totalSalary=0;

            for (int m=0;m<n;++m) 
			{
                if (employees[m].getDepartment()==currentdept) 
				{
                    kp++;
                    totalSalary+=employees[m].getSalary()+employees[m].getBonus();
                }
            }

            departments[k++]=currentdept;

            std::cout << " Viddil: " << currentdept << ", K-st pracivnykiv: " << kp << ", Zagalna zarplata: " << totalSalary << " grn\n";
        }
    }
}

Vacation::Vacation(Employee emp, int currentYear)
    : employee(emp), startDate("01.07.2021")
{
    int exp = emp.getExperience(currentYear);
    double totalSalary = emp.getSalary() + emp.getBonus();

    if (exp < 10 && totalSalary < 12000)
        duration = 14;
    else if (exp > 25 && totalSalary > 25000)
        duration = 28;
    else
        duration = 21;

    endDate = calculateEndDate(startDate, duration);
}

std::string Vacation::calculateEndDate(const std::string& start, int days) {
    return  "01.07.2021+ " + std::to_string(days) + " dniv";
}

void Vacation::display() const {
    std::cout << "Vidpustka dlia: " << employee.getSurname()
              << ", Start: " << startDate
              << ", Trivalist: " << duration << " dniv"
              << ", Kinets: " << endDate << std::endl;
}
