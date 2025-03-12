#include <iostream>
#include <cmath>

bool perevirka(int* x,int y)
{
	int i;
	for(i=0;i<y;i++)
	{
		if(x[i]<x[i+1])
		{
			return false;
		}
	}
	return true;
}
using namespace std;
int main()
{
	int i,n,j,k=0;
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
			cin>>a[i][j];
		}
	}
	
	for(j=0;j<n;j++)
	{
		int *b = new int[n];
		for(i=0;i<n;i++)
		{
			b[i]=a[i][j];
		}
		if(perevirka(b,n))
		{
			k++;
		}
		delete []b;
	}
	cout<<"Kilikisit vidsorotovanyh stovptyv: "<<k;
	
	for(i=0;i<n;i++)
		delete []a[i];
return 0;
}
