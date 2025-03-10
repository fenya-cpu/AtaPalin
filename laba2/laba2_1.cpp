#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	float a[10],*p,min;
	int i,n;
	cout<<"Vediti rozmirnisti: ";
	cin>>n;
	cout<<"Vediti masiv:";
	p=a;
	for(i=0;i<n;i++)
	{
		cin>>p[i];
		p++;
	}
	p=a;
	min=a[0];
	for(i=0;i<n;i++)
	{
		if(i%2==0)
		{
			if(p[i]<min)
			{
				min=p[i];
			}
		}
	}
	cout<<"Mininmaliniy: "<<min;
return 0;
	
}
