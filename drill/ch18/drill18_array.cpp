#include "std_lib_facilities.h"

int ga[10] {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

void f(int ar[], int n)
{
	int la[10];
	copy( ga, &ga[10], la);

	for(int i = 0;i < 10; ++i)
		cout << la[i] << ' ';
	cout << endl;

	int* p = new int[n];
	copy(ar, &ar[n], p);

	for(int i = 0; i < n; i++)
		cout << p[i] << ' ';
	cout << endl;

}

int factor(int n)
{
	if(n > 1) return n*(factor(n-1));
	return 1;
}

int main()
{
	cout << "ga:\n";
	f(ga,10);

	cout << "\naa:\n";
	int aa[10] {factor(1), factor(2), factor(3), factor(4), factor(5), factor(6), factor(7), factor(8), factor(9), factor(10)};
	f(aa,10);
	
	return 0;
}