#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	int a[100][100],n,i,j,max,min;
	int **dp;
	cout<<"Vediti n:";
	cin>>n;
	int *p[n];
	dp=&p[0];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
	}
	for(i=0;i<n;i++) 
	{
		p[i] = a[i];
	}

	max=a[0][0];
	min=a[0][n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<*(*(dp+i)+j)<<" ";
		}
		cout<<endl;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i=j)
			{
				if(*(*(dp+i)+j)>max)
				max=*(*(dp+i)+j);
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i+j==n-1)
			{
				if(*(*(dp+i)+j)<min);
				min=*(*(dp+i)+j);
			}
		}
	}
	cout<<"max:"<<max;
	cout<<endl;
	cout<<"min:"<<min;
	cout<<endl;
	cout<<"Riznytsea:"<<max-min;
	
	
return 0;
}
