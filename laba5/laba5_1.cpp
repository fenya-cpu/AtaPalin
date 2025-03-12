#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;



int main()
{
	ofstream file("output.txt");
	if (!file) 
	{
		cout << "Error opening file!";
		return 1;
	}
	int n,m,i,j,h=1;
	float ser,s,k;
	cout<<"Kilkisti riadkiv: ";
	cin>>n;
	cout<<"Kilkisti stovptiv: ";
	cin>>m;
	
	int **a;
	a = new int*[n];
	
	for(i=0;i<n;i++)
	{
		a[i]=new int[m];
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			cin>>a[i][j];
		}
	}
	
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			s=s+a[i][j];
			k++;
		}
	}
	ser=s/k;
	
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(a[i][j]<ser)
			{
				h++;
			}
		}
	}
	int *b = new int[h];
	int *v = new int[n];
	
	cout<<"Seredniy: "<<ser<<endl;
	h=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(a[i][j]<ser)
			{
				b[h]=a[i][j];
				h++;
			}
		}
	}
	cout<<"masiv b: ";
	for(i=0;i<h;i++)
	{
		cout<<b[i]<<" ";
	}
	
	for(i=0;i<h;i++)
	{
		file<<b[i]<<" ";
	}
	
	h=0;
	k=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(a[i][j]<ser)
			{
				k++;
			}
		}
		v[h]=k;
		h++;
		k=0;
	}
	cout<<endl<<"Masiv z kilikosti u ryadkah: ";
	for(i=0;i<n;i++)
	{
		cout<<v[i]<<" ";
	}
	file<<endl;
	for(i=0;i<n;i++)
	{
		file<<v[i]<<" ";
	}
	file.close();
	
	
	
	delete []v;
	delete []b;
	for(i=0;i<n;i++)
		delete []a[i];
	
return 0;
}
