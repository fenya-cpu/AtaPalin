#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void inputArray(int* x, int n)
{
    int c;
    cout<<"1(vruchnu) chy 2(randomno): ";
    cin>>c;

    if(c==1) 
	{
        for(int i=0;i<n;i++) 
		{
            cout<<"x["<<i<<"] = ";
            cin>>*(x+i);
        }
    }
	else
	
	{
        int minVal, maxVal;
        cout<<"Vediti nyjnyu ta verhnyu: ";
        cin>>minVal >> maxVal;
        srand(time(0));
        for(int i=0;i<n;i++) 
		{
            *(x+i)=rand()%(maxVal-minVal+1)+minVal;
        }
    }
}

void printarray(int* x,int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<x[i]<<endl;
	}
	cout<<endl;
}

void printArray(int* x, int n) 
{
    for(int i=0;i<n;i++) 
	{
        cout<<x[i]<<" ";
    }
    cout<<endl;
}

void removeDuplicatesMinMax(int* x, int& n) 
{
    int minVal=*x, maxVal=*x;
    
    for(int i=1;i<n;i++) 
	{
        if(*(x+i)<minVal)
		minVal=*(x+i);
        if(*(x+i)>maxVal)
		maxVal=*(x+i);
    }

    int mink=0,maxk=0;
    for(int i=0;i<n;i++) 
	{
        if(*(x+i)==minVal)
		mink++;
        if(*(x+i)==maxVal)
		maxk++;
    }

    int ind=0;
    for(int i=0;i<n;i++) 
	{
        if ((*(x+i)==minVal && mink>1)||(*(x+i)==maxVal && maxk>1)) 
		{
            mink-=(*(x+i)==minVal);
            maxk-=(*(x+i)==maxVal);
        } 
		else 
		{
            *(x+ind)=*(x+i);
            ind++;
        }
    }
    n=ind;
}

void findMinMax(int* x, int n, int& minIndex, int& maxIndex) 
{
    minIndex=0;
    maxIndex=0;
    for (int i=1;i<n;i++) 
	{
        if (x[i]<x[minIndex])
		minIndex=i;
        if (x[i]>x[maxIndex])
		maxIndex=i;
    }
}

void sdvig(int* x, int n) 
{
    int minIndex=0;
    for(int i=1;i<n;i++) 
	{
        if(*(x+i)<*(x+minIndex)) 
		{
            minIndex=i;
        }
    }

    int minVal=*(x+minIndex);


    for(int i=minIndex;i>0;i--) 
	{
        *(x+i)=*(x+i-1);
    }
    *x=minVal;
}


void removeElements(int* x, int& n) 
{
	int minIndex, maxIndex;
    findMinMax(x,n,minIndex,maxIndex);
    if(minIndex>maxIndex) 
	swap(minIndex,maxIndex);

    int newSize=maxIndex-minIndex+1;
    for (int i=0;i<newSize;i++) 
	{
        x[i]=x[minIndex+i];
    }
    n=newSize;
}

int* parnep(int* x, int n, int& newSize) 
{
    int parnk=0,neparnk=0;

    for (int i=0;i<n;i++) 
	{
        if(*(x+i)%2==0)
		parnk++;
        else 
		neparnk++;
    }

    if(parnk>neparnk)
    {
    	newSize=parnk;
	}
	else
	{
		newSize=neparnk;
	}
    int* newArr=new int[newSize];
    int k=0;
    
    if(parnk>neparnk)
    {
    	for(int i=0;i<n;i++)
    	{
    		if(*(x+i)%2==0)
    		{
    			newArr[k]=*(x+i);
    			k++;
			}
		}
	}
	else
	{
		for(int i=0;i<n;i++)
    	{
    		if(*(x+i)%2==1)
    		{
    			newArr[k]=*(x+i);
    			k++;
			}
		}
	}
    return newArr;
}

int main() 
{
    int n;
    cout<<"Vediti rozmirnisti: ";
    cin>>n;

    int* arr = new int[n];

    inputArray(arr, n);

	int c;
    cout<<"vyberiti 1 dlya vyvodu u riadok,2 dlia vyvodu u stovp: ";
    cin>>c;
    if(c==1)
    {
    	printArray(arr, n);
	}
	if(c==2)
	{
		printarray(arr, n);
	}

    removeDuplicatesMinMax(arr, n);
    cout<<"pislea vydalenya duplikativ min/max: ";
    printArray(arr, n);

    sdvig(arr, n);
    cout<<"pislea sdviga: ";
    printArray(arr, n);

    removeElements(arr, n);
    cout<<"Pislea vydalenya poza min max: ";
    printArray(arr, n);

    int newSize;
    int* newArr=parnep(arr,n,newSize);
    cout<<"masiv z chetnymi , nechetnymi: ";
    printArray(newArr, newSize);

    delete[] arr;
    delete[] newArr;

    return 0;
}

