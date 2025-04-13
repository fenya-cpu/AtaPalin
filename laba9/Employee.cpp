#include "Employee.h"
#include <iostream>

Employee::Employee() : surname(""), department(""), yearOfHiring(0), salary(0), bonus(0) {}

Employee::Employee(std::string sur, std::string dep, int year, double sal)
    : surname(sur), department(dep), yearOfHiring(year), salary(sal), bonus(0) {}


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
    return currentYear - yearOfHiring;
}

void Employee::display() const 
{
    std::cout << "Prizvyshe: " << surname << ", Viddil: " << department << ", Rik pryiomu: " << yearOfHiring << ", Zarplata: " << salary << ", Premia: " << bonus << std::endl;
}
