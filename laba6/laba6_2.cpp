#include <iostream>
#include <cmath>
#include <fstream>
#include <stdlib.h>
#include <ctime>
using namespace std;

bool gol(char c) 
{
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y');
}

char randc(bool gol) 
{
    if (gol) 
	{
        char gol[] = {'a', 'e', 'i', 'o', 'u', 'y'};
        return gol[rand() % 6];
    } 
	else 
	{
        char cons[]={'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'z'};
        return cons[rand()%20];
    }
}

char** matrita(int n) 
{
    char** a = new char*[n];
    for(int i=0;i<n;i++) 
	{
        a[i]=new char[n];
        for(int j=0;j<n;j++) 
		{
            if(i==j || i+j==n-1) 
			{
                a[i][j]=randc(true);
            } else 
			{
                a[i][j]=randc(false);
            }
        }
    }
    return a;
}


void print(char** a, int n) 
{
    for(int i=0;i<n;i++) 
	{
        for(int j=0;j<n;j++) 
		{
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool ryad(char** a, int n, string s) 
{
    for(int i=0;i<n;i++) 
	{
        for(int j=0;j<=n-s.length();j++) 
		{
            bool f=true;
            for(int k=0;k<s.length();k++) 
			{
                if(a[i][j+k]!=s[k]) 
				{
                    f=false;
                    break;
                }
            }
            if(f) 
			{
                cout<<"Slovo e v riadku "<<i+1<<" na pozitii "<<j+1<<" - "<<j+s.length()<<endl;
                return true;
            }
        }
    }
    return false;
}

bool stovp(char** a, int n, string s) 
{
    for(int j=0;j<n;j++) 
	{
        for(int i=0;i<=n-s.length();i++) 
		{
            bool f=true;
            for(int k=0;k<s.length();k++) 
			{
                if(a[i+k][j]!=s[k]) 
				{
                    f=false;
                    break;
                }
            }
            if(f) 
			{
                cout<<"Slovo e v stovpti "<<j+1<< " na pozitii " <<i+1<<" - "<<i+s.length()<<endl;
                return true;
            }
        }
    }
    return false;
}

int main() 
{
    srand(time(NULL));
    int n;
    cout<<"Vediti rozmirnisti n: ";
    cin>>n;
    
    char** a = matrita(n);
    
    cout<<"Matrita:"<<endl;
    print(a,n);
    
    string s;
    cout<<"Vediti slovo dlia poshuku: ";
    cin>>s;
    
    bool f=ryad(a,n,s) || stovp(a,n,s);
    if(!f) 
	{
        cout<<"Slovo ne maie"<<endl;
    }
    
    for(int i=0;i<n;i++) 
	{
        delete[] a[i];
    }
    delete[] a;
    
return 0;
}

