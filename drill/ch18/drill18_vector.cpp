#include "std_lib_facilities.h"

vector<int> gv {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

int factor(int n)
{
	if(n > 1) return n*(factor(n-1));
	return 1;
}

void f(vector<int> v)
{
	vector<int> lv(v.size());

	lv = gv;

	for(int i : lv)
		cout << i << ' ';
	cout << endl;

	vector<int> lv2(v);
	for(int i : lv2)
		cout << i << ' ';
	cout << endl;
}

int main()
{
	cout << "gv:\n";
	f(gv);

	cout << "\nvv:\n";
	vector<int> vv{factor(1), factor(2), factor(3), factor(4), factor(5), factor(6), factor(7), factor(8), factor(9), factor(10)};
	f(vv);

	return 0;
}