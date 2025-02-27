#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	float a[10],*p,*p2,*p3;
	int i,n;
	cout<<"Vediti rozmirnisti: ";
	cin>>n;
	cout<<"Vediti masiv:";
	p=a;
	for(i=0;i<n;i++)
	{
		cin>>p[i];
	}
	cout<<endl;

	p=&a[0];
	for(i=0;i<n-2;i++)
	{
		p2=&a[i+1];
		p3=&a[i+2];
		if(*p>*p2 and *p2>*p3)
		{
			cout<<endl;
			cout<<*p<<" "<<*p2<<" "<<*p3;
		}
		p++;
	}
return 0;
}
