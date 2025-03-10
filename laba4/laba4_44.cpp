#include <iostream>
#include <cmath>
#include <time.h>
#include <stdlib.h>
using namespace std;

void findMinMax(float* x, int y, float& min, float& max) 
{
    min=max=x[0];
    for (int i=1;i<y;i++) 
	{
        if (x[i]>max) max=x[i];
        if (x[i]<min) min=x[i];
    }
}

int main() {
    srand(time(NULL));
    int n;
    cout << "Vediti rozmirnisti n: ";
    cin >> n;

    float* a = new float[n];
    for (int i = 0; i < n; i++) 
	{
        a[i] = (rand() % 60 - 20)*1.0/10;
    }

    cout << "pochatkovyi masiv:\n";
    for (int i = 0; i < n; i++) 
	{
        cout << a[i] << " ";
    }
    cout << endl;

    int ns = n;
    for (int i = 0; i < n; i++) 
	{
        if (a[i] < 0) ns++;
    }

    float* na = new float[ns];
    int ni = 0;

    for (int i = 0; i < n; i++) 
	{
        if (a[i] < 0) 
		{
            float min, max;
            findMinMax(a, i, min, max);
            na[ni++] = min + max;
        }
        na[ni++] = a[i];
    }

    cout << "novyi masiv:\n";
    for (int i = 0; i < ns; i++) 
	{
        cout << na[i] << " ";
    }
    cout << endl;

    delete[] a;
    delete[] na;
    return 0;
}

