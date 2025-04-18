#include <iostream>
using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;

    void normalize() {
        minutes += seconds / 60;
        seconds %= 60;
        hours += minutes / 60;
        minutes %= 60;
        hours %= 24;
    }

public:
    Time() : hours(0), minutes(0), seconds(0) {}

    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
        normalize();
    }

    ~Time() {}

    void input() {
        cout << "Vediti godyny hvylyny ta secundy: ";
        cin >> hours >> minutes >> seconds;
        normalize();
    }

    void display() const {
        if (hours < 10) cout << "0";
        cout << hours << ":";

        if (minutes < 10) cout << "0";
        cout << minutes << ":";

        if (seconds < 10) cout << "0";
        cout << seconds << endl;
    }

    Time operator+(const Time& t) const 
	{
        return Time(hours + t.hours, minutes + t.minutes, seconds + t.seconds);
    }

    Time operator-(const Time& t) const 
	{
        int total1 = hours * 3600 + minutes * 60 + seconds;
        int total2 = t.hours * 3600 + t.minutes * 60 + t.seconds;
        int diff = abs(total1 - total2);
        return Time(diff / 3600, (diff % 3600) / 60, diff % 60);
    }

    // Оператори порівняння
    bool operator==(const Time& t) const {
        return hours == t.hours && minutes == t.minutes && seconds == t.seconds;
    }
    
    bool operator<(const Time& t) const {
        if (hours != t.hours) return hours < t.hours;
        if (minutes != t.minutes) return minutes < t.minutes;
        return seconds < t.seconds;
    }

    bool operator<=(const Time& t) const {
        return *this < t || *this == t;
    }

    bool operator>(const Time& t) const {
        return !(*this <= t);
    }

};

int main() {
    Time t1, t2;
    cout << "Pershyi chas:\n";
    t1.input();

    cout << "Drugyi chas:\n";
    t2.input();

    Time sum = t1 + t2;
    Time diff = t1 - t2;

    cout << "Suma: ";
    sum.display();

    cout << "Riznytea: ";
    diff.display();

    cout << "Chas 1 == chas 2: " << (t1 == t2 ? "Tak" : "Ni") << endl;
    cout << "Chas 1 <  Chas 2: " << (t1 <  t2 ? "Tak" : "Ni") << endl;
    cout << "Chas 1 >  Chas 2: " << (t1 >  t2 ? "Tak" : "Ni") << endl;

    return 0;
}
