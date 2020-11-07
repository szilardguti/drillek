#include "std_lib_facilities.h"

namespace UDChrono {

class Year{
	int y;
	static constexpr int min = 1800;
	static constexpr int max = 2200;
public:
	Year(int x): y(x) { if(x < min || x > max) throw Invalid{};}
	class Invalid{};
	int year() { return y; }
	void increment() { y++; }
};

Year operator++(Year& year)
{
	year.increment();
}

ostream& operator<<(ostream& os, Year year)
{
	return os << year.year();
}

const vector<string> months =
{
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December",
};

enum class Month {
	jan, feb, mar, apr, may, jun, july, aug, sept, oct, nov, dec
};

Month operator++(Month& m)
{
	m = (m == Month::dec) ? Month::jan : Month(int(m) + 1);//egyszerűsített if
							//igaz			//hamis
	return m;
}

ostream& operator<<(ostream& os, Month m)
{
	return os << months[int(m)];
}



class Date {
	Year year;
	Month month;
	int day;
public:
	class Invalid {};
	Date(Year y, Month m, int d): year(y), month(m), day(d) { if(!is_valid()) throw Invalid{}; } // konstruktor - hogyan kell elkészíteni
	Date(): year(Year{2001}), month(Month::jan), day(1) {};
	void add_day(int n);
	bool is_valid();
	Year get_year() const {return year; }
	Month get_month() const {return month; }
	int get_day() const {return day; } //const - nem változtatja meg az állapotát!
};

bool Date::is_valid()
{
	if ( day < 0 || day > 31)
		return false;
	return true;
}

/*
Date::Date(int y, int m, int d)
{
	if(y > 0)
		year = y;
	else
		error("Invalid year");

	if(m <= 12 && m > 0)
		month = m;
	else
		error("Invalid month");

	if(d <= 31 && m > 0)
		day = d;
	else
		error("Invalid day");

}
*/

void Date::add_day(int n)
{
	day += n;
	do{
	if(day > 31)
		{
			++month;
			day -= 31;

			if(month == Month::jan)
			{
				++year;
			}
		}
	}while(day / 31 != 0);
}

} // UDChrono ends here

int main()
try{

	UDChrono::Date today {UDChrono::Year{2020},UDChrono::Month::aug,31};


	/*cout << "Date: " << today.year << '.' << 
		today.month << '.' << today.day << ".\n";*/



	cout << "Date: " << today.get_year() << ". " << 
		today.get_month() << ' ' << today.get_day() << ".\n";


	UDChrono::Date tomorrow {today};// lemásolja a today értékeit

	tomorrow.add_day(1);

	cout << "Date: " << tomorrow.get_year() << ". " << 
		tomorrow.get_month() << ' ' << tomorrow.get_day() << ".\n";


		vector<UDChrono::Date> dates(10);


		cout << "\nVector:\n";
		for(const auto& date : dates)
			cout << "Date: " << date.get_year() << ". " << 
				date.get_month() << ' ' << date.get_day() << ".\n";



	return 0;
}
catch (UDChrono::Date::Invalid){
	cerr << "Invalid date\n";
	return 1;
}
catch (UDChrono::Year::Invalid){
	cerr << "Invalid year\n";
	return 2;
}
 catch (exception& e){
	cerr << e.what() << endl;
	return 3;
}