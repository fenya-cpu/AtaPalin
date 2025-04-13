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


    void calculateBonus(int currentYear);
    int getExperience(int currentYear) const;

    void display() const;
};
