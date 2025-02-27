#include <iostream>
#include <conio.h>

using namespace std;
int main()
{
	float a[100];
	int n;
	float* p;

	p = &a[0];

	cout << "rozmirnisti n:" <<endl;
	cin >> n;

	for (int i = 0; i < n; i++) 
	{
		cin >> *p;
		p++;
	}

	p = &a[0];

	float s = 0;

	for (int i = 0; i < n; i++) 
	{
		float* pi = &a[i];
		float* pm = &a[i - 1];
		float* pp = &a[i + 1];
		s += *p;

		if (static_cast<int>(*pi) % 5 == 0) 
		{

			for (int j = n; j > i + 1; j--) 
			{
				float* pj = &a[j];
				float* p1 = &a[j - 1];
				*pj = *p1;
			}

			*pp = s - *pi;
			n++;
			i++;
		}
		p++;
	}

	p = &a[0];

	for (int i = 0; i < n; i++) {
		cout << *p << " ";
		p++;
	}

	p = &a[0];

	return 0;
}
