#include "std_lib_facilities.h"

void print_array10(ostream& os, int* a)
{
	for(int i = 0;i < 10; ++i)
		os << a[i] << ' ';
	os << endl;
}

void print_array(ostream& os, int* a, int n)
{
	for(int i = 0;i < n; ++i)
		os << a[i] << ' ';
	os << endl;
}

void print_vector(ostream& os,vector<int*> a, int n)
{
	for(int i = 0;i < n; ++i)
		os << *a[i] << ' ';
	os << endl;
}

void allocate_array(int*& ar, int n)
{
	for(int i = 0;i < n; ++i)
		ar[i] = 100 + i;
}

void allocate_vector(vector<int*>& v, int n)
{
	for(int i = 0;i < n; ++i)
		v.push_back(new int {100+i});
}

void delete_vector(vector<int*> v, int n)
{
	for(int i = 0;i < n; ++i)
		delete v[i];
}

int main()
{
	int* ar1 = new int[10]{0, 0, 0, 0, 0, 0, 0, 0, 0, 0};


	for(int i = 0;i < 10; ++i)
		cout << ar1[i] << ' ';
	cout << endl;

	print_array10(cout, ar1);


	int* ar2 = new int[10]{100, 101, 102, 103, 104, 105, 106, 107, 108, 109};

	print_array(cout, ar2, 10);


	int* ar3 = new int[11];

	allocate_array(ar3, 11);
	print_array(cout, ar3, 11);


	int* ar4 = new int[20];

	allocate_array(ar4, 20);
	print_array(cout, ar4, 20);


	cout << "////////////////////////////vector///////////////////////////" << endl;

	vector<int*>  v1;
	allocate_vector(v1, 10);
	print_vector(cout, v1, 10);

	vector<int*> v2;
	allocate_vector(v2, 11);
	print_vector(cout, v2, 11);

	vector<int*> v3;
	allocate_vector(v3, 20);
	print_vector(cout, v3, 20);

	delete[] ar1;
	delete[] ar2;
	delete[] ar3;
	delete[] ar4;

	delete_vector(v1, 10);
	delete_vector(v2, 11);
	delete_vector(v3, 20);

	return 0;
}