#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	float a[10],*p,*p2;
	int i,n,k;
	cout<<"Vediti rozmirnisti: ";
	cin>>n;
	cout<<"Vediti masiv:";
	p=a;
	for(i=0;i<n;i++)
	{
		cin>>*p;
		p++;
	}
	p=&a[0];
	for(i=0;i<n;i++)
	{
		p2=&a[i+1];
		if(*p<*p2)
		{
			cout<<*p2<<" ";
			k++;
		}
		p++;
	}
	cout<<endl;
	
	cout<<"Kilkisti: "<<k;
return 0;
}
	
