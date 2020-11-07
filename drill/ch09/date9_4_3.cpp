#include "std_lib_facilities.h"

class Date {
	int y,m,d;
public:
	Date(int year,int month,int day): y(year),m(month),d(day){if (!letezik(y,m,d)) error("Wrong date!");}
	void add_day(int n);
	bool letezik(int y,int m,int d);

	int day() {return d;}
	int month() {return m;}
	int year() {return y;}
};

bool Date::letezik(int y,int m,int d)
{
	if(y > 1800 && y < 2100 && m > 0 && m < 13 && d > 0 && d < 31) return true; 
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