#include <iostream>
using namespace std;

double surfaceArea(double length,double width,double height) 
{
    return 2*(length * width + width * height + length * height);
}

int main() 
{
	int l,w,h;
	cout<<"Vediti length,width,height: ";
	cin>>l>>w>>h;
    cout<<"Surface area: "<<surfaceArea(l, w, h)<<endl;
    return 0;
}

