#include "std_lib_facilities.h"

int main()
{
	int birth_year = 2001;
	int my_age = 19;

	cout << dec << birth_year << "\t(decimal)\n"
		<< hex << birth_year << "\t(hexadecimal)\n"
		<< oct << birth_year << "\t(octal)\n";

	cout << "My age: " << dec << my_age << endl;


	cout << showbase << dec << birth_year << "\t(decimal)\n"
		<< hex << birth_year << "\t(hexadecimal)\n"
		<< oct << birth_year << "\t(octal)\n" << noshowbase << dec;

	int a, b, c, d;
	cin >> a >>	oct >> b >> hex >> c >> d;
	cout << a << '\t'<< b << '\t'<< c << '\t'<< d << '\n' ;


	cout 
		<< defaultfloat << 1234567.89 << "\t(defaultfloat)\n"
		<< fixed << 1234567.89 << "\t(fixed)\n"
		<< scientific << 1234567.89 << "\t(scientific)\n";

	cout << '|' << setw(8) <<"Guti" << '|' << setw(10) << "Szili" << '|' 
		<< endl;
}