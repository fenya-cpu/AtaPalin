#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	int a[100][100],n,i,j,max,min;
	int **dp;
	float avgd,avgv,k0,k,sum;
	cout<<"Vediti n:";
	cin>>n;
	int *p[n];
	dp=&p[0];
	for(i=0;i<n;i++) 
	{
	
		p[i] = a[i];
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>*(*(dp+i)+j);
		}
	}
	for(i=0;i<n;i++)
	{
		if(i%2==0)
		{
		for(j=n-1;j>-1;j--)
		{
			cout<<*(*(dp+i)+j)<<" ";
		}
		cout<<endl;
		}
		if(i%2==1)
		{
			for(j=0;j<n;j++)
			{
				cout<<*(*(dp+i)+j)<<" ";
			}
			cout<<endl;
		}
	}
return 0;
}
