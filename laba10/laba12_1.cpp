#include <iostream>
#include <vector>
using namespace std;

void print(const vector<int>& v) 
{
    for(int n : v)
    cout<<n<<" ";
    cout<<endl;
}

int main() 
{
    vector<int> arr(10);
    
    cout<<"Vediti 10 chysel:\n";
    for(int i=0;i<10;i++)
        cin>>arr[i];

    arr[1] = 10;
    print(arr);

    arr.pop_back();
    print(arr);

    arr.push_back(25);
    print(arr);

    return 0;
}
