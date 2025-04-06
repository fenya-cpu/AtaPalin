#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee 
{
private:
    std::string surname;
    std::string department;
    int yearOfHiring;
    double salary;
    double bonus;

public:
    Employee();
    Employee(std::string sur, std::string dep, int year, double sal);

    std::string getSurname() const;
    std::string getDepartment() const;
    int getYearOfHiring() const;
    double getSalary() const;
    double getBonus() const;

    void setSurname(const std::string& sur);
    void setDepartment(const std::string& dep);
    void setYearOfHiring(int year);
    void setSalary(double sal);

    void calculateBonus(int currentYear);
    int getExperience(int currentYear) const;

    void display() const;
};

#endif
