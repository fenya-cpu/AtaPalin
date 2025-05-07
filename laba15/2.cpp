#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

template <typename T>
class MyVector {
private:
    T arr[10];

public:
    MyVector() 
	{
        for (int i=0;i<10;++i)
            arr[i]=T(); // 0 для int, 0.0 для float тощо
    }

    MyVector(const T& value) 
	{
        for(int i=0;i<10;++i)
            arr[i]=value;
    }

    void inputFromKeyboard() 
	{
        cout<<"Vediti 10 elementiv: ";
        for (int i=0;i<10;++i)
            cin>>arr[i];
    }
    void fillRandom(T minVal, T maxVal) 
	{
        for (int i=0;i<10;++i)
            arr[i]=rand()%(maxVal-minVal+1)+minVal;
    }

    void print() const 
	{
        for (int i=0;i<10;++i)
            cout<<arr[i]<<" ";
        cout<<endl;
    }

    // Метод для переміщення елементів: парні в першу половину, непарні — в другу
    void rearrange() 
	{
        T temp[10];
        int idx1=0, idx2=5;

        for (int i=0;i<10;++i) 
		{
            if (i%2==0&&idx1<5)
                temp[idx1++]=arr[i];
            else if (i%2!=0&&idx2<10)
                temp[idx2++]=arr[i];
        }

        for (int i=0;i<10;++i)
            arr[i]=temp[i];
    }

    void removeElement(T value) 
	{
        for (int i=0;i<10;++i)
            if (arr[i]==value)
                arr[i]=T();
   }

    // Перевантаження операції +
    MyVector operator+(const MyVector& other) const 
	{
        MyVector result;
        for (int i=0;i<10;++i)
            result.arr[i]=this->arr[i]+other.arr[i];
        return result;
    }

    // Перевантаження операції префікс ++ (збільшити кожен елемент на 10)
    MyVector& operator++() 
	{
        for (int i=0;i<10;++i)
            arr[i]+=10;
        return *this;
    }

    // Порівняння за сумою елементів
    bool operator>(const MyVector& other) const 
	{
        return sum() > other.sum();
    }

    bool operator<(const MyVector& other) const 
	{
        return sum() < other.sum();
    }

    bool operator<=(const MyVector& other) const 
	{
        return sum() <= other.sum();
    }

private:
    T sum() const 
	{
        T s = T();
        for (int i=0;i<10;++i)
            s+=arr[i];
        return s;
    }
};

int main() {
    srand(time(0));

    MyVector<int> a;
    a.fillRandom(1, 20);
    cout << "Vector A: ";
    a.print();

    MyVector<int> b(5);
    cout << "Vector  B usi 5: ";
    b.print();

    MyVector<int> c = a + b;
    cout << "A+B: ";
    c.print();

    ++c;
    cout << "++(A+B): ";
    c.print();

    cout<<"Pislea rearrange(): ";
    c.rearrange();
    c.print();

    cout << "Pislea vydalenia 15: ";
    c.removeElement(15);
    c.print();

    cout << "C > A: " << (c > a) << endl;

    return 0;
}
