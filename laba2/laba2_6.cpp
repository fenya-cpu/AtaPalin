#include <iostream>
#include <conio.h>

using namespace std;
int main()
{
	float a[10],*p,*p1,t;
	int i,n,k,j;
	cout<<"Vediti rozmirnisti: ";
	cin>>n;
	cout<<"Vediti masiv:";
	p=a;
	for(i=0;i<n;i++)
	{
		cin>>*p;
		p++;
	}
	for(i=0;i<n;i=i+2)
	{
		p=&a[i];
		for(j=i+2;j<n;j=j+2)
		{
			p1=&a[j];
			if(*p>*p1)
			{
				t=*p;
				*p=*p1;
				*p1=t;
			}
		}
	}
	for(i=1;i<n;i=i+2)
	{
		p=&a[i];
		for(j=i+2;j<n;j=j+2)
		{
			p1=&a[j];
			if(*p<*p1)
			{
				t=*p;
				*p=*p1;
				*p1=t;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
}
