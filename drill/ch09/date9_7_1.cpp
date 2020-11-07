#include "std_lib_facilities.h"

enum class Month{
	jan = 1, feb, mar, apr, may, jun, july, aug, sep, oct, nov, dec
};

class Year {
	static const int min = 1800;
	static const int max = 2200;
	int y;
public:
	class Invalid{};
	Year(int x): y(x) {if(x < min && x > max) throw Invalid{};}
	int year() {return y;}
}

class Date {
	int d;
	Month m;
	Year y;
public:
	Date(Year year,Month month,int day): y(year),m(month),d(day){if (!letezik(y,m,d)) error("Wrong date!");}
	void add_day(int n);
	bool letezik(int y,int m,int d);

	int day() {return d;}
	int month() {return m;}
	int year() {return y;}
};

bool Date::letezik(int y,int m,int d)
{
	if(d > 0 && d < 31) return true; 
		else return false;
}

void Date::add_day(int n)
{
	d += n;
	if (!letezik(y,m,d)) error("Wrong date!");
}


int main()
{

	Date today{2020,11,07};

	cout << today.year() << "." 
		<< today.month() << "." << today.day() << endl;

	Date tomorrow{today};
	tomorrow.add_day(1);

	cout << tomorrow.year() << "." 
		<< tomorrow.month() << "." << tomorrow.day() << endl;

	return 0;
}