#include "std_lib_facilities.h"



int main()
{

	string first_name,friend_name;
	char friend_sex = 0;
	int age = 0;


	cout << "Enter the name of the person you want to write to: ";
	cin >> first_name;

	cout << "Name one of your friend: ";
	cin >> friend_name;

	cout << "Please enter the sex of the other friend (f/m): ";
	cin >> friend_sex;

	cout << "Enter the age of the recipient: ";
	cin >> age;

	if(age < 0 || age > 110) simple_error("youre kidding!");



	cout << "Dear " << first_name << ",\n" << endl; 

	cout << "How are you? I hope you're doing great. I miss you:(\n"
		 << "Sorry for not writing for such a long time.\n"
		 << "Have you seen " << friend_name << " lately?\n" ;


	if (friend_sex == 'f')
	{
		cout << "If you see " << friend_name << " please tell her to call me!\n";

	}
	else if(friend_sex == 'm')
	{
		cout << "If you see " << friend_name << " please tell him to call me!\n";
	
	}


	cout << "I hear you just had a birthday and you are " << age << " years old.\n";


	if(age < 12) cout << "Next year you will be " << age+1 << ".\n";
	else if(age == 17) cout << "Next year you will be able to vote.\n";
	else if(age > 70) cout << "I hope you are enjoying retirement.\n";


	cout << "Yours sincerely, \n\n\nSzilárd\n";

}