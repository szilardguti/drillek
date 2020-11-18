#include "std_lib_facilities.h"

void delete_vector(vector<int*> v, int n)
{
	for(int i = 0;i < n; ++i)
		delete v[i];
}

int main()
{
	int* p1 = new int{7};
	cout << p1 << '\t' << *p1 << endl;


	int* p2 = new int[7]{1, 2, 4, 8, 16, 32, 64};
	cout << p2 << '\t';

	for(int i = 0; i < 7; ++i) 
		cout << p2[i] << ' ';
	cout << endl;


	int* p3 = p2;

	p2 = p1;
	p2 = p3;

	cout << p1 << '\t' << *p1 << endl;
	cout << p2 << '\t' << *p2 << endl;

	delete p1;
	delete[] p2;


	p1 = new int[10]{1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

	p2 = new int[10];

	for(int i = 0;i < 10; ++i)
	{
		p2[i] = p1[i];
	}

	/*for(int i = 0;i < 10; ++i)
	{
		cout << p2[i] << ' ';
	}cout << endl;*/

	vector<int*> v1;
	for(int i = 0;i < 10; ++i)
		v1.push_back(new int{p1[i]});

	vector<int*> v2;
	for(int i = 0;i < 10; ++i)
		v2.push_back(new int{0});

	for(int i = 0;i < 10; ++i)
		*v2[i] = *v1[i];

	/*for (int i = 0; i < 10; ++i)
	{
		cout << v1[i] << ':' << *v1[i] << '\t' << v2[i] << ':' << *v2[i] << endl;
	}*/


	delete[] p1;
	delete[] p2;
	delete_vector(v1, 10);
	delete_vector(v2, 10);

	return 0;
}