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
    friend void departmentStats(Employee employees[], int n);
};


class Vacation {
private:
    Employee employee;
    std::string startDate;
    int duration;
    std::string endDate;

    std::string calculateEndDate(const std::string& start, int durationDays);

public:
    Vacation(Employee emp, int currentYear);
    void display() const;
};