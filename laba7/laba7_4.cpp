#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;


void generateArray(int a[],int n) 
{
    srand(time(0));
    cout<<"masiv a: ";
    for (int i=0;i<n;++i) 
	{
        a[i]=1+rand()%50;
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void createSubarray(int a[], int b[], int& size_b, int i1, int i2,int n) 
{
    if (i1>i2)
	swap(i1,i2);
    if (i1<0||i2>=n) 
	{
        cout << "error!"<<endl;
        size_b=0;
        return;
    }

    size_b=i2-i1+1;
    for (int i=0;i<size_b;++i) 
	{
        b[i]=a[i1+i];
    }
}

void printArray(const int arr[], int size) 
{
    for (int i=0;i<size;++i) 
	{
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
	cout<<"Vediti n: ";
	int n;
	cin>>n;
    int a[n];
    generateArray(a,n);

    int i1, i2;
    cout<<"Vediti indexy i1 ta i2: ";
    cin>>i1>>i2;

    int b[n],size_b;
    createSubarray(a, b, size_b, i1, i2, n);
    
    cout<<"masiv b: ";
    printArray(b, size_b);


    return 0;
}

