#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
void generateRandomArray(vector<T>& arr, int size, int minVal, int maxVal) 
{
    arr.resize(size);
    for (int i=0;i<size;++i)
        arr[i]=rand()%(maxVal-minVal+1)+minVal;
}

template <typename T>
void printArray(const vector<T>& arr) 
{
    for (T val:arr)
        cout<<val<<" ";
    cout<<endl;
}

template <typename T>
int countEqualFirst(const vector<T>& arr) 
{
    if(arr.empty()) return 0;
    int count=0;
    for (T val:arr)
        if(val==arr[0]) 
		++count;
    return count;
}

template <typename T>
void swapByIndices(vector<T>& arr, int i, int j) 
{
    if(i>=0 && j>=0 && i<arr.size() && j<arr.size())
        swap(arr[i], arr[j]);
}

template <typename T>
void insertAt(vector<T>& arr, int index, T value) 
{
    if(index>=0 && index<=arr.size())
        arr.insert(arr.begin()+index,value);
}

template <typename T>
void longestEqualSegment(const vector<T>& arr, int& startIndex, int& endIndex) 
{
    int maxLen=1,currLen=1;
    int start=0;
    startIndex=0;
    endIndex=0;

    for(int i=1;i<arr.size();++i) 
	{
        if(arr[i]==arr[i-1]) 
		{
            ++currLen;
        } 
		else 
		{
            currLen=1;
            start=i;
        }

        if(currLen>maxLen) 
		{
            maxLen=currLen;
            startIndex=start-maxLen+1;
            endIndex=start;
        }
    }
}

template <typename T>
void sortBetweenExtremes(vector<T>& arr) 
{
    if(arr.empty()) 
	return;
    auto minIt=min_element(arr.begin(),arr.end());
    auto maxIt=max_element(arr.begin(),arr.end());

    int minIdx=distance(arr.begin(),minIt);
    int maxIdx=distance(arr.begin(),maxIt);

    if (minIdx>maxIdx)
	swap(minIdx, maxIdx);

    sort(arr.begin()+minIdx+1,arr.begin()+maxIdx);
}


int main() 
{
    srand(time(0));
    vector<int> arr;
    generateRandomArray(arr, 15, 0, 9);

    cout << "Pochatkovyi masiv: ";
    printArray(arr);

    cout << "Kilikisti elementiv rivnyh pershomu: " << countEqualFirst(arr) << endl;

    swapByIndices(arr, 1, 3);
    cout << "Pislea obminu mij 1 ta 3: ";
    printArray(arr);

    insertAt(arr, 5, 99);
    cout << "pislea vtsavky 99 pislea 5: ";
    printArray(arr);

    int start, end;
	longestEqualSegment(arr, start, end);
	cout << "Najdovsha dileanka elementiv: z " << start << " po " << end << endl;


    sortBetweenExtremes(arr);
    cout << "Pislea sortuvania mij min ta max: ";
    printArray(arr);

    return 0;
}
