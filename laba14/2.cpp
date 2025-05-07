#include <iostream>
#include <string>
using namespace std;

class Dvyhun {
protected:
    int potuzhnist;
    string zavodNomer;

public:
    Dvyhun() 
	{
        potuzhnist=0;
        zavodNomer="7777";
    }

    Dvyhun(int p, string zn) : potuzhnist(p), zavodNomer(zn) {}

    virtual ~Dvyhun() 
	{
    }

    virtual void vvedennia() {
        cout << "Введіть потужність двигуна: ";
        cin >> potuzhnist;
        cout << "Введіть заводський номер: ";
        cin >> zavodNomer;
    }

    virtual void vyvedennia() const {
        cout << "Потужність: " << potuzhnist << " к.с.\n";
        cout << "Заводський номер: " << zavodNomer << endl;
    }
};

class Avtomobil : public Dvyhun {
protected:
    string marka;
    double tsina;

public:
    Avtomobil() : Dvyhun() 
	{
        marka = "Невідома";
        tsina = 0;
        cout << "Конструктор Avtomobil (за замовчуванням)\n";
    }

    Avtomobil(int p, string zn, string m, double t)
        : Dvyhun(p, zn), marka(m), tsina(t) {
        cout << "Конструктор Avtomobil (з параметрами)\n";
    }

    ~Avtomobil() override {
        cout << "Деструктор Avtomobil\n";
    }

    void vvedennia() override {
        Dvyhun::vvedennia();
        cout << "Введіть марку автомобіля: ";
        cin >> marka;
        cout << "Введіть ціну: ";
        cin >> tsina;
    }

    void vyvedennia() const override {
        Dvyhun::vyvedennia();
        cout << "Марка: " << marka << endl;
        cout << "Ціна: " << tsina << " грн\n";
    }
};

// ======== ПОХІДНИЙ КЛАС: Вантажівка =========
// Знову public-наслідування для доступності всіх методів
class Vantazhivka : public Avtomobil {
private:
    double vantazhopidyomnist;

public:
    Vantazhivka() : Avtomobil() {
        vantazhopidyomnist = 0;
        cout << "Конструктор Vantazhivka (за замовчуванням)\n";
    }

    Vantazhivka(int p, string zn, string m, double t, double vp)
        : Avtomobil(p, zn, m, t), vantazhopidyomnist(vp) {
        cout << "Конструктор Vantazhivka (з параметрами)\n";
    }

    ~Vantazhivka() override {
        cout << "Деструктор Vantazhivka\n";
    }

    void vvedennia() override {
        Avtomobil::vvedennia();
        cout << "Введіть вантажопідйомність (т): ";
        cin >> vantazhopidyomnist;
    }

    void vyvedennia() const override {
        Avtomobil::vyvedennia();
        cout << "Вантажопідйомність: " << vantazhopidyomnist << " т\n";
    }
};

int main() {
    cout << "\n--- Введення та виведення масиву вантажівок ---\n";

    Vantazhivka trucks[3];

    for (int i = 0; i < 3; ++i) {
        cout << "\nВведення даних для вантажівки #" << (i + 1) << ":\n";
        trucks[i].vvedennia();
    }

    cout << "\n--- Виведення даних ---\n";
    for (int i = 0; i < 3; ++i) {
        cout << "\nВантажівка #" << (i + 1) << ":\n";
        trucks[i].vyvedennia();
    }

    return 0;
}
