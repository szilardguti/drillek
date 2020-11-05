#include "std_lib_facilities.h"

struct Date{
	int y;
	int m;
	int d;
};

void init_day(Date& dd, int y, int m, int d)
{
	if(y > 1800 && y < 2100 && m > 0 && m < 13 && d > 0 && d < 31)
	{
		dd.y = y; dd.m = m; dd.d = d;
	}
	else error("Wrong date in init_day");
	
}

void add_day(Date& dd, int n)
{
	dd.d += n;
}

int main()
{
	Date today;
	
	init_day(today,2005,12,24);
	add_day(today,5);
	
	cout << today.y << "\t" << today.m << "\t" << today.d << endl;
	
	return 0;
}
