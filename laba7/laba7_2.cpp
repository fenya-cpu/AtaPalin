#include <iostream>
using namespace std;

double surfaceArea(double length,double width=1,double height=1) 
{
    return 2*(length * width + width * height + length * height);
}

int main() 
{
	int l,w,h;
	cout<<"Vediti dovjynu: ";
	cin>>l;
    cout<<"Surface area: "<<surfaceArea(l)<<endl;
    cout<<"Vediti dovjynu,shyrynu,ta vysotu: ";
	cin>>l>>w>>h;
    cout<<"Surface area: "<<surfaceArea(l,w,h)<<endl;
    return 0;
}

