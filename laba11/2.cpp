#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAX_SIZE = 10;

class Matrix 
{
private:
    int size;
    int data[MAX_SIZE][MAX_SIZE];

public:
    Matrix(int n = 2) : size(n) 
	{
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                data[i][j] = 0;
    }

    void fillRandom(int minVal = 0, int maxVal = 10) 
	{
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                data[i][j] = minVal + rand() % (maxVal - minVal + 1);
    }

    void display() const 
	{
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j)
                cout << data[i][j] << "\t";
            cout << endl;
        }
    }

    friend Matrix operator+(const Matrix& a, const Matrix& b);
    friend Matrix operator-(const Matrix& a, const Matrix& b);
    friend Matrix operator*(const Matrix& a, const Matrix& b);
    friend bool operator==(const Matrix& a, const Matrix& b);
};

Matrix operator+(const Matrix& a, const Matrix& b) 
{
    Matrix result(a.size);
    for (int i = 0; i < a.size; ++i)
        for (int j = 0; j < a.size; ++j)
            result.data[i][j] = a.data[i][j] + b.data[i][j];
    return result;
}

Matrix operator-(const Matrix& a, const Matrix& b) 
{
    Matrix result(a.size);
    for (int i = 0; i < a.size; ++i)
        for (int j = 0; j < a.size; ++j)
            result.data[i][j] = a.data[i][j] - b.data[i][j];
    return result;
}

Matrix operator*(const Matrix& a, const Matrix& b) 
{
    Matrix result(a.size);
    for (int i = 0; i < a.size; ++i)
        for (int j = 0; j < a.size; ++j)
            for (int k = 0; k < a.size; ++k)
                result.data[i][j] += a.data[i][k] * b.data[k][j];
    return result;
}

bool operator==(const Matrix& a, const Matrix& b) 
{
    if (a.size != b.size) return false;
    for (int i = 0; i < a.size; ++i)
        for (int j = 0; j < a.size; ++j)
            if (a.data[i][j] != b.data[i][j])
                return false;
    return true;
}

int main() {
    srand(time(0));

    Matrix A(3), B(3);
    A.fillRandom(1, 5);
    B.fillRandom(1, 5);

    cout << "Matrytsa A:\n";
    A.display();

    cout << "\nMatrytsa B:\n";
    B.display();

    Matrix C = A + B;
    cout << "\nA + B:\n";
    C.display();

    Matrix D = A - B;
    cout << "\nA - B:\n";
    D.display();

    Matrix E = A * B;
    cout << "\nA * B:\n";
    E.display();

    cout << "\nA == B: " << (A == B ? "Tak" : "Ni") << endl;

    return 0;
}
