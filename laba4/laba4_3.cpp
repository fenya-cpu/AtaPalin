#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int i,n,m=0,k=0,j;
	float t;
	float *a = new float[n];
	cout<<"Vediti rozmirnisti: ";
	cin>>n;
	cout<<"Vediti masiv: ";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(i=0;i<n;i++)
	{
		if(int(a[i])%2==0)
		{
			m++;
		}
	}
	float *b = new float[m];
	for(i=0;i<n;i++)
	{
		if(int(a[i])%2==0)
		{
			b[k]=a[i];
			k++;
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=i+1;j<m;j++)
		{
			if(b[i]>b[j])
			{
				t=b[i];
				b[i]=b[j];
				b[j]=t;
			}
		}
	}
	for(i=0;i<m;i++)
	{
		cout<<b[i]<<" ";
	}
	delete []a;
	delete []b;
return 0;
}
