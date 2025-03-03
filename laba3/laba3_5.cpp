#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	int a[100][100],b[100],n,k=0,i,j,max,min,*u,t;
	int **dp;
	float avgd,avgv,k0,sum;
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
			if(i==j)
			{
				b[k]=*(*(dp+i)+j);
			}
		}
		k++;
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(b[i]>b[j])
			{
				t=b[i];
				b[i]=b[j];
				b[j]=t;
			}
		}
	}
	k=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j)
			{
				*(*(dp+i)+j)=b[k];
			}
		}
		k++;
	}
	
	cout<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<*(*(dp+i)+j)<<" ";
		}
		cout<<endl;
	}
return 0;
}

