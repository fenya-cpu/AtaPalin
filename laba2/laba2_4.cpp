#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	float a[100];
	int n;
	float* p;

	p=&a[0];

	cout<<"n:"<<endl;
	cin>>n;
	cout<<"Vediti masiv: ";
	for(int i = 0; i < n; i++) 
	{
		cin >> *p;
		p++;
	}

	p=&a[0];

	int k=0;

	for (int i = 0; i < n; i++) 
	{
		if (*p < 0) {
			cout<<"*p="<<*p<<"&p: "<<&p<<endl;
			k++;
		} 
		p++;
	}

	cout<<endl;

	cout<<"kilkisti menshe za 0: " <<k;

	return 0;
}
