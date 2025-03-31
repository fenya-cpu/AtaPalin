#include <iostream>
#include <cmath>
#include <time.h>
#include <stdlib.h>
using namespace std;

// functia dlia masivu b[j]
void crarray(float* a, int n, float*& b, int& m) 
{
    m=0;
    for(int i=1;i<n;i+=2) 
	{
        if(static_cast<int>(a[i])%2==0) 
		{
            m++;
        }
    }

    b = new float[m];
    int in=0;

    for(int i=1;i<n;i+=2) 
	{
        if(static_cast<int>(a[i])%2==0) 
		{
            b[in++]=a[i];
        }
    }
}

int main() 
{
    int n;
    cout<<"Vediti rozmirnisti: ";
    cin>>n;

    float* a = new float[n];

    for (int i=0;i<n;i++) 
	{
        a[i]=(rand()%20-10)*1.0;
        cout<<a[i]<<" ";
    }
    cout<<endl;

    float* b=new float[n];
    int m=0;

    //vyklyk fcuntii cerez vkazivnyk
    void (*p)(float*,int,float*&,int&)=crarray;
    p(a,n,b,m);

    cout<<"masiv b:\n";
    for(int i=0;i<m;i++) 
	{
        cout<<b[i]<<" ";
    }
    cout<<endl;

    delete[] a;
    delete[] b;

    return 0;
}

