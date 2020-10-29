#include "std_lib_facilities.h"

constexpr char number = '8';
constexpr char quit = 'q';
constexpr char print = ';';
constexpr char result = '=';
constexpr char let = 'L';
constexpr char name = 'a';
constexpr char square_root = '@';
constexpr char pow1 = 'p';

//const string declkey = "let";
const string sqrtkey = "sqrt";
const string powkey = "pow";
const string quitkey = "quit";

double expression();

class Variable
{
public:
	string name;
	double value;

};

vector<Variable> var_table;

bool is_declared(string var){ //volt-e már deklarálva a változó - define_name-hez kell
	for(const auto& v : var_table)
		if(v.name == var) return true;
	return false;
}

double define_name(string var, double val){ //felveszi a változót és berakja a vektorba
	if(is_declared(var)) error("Variable is already declared: ", var);
	var_table.push_back(Variable{var,val});
}

double get_value(string s){ //megkeresi a vektorból és megadja az értékét
	for (const auto& v : var_table)
		if (v.name == s) return v.value;
	error("get: variable not defined");
}

void set_value(string s, double d){ //megkeresi és beállítja az értékét
	for (auto& v : var_table)
		if(v.name == s)
		{
			v.value = d;
			return;
		}
	error("set: variable not defined");
}	

class Token
{
public:
	char kind; // egy tokennek van típusa
	double value; //értéke
	string name; //a változók óta neve is lehet
	Token(): kind(0) {}
	Token (char ch): kind(ch), value(0) {} //konstruktorok
	Token (char ch, double val): kind(ch),value(val) {}	
	Token (char ch, string n): kind(ch), name(n) {}
};


class Token_stream { //Token_stream végzi a "pakolgatást"
public:
	Token_stream();
	Token get();//bekéri a következő tokent és megvizsgálja, a helyes típust és/vagy értéket adja vissza

	void putback(Token t);//visszarakja az épp vizsgált tokent
	void ignore(char c);//kidobálja az ignorálandó karaktereket
private:
	bool full;
	Token buffer;

};

Token_stream::Token_stream(): full(false), buffer(0) {}


void Token_stream::putback(Token t)
{
	if(full) error("Token_stream buffer full");
	buffer = t;
	full = true;
}

