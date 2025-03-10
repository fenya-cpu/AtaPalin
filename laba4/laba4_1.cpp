#include <iostream>
using namespace std;

int main()
{
	int i,n,m,ka=0,kb=0;
	cout<<"Vediiti n: ";
	cin>>n;
	cout<<"Vediti m: ";
	cin>>m;
	float *a = new float[n];
	float *b = new float[m];
	cout<<"Vediti masiv a: ";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<"Vediti masiv b: ";
	for(i=0;i<m;i++)
	{
		cin>>b[i];
	}
	for(i=0;i<n;i++)
	{
		if(int(a[i])%3==0)
		{
			ka++;
		}
	}
	for(i=0;i<m;i++)
	{
		if(int(b[i])%3==0)
		{
			kb++;
		}
	}
	if(ka<kb)
	{
		for(i=0;i<n;i++)
		{
			cout<<a[i]<<" ";
		}
	}
	if(ka==kb)
	{
		cout<<"Error! ";
	}
	if(ka>kb)
	{
		for(i=0;i<m;i++)
		{
			cout<<b[i]<<" ";
		}
	}
	
	cout<<endl;
	delete []a;
	delete []b;
	
return 0;
}
