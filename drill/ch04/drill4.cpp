#include "std_lib_facilities.h"


int main()
{

	/*
	double num1 = 0, num2 = 0;

	while(cin >> num1 >> num2)
	{

		if(num1 < num2)
		{

			cout << "the smaller value is: " << num1 
			<< "\nthe larger value is: " << num2 << endl;


		}
		else if(num1 > num2)
		{

			cout << "the smaller value is: " << num2 
			<< "\nthe larger value is: " << num1 << endl;

		}
		else if(num1 == num2) cout << "the numbers are equal!\n";


		if((abs(num1-num2)) < 0.01) cout << "the numbers are almost equal" << endl; 


	}
	*/


	double numN = 0, min = 0, max = 0, sum = 0;
	string unit;
	bool min_Empty = true;

	vector<double> nums ;


	static double m_to_cm = 100, in_to_cm = 2.54, ft_to_in = 12;

	while(cin >> numN >> unit)
	{

		cout << numN << unit << endl;

		if(unit == "cm" || unit == "m" || unit == "in" || unit == "ft")
		{

			if(unit == "cm") numN = numN / m_to_cm;

			if(unit == "in") numN = (numN * in_to_cm)/ m_to_cm;

			if(unit == "ft") numN = ((numN * ft_to_in) * in_to_cm ) / m_to_cm;



			sum += numN;
			nums.push_back(numN);


			if(min_Empty)
			{
				min=numN;
				min_Empty = false;
			}


			if(numN < min)
			{
				min = numN;
				cout << "the smallest so far\n";
			}
			else if(numN > max)
			{
				max = numN;
				cout << "the largest so far\n";
			}

		}
		else simple_error("not valid unit");
	}

	cout << "the smallest entered value in meter: " << min << endl;

	cout << "the largest entered value in meter: " << max << endl;

	cout << "the sum of the values entered: " << sum << endl;

	cout << "the number of entered values: " << nums.size() << endl;


	sort(nums);

	for (double szamok : nums)
		cout << szamok << endl;


	return 0;
}