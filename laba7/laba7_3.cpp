#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void generateUniqueArray(int a[], int size, int minVal, int maxVal) 
{
    int k=0;
    while (k<size) 
	{
        int num=minVal+rand()%(maxVal-minVal+1);
        a[k++]=num;
    }
}

void generateRandomSubarray(int a[], int a_size, int b[], int b_size) 
{
    bool used[12] = {false}; //vidmichaie vykorystani indexy
    int k=0;
    
    while(k<b_size) 
	{
        int i=rand()%a_size;
        if (!used[i]) 
		{
            b[k++]=a[i];
            used[i]=true;
        }
    }
}

void printArray(const int arr[], int size) 
{
    for(int i=0;i<size;++i) 
	{
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() 
{
    srand(time(0));
    int a[12];
    generateUniqueArray(a, 12, 1, 50);

    int n;
    cout<<"Rozmirnisti masyvu b: ";
    cin>>n;

    int b[n];
    generateRandomSubarray(a, 12, b, n);

    cout<<"masiv a: ";
    printArray(a, 12);
    cout<<"masiv b: ";
    printArray(b, n);

    return 0;
}

