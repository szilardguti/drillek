#include "std_lib_facilities.h"
int main()
try {
//Cout << "Success!\n";
cout << "Success!\n";	
//cout << "Success!\n";
cout << "Success!\n";
//cout << "Success" << !\n"
cout << "Success!\n";
//cout << success << '\n';
cout << "Success!\n";

/*string res = 7; 
vector<int> v(10); 
v[5] = res; 
cout <<"Success!\n";*/
int res = 7; 
vector<int> v(10); 
v[5] = res; 
cout <<"Success!\n";

/*vector<int> v(10); 
v(5) = 7; 
if (v(5)!=7) cout << "Success!\n";*/
//vector<int> v(10); -- már deklarálva volt
v[5] = 7; 
if (v[5]==7) cout << "Success!\n";

/*if (cond) cout << "Success!\n"; 
else cout << "Fail!\n";*/

bool cond = true;
if (cond) cout << "Success!\n"; 
else cout << "Fail!\n";

/*bool c = false; 
if (c) cout << "Success!\n"; 
else cout <<"Fail!\n";*/

bool c = false; 
if (!c) cout << "Success!\n"; 
else cout <<"Fail!\n";

/*string s = "ape";
boo c = "fool" < s; 
if (g) cout <<"Success!\n";*/

string s = "ape";
bool c2 = "fool" > s; 
if (c2) cout <<"Success!\n";

/*string s = "ape";
if (s=="fool") cout << "Success!\n";*/

string s2 = "ape";
if (s2 !="fool") cout << "Success!\n";

/*string s = "ape"; 
if (s=="fool") cout < "Success!\n";*/

string s3 = "ape"; 
if (s3 !="fool") cout << "Success!\n";

/*string s = "ape"; 
if (s+"fool") cout < "Success!\n";*/

string s4 = "ape"; 
if (s4 != "fool") cout << "Success!\n";

/*vector<char> v(5); 
for (int i=0; 0<v.size(); ++i) ; 
	cout <<"Success!\n";*/

vector<char> v2(1); //eszerint futtatja le
for (int i=0; i < v2.size(); ++i) 
	cout <<"Success!\n";

/*vector<char> v(5); 
for (int i=0; i<=v.size(); ++i)  
cout <<"Success!\n";*/

vector<char> v3(0); 
for (int i=0; i<=v3.size(); ++i)  
cout <<"Success!\n";

/*string s = "Success!\n"; 
for (int i=0; i<6; ++i) cout << s[i];*/

string s5 = "Success!\n"; 
for (int i=0; i< s5.size(); ++i) cout << s5[i];

/*if (true) then cout << "Success!\n"; 
else cout << "Fail!\n";*/

if (true) cout << "Success!\n"; 
else cout << "Fail!\n";

/*int x = 2000; 
char c = x; 
if (c==2000) cout << "Success!\n";*/

int x = 2000; 
int c3 = x; 
if (c3==2000) cout << "Success!\n";

/*string s = "Success!\n"; 
for (int i=0; i<10; ++i) cout << s[i];*/

string s6 = "Success!\n";
 for (int i=0; i< s6.size(); ++i) cout << s6[i];

/*vector v(5); 
for (int i=0; i<=v.size(); ++i) 
	 cout <<"Success!\n";*/

vector<char> v4(1); 
for (int i=0; i< v4.size(); ++i) 
	 cout <<"Success!\n";


/*int i=0; 
int j = 9; 
while (i<10) ++j; 
if (j<i) 
cout <<"Success!\n";*/

int i=0; 
int j = 9; 
while (i<10) ++i; 
if (j<i) 
cout <<"Success!\n";

/*int x = 2; 
double d = 5/(x–2); 
if (d==2*x+0.5) 
	cout <<"Success!\n";*/

double x2 = 2; 
double d = 5/x2; 
if (d 	==	x2 + 0.5) cout <<"Success!\n";

/*string<char> s = "Success!\n"; 
for (int i=0; i<=10; ++i) 
	cout << s[i];*/

string s7 = "Success!\n"; 
for (int i=0; i<s7.size(); ++i) 
	cout << s7[i];

/*int i=0; 
while (i<10) ++j; 
if (j<i) cout << "Success!\n";*/

int i2=0;
int j2=0;
while (i2<10) ++i2; 
if (j2<i2) cout << "Success!\n";

/*int x = 4; 
double d = 5/(x–2); 
if (d=2*x+0.5) c
	out <<"Success!\n";*/

double x3 = 4; 
double d3 = 0 ; 
d3 = 5/ (x3 - 2); 
if (d3 == x3/2+0.5) 
	cout <<"Success!\n";
cout << endl;

cout << "Success!\n";



keep_window_open();
return 0;
}

catch (exception& e) {
cerr << "error: " << e.what() << '\n';
keep_window_open();
return 1;
}

catch (...) {
cerr << "Oops: unknown exception!\n";
keep_window_open();
return 2;
}