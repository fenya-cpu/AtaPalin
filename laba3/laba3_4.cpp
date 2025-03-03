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
		for(j=0;j<n;j++)
		{
			if(*(*(dp+i)+j)>0)
			{
				sum=sum+*(*(dp+i)+j);
				k++;
			}
		}
	}
	cout<<endl<<"Seredne dodatne: "<<sum/k<<endl;
	sum=0;
	k=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(*(*(dp+i)+j)<0)
			{
				sum=sum+*(*(dp+i)+j);
				k++;
			}
		}
	}
	cout<<endl<<"Seredne vid'emne: "<<sum/k<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(*(*(dp+i)+j)==0)
			{
				k0++;
			}
		}
	}
	cout<<endl<<"kilkisti 0: "<<k0<<endl;
	return 0;	
}
