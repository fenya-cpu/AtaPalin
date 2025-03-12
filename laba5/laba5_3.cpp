#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <fstream>

void sort(int* x, int y) 
{
	int t;
    for(int i=0;i<y-1;i++) 
	{
        for(int j=0;j<y-i-1;j++) 
		{
            if(x[j]<x[j+1]) 
			{
                t=x[j];
                x[j]=x[j+1];
                x[j+1]=t;
            }
        }
    }
}

using namespace std;
int main()
{
	ofstream file("output2.txt");
	if (!file) 
	{
		cout << "Error opening file!";
		return 1;
	}
	srand(time(NULL));
	int i,n,j,k;
	cout<<"Vediti rozmirnisti: ";
	cin>>n;
	
	int **a;
	a = new int*[n];
	
	for(i=0;i<n;i++)
	{
		a[i]=new int[n];
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			a[i][j]=rand()%899+100;
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	for (int i=0;i<n;i++)
	{
        sort(a[i],n);
    }
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			file<<a[i][j]<<" ";
		}
		file<<endl;
	}
	file.close();
	
	for(i=0;i<n;i++)
		delete []a[i];
		
return 0;
}
	
