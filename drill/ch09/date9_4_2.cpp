#include "std_lib_facilities.h"

struct Date{
	int y,m,d;
	bool letezik(int y,int m,int d);
	Date(int year,int month,int day): y(year),m(month),d(day){if (!letezik(y,m,d)) error("Wrong date!");}
	void add_day(int n);
	};

bool Date::letezik(int y,int m,int d)
{
	if(y > 1800 && y < 2100 && m > 0 && m < 13 && d > 0 && d < 31) return true; 
		else return false;
}


int main()
try{
	Date today{2001,07,23};
	
	cout << today.y << "\t" << today.m << "\t" << today.d << "\n";
	
	Date miez{2005,23,52};

	cout << miez.y << "\t" << miez.m << "\t" << miez.d << "\n";

	
	return 0;
}catch(exception& e)
{
	cerr << e.what() << endl;
	return 1;
}catch(...)
{
	cerr << "Exceptions occurred!" << endl;
	return -1;
}
