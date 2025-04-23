#include <iostream>
#include <cmath>
#include <ctime>
#include <stdlib.h>
using namespace std;

bool per(int x) 
{
    int d=x/10;
    int o=x%10;
    return d==o;
}

int main() 
{
    srand(time(NULL));
    int n,i,j;
    cout<<"Vediti rozmirnisti n: ";
    cin>>n;
    

    int **a = new int*[n];
    for(i=0;i<n;i++) 
	{
        a[i]=new int[n];
    }
    

    for(i=0;i<n;i++) 
	{
        for(j=0;j<n;j++) 
		{
            a[i][j]=rand()%90+10;
        }
    }
    

    cout<<"Matryta:"<<endl;
    for(i=0;i<n;i++) 
	{
        for(j=0;j<n;j++) 
		{
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    

    int sum=0;
    for(j=0;j<n;j++) 
	{
        bool v=true;
        for(i=0;i<n;i++) 
		{
            if(per(a[i][j])) 
			{
                v=false;
                break;
            }
        }
        if(v) 
		{
            for(i=0;i<n;i++) 
			{
                sum=sum+a[i][j];
            }
        }
    }
    
    cout<<"SUma elementiv u tyh stovptiah: "<<sum<<endl;
    
    for(i=0;i<n;i++) 
	{
        delete[] a[i];
    }
    delete[] a;
    
    return 0;
}

