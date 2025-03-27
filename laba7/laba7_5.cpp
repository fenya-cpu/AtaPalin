#include <iostream>
#include <cstdarg>
using namespace std;
const int SIZE = 12;

void func(int a[], int b[], int count, ...) 
{
    va_list args;
    va_start(args, count);

    cout<<"Nespivpdaiuci indexy: ";
    bool found=false;

    for (int i=0;i<count;++i) 
	{
        int index=va_arg(args,int);
        if(index>=0 && index<SIZE) 
		{
            if (a[index]!=b[index]) 
			{
                cout<<index<<" ";
                found=true;
            }
        }
    }

    va_end(args);

    if(!found) 
	{
        cout<<"nemae";
    }
    cout<<endl;
}

int main() 
{
    int a[SIZE]={13, 4, 2, 28, 34, 7, 10, 21, 43, 50, 37, 11};
    int b[SIZE]={5, 4, 12, 3, 30, 7, 11, 45, 49, 37, 15, 11};

    func(a, b, 5, 1, 4, 5, 9, 10);

    return 0;
}