Token Token_stream::get()
{

	if (full)
	{
		full = false;
		return buffer;
	}


	char ch;
	cin >> ch;

	switch(ch)	//itt viszgálja az éppen bekért token típusát
	{	
		case '#': return Token{let};			
		//case quit: //így nem működik sima 'q' beírására csak "quit"-re
		case print:
		case '(':
		case ')':
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
		case '=':
		case ',':
			return Token(ch);

		case '.':
		case '0': case '1': case '2': 
		case '3': case '4': case '5':
		case '6': case '7': case '8':
		case '9':
		{
			cin.putback(ch);
			double val = 0;
			cin >> val; 

			return Token(number,val);
		}
		default://ha nem szám vagy operátor akkor egy további kifejezés lehet (pl variable)
		{
			if (isalpha(ch))
			{
				string s;
				s += ch;
				while(cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;
				cin.putback(ch);

				//if(s == declkey) return Token{let};
				/*else*/ if( s == sqrtkey) return Token{square_root};
				else if(s == powkey) return Token{pow1};
				else if(s == quitkey) return Token{quit};
				else if(is_declared(s))
					return Token(number, get_value(s));
				return Token{name, s};
			}
			error("Bad token");
		}
	}
}

void Token_stream::ignore(char c)
{
	if (full && c == buffer.kind)
	{
		full = false;
		return;
	}

	full = false;

	char ch = 0;
	while(cin >> ch)
		if (ch == c) return;
	
}

Token_stream ts;

double calc_sqrt(){ //négyzetgyököt számol

	char ch;
	if(cin.get(ch) && ch != '(') error("'(' expected in square root");
	cin.putback(ch);
	double d = expression();

	if(d < 0) error("square root: negative value");
	return sqrt(d);//cmath-ból meghívott
}

double calc_pow(){ //valahanyad hatványt számol

   Token t = ts.get();
   if (t.kind != '(')
    error("'(' expected in pow");
   double d = expression();

   t = ts.get();
   if (t.kind != ',')
    error("',' expected in pow");
   double i = expression();

   t = ts.get();
   if (t.kind != ')')
    error("')' expected in pow");

   return pow(d, i);
  }


double primary()//az elsőre is kiértékelhetőket ..... kiértékeli
{
	Token t = ts.get();
	switch(t.kind)
	{
		case '(':
		{
			double d = expression();
			t = ts.get();

			if(t.kind != ')') error("')' expected");
			return d;		
		}

		case number:
			return t.value;

		case '-':
			return - primary();
		case '+':
			return primary();
		case square_root:
			return calc_sqrt();
		case pow1:
			return calc_pow();
		default:
			error("primary expected");
	}
}

double term()// '/'/*/% okat kezeli
{
	double left = primary();
	Token t = ts.get();

	while(true)
	{
		switch(t.kind)
		{
			case '*':
				left *= primary();
				t = ts.get();
				break;
			case '/':
			{
				double d = primary();
				if(d == 0 ) error("divide by zero!");

				left /= d;
				t = ts.get();
				break;
			}
			case '%':
			{

				double d = primary();
				if (d == 0) error("%: zero divider");

				left = fmod(left,d);
				t = ts.get();
				break;

				/*
				int i1 = narrow_cast<int> (left);
				int i2 = narrow_cast<int> (primary());
				if (i2 == 0) error("%: zero divider");
				
				left = i1 % i2;
				t = ts.get();
				break;
				*/
			}
				/*
				left %= primary();
				t = get_token();
				break;
				*/
			default:
				ts.putback(t);
				return left;

		}
	}
}




double expression()// +/- okat kezeli
{

	double left = term();
	Token t = ts.get();

	while(true)
	{
		switch(t.kind)
		{
			case '+': 
				left += term();
				t = ts.get();
				break;

			case '-': 
				left -= term();
				t = ts.get();
				break;
			default:
				ts.putback(t);
				return left;
		}
	}
}

void clean_up_mess(){
	ts.ignore(print);
}

double declaration(){ //deklarációkat kezeli
	Token t = ts.get();
	if(t.kind != name) error("name expected in declaration");
	string var_name = t.name;

	Token t2 = ts.get();
	if(t2.kind != '=') error("'=' expected in declaration");

	double d = expression();
	define_name(var_name, d);//létrehoz és úgy változót
	return d;
}

double statement()//eldönti hogy deklarálni akarunk-e
{
	Token t = ts.get();
	switch(t.kind){

		case let:
			return declaration();

		default:
			ts.putback(t); 
			return expression();
	}
}

void calculate()//a számolás innen kezdődik
{
	//double val = 0;

	while(cin)//folyamatos input bekérés
	try{

		Token t = ts.get();//bekéri a következő tokent

 		while(t.kind == print) t = ts.get(); //ameddig print tokent nem kap
 		if(t.kind == quit) return; //vagy kilépést

 		ts.putback(t);
 		cout << result << statement() << endl; 

		/*
		if (t.kind == quit) break;
		if (t.kind == print) 
			cout << result << val << endl;
		else
			ts.putback(t);
		
		val = expression();
		*/
	}
	catch(exception& e)
	{
		cerr << e.what() << endl;
		clean_up_mess();
	}
}



int main()
try{

	define_name("k", 1000);//akármilyen változót így adhatunk meg

	calculate();

	return 0;

}
catch (exception& e)
{
	cerr << e.what() << endl;
	return 1;
}
catch (...)
{
	cerr << "exceptions\n";
	return 2;
}