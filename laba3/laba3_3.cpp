#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	int a[100][100],b[100],n,k,i,j,max,min,*u;
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
		min=a[i][0];
		for(j=0;j<n;j++)
		{
			if(j==0)
			{
				b[k]=j+1;				
			}
			if(*(*(dp+i)+j)<min)
			{
				min=a[i][j];
				b[k]=j+1;
			}
		}
		k++;	
	}
	u=b;
	for(i=0;i<n;i++)
	{
		cout<<*u<<" ";
		u++;
	}
return 0;
}
