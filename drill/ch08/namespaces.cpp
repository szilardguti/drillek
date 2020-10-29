#include <iostream>

using namespace std;

namespace X {
	double var;

	void print()
	{
		cout << "X: " << var << endl;
	}
}

namespace Y {
	double var;

	void print()
	{
		cout << "Y: " << var << endl;
	}
}

namespace Z {
	double var;

	void print()
	{
		cout << "Z: " << var << endl;
	}
}

int main()
{
	X::var = 7;
	X::print();

	using namespace Y;
	var = 9;
	print();

	{
		using Z::var;
		using Z::print;

		var = 11;
		print();
	}
	print();
	X::print();
}