/*
	calculator08buggy.cpp
	Helpful comments removed.
	We have inserted 3 bugs that the compiler will catch and 3 that it won't.
*/



/*
Simple calculator
Revision history:
Revised by Bjarne Stroustrup November 2013
Revised by Bjarne Stroustrup May 2007
Revised by Bjarne Stroustrup August 2006
Revised by Bjarne Stroustrup August 2004
Originally written by Bjarne Stroustrup

This program implements a basic expression calculator.
Input from cin; output to cout.
The grammar for input is:

Statement:
Expression
Print
Quit


Print:
;

Quit:
q


Expression:
Term
Expression + Term
Expression – Term


Term:
Primary
Term * Primary
Term / Primary
Term % Primary


Primary:
Number
( Expression )
– Primary
+ Primary


Number:
floating-point-literal
Input comes from cin through the Token_stream called ts.
*/



#include "../std_lib_facilities.h" //absolute path error[0]

//Define a struct with constructors and fileds

struct Token {
	char kind;
	double value;
	string name;
	Token(char ch) :kind(ch), value(0) { }
	Token(char ch, double val) :kind(ch), value(val) { }
	Token(char ch, string s) :kind(ch), name(s) { } // We need a new constructor -Adam error[1]
};

//Create a new class for Token with the following fields

class Token_stream {
	bool full;
	Token buffer;
public:
	Token_stream() :full(0), buffer(0) { }

//define a void to clean the buffer

	Token get();
	void unget(Token t) { buffer = t; full = true; }

	void ignore(char);
};

//constants

const char let = '#';
const char quit = 'Q';
const char print = ';';
const char number = '8';
const char name = 'a';
const char sq = 's';
const char hatvany = '^';


//Observe the full variable if is it full or not.
// define the operators and numbers in a switch-case structure

Token Token_stream::get()
{
	if (full) { full = false; return buffer; }
	char ch;
	cin >> ch;
	switch (ch) {
	case quit:
	case let:	
	case sq:
	case hatvany:
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case ';':
	case '=':


		return Token(ch);

		
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	{	cin.unget();
	double val;
	cin >> val;
	return Token(number, val);
	}

	break;
	default:
		if (isalpha(ch)) {
			string egyeb;
			egyeb = egyeb + ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch=='_')) egyeb += ch;
			cin.putback(ch);
			if (egyeb == "#") return Token(let);
			if (egyeb == "quit") return Token(quit);
			
		
		return Token(name, egyeb); // the return value must be declared in the end of the block - Adam error[2]

	}
		
	error("Bad token");
}
		
		return 0;	
}

//observe the buffer

void Token_stream::ignore(char c)
{
	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch;
	while (cin >> ch)
		if (ch == c) return;
}

struct Variable {
	string name;
	double value;
	Variable(string n, double v) :name(n), value(v) { }
};

//Create an empty Variable type vector to get values with a for loop and another for loop for set values

vector<Variable> var_names;

double get_value(string s)
{
	for (int i = 0; i < var_names.size(); ++i)
		if (var_names[i].name == s) return var_names[i].value;
	error("get: undefined name ", s);

	return 0; //return value missed
}

void set_value(string s, double d)
{
	for (int i = 0; i <= var_names.size(); ++i)
		if (var_names[i].name == s) {
			var_names[i].value = d;
			
		}
	error("set: undefined name ", s);
}

bool is_declared(string s)
{
	for (int i = 0; i < var_names.size(); ++i)
		if (var_names[i].name == s) return true;
	return false;
}

Token_stream ts;

double expression();

//get the numbers

double primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{	double d = expression();
	t = ts.get();
	if (t.kind != ')') error("')' expected");
	return d; // missed the return value - Adam error[3]
	}
	
	case '-':
		return -primary();
		
	case number:

		return t.value;
		
	case name:
		return get_value(t.name);

	case sq:
        {
            double d = primary();

            if (d < 0)
            	{ error("It's a negative number");

        		}

            return sqrt(d);
        }

	
		// for wrong data
	default:
		error("primary expected");
		
	}

		return 0;
	
}
	//power
double hatvanyozas(double hatvanyalap, double kitevo)
{
    int szam = narrow_cast<int>(kitevo);

    double n = 1;
    double b;

    if (kitevo < 0) {
        b = 1 / hatvanyalap;
        szam *= -1;
    } else
        b =hatvanyalap;

    for (int i = 0; i < szam; ++i)
        n *= b;

    return n;
}
	//define the power symbol
double hatvanyjel()
{
    double left = primary();
    while(true) {
        Token t = ts.get();

        if(t.kind=='^'){
        	return hatvanyozas(left, primary());
        }

        else{
        	 ts.unget(t);
             return left;
        }

    }
}


	// multiply and divide
double term()
{
	double left = hatvanyjel();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '*':
			left *= hatvanyjel();
			break;
		case '/':
		{	double d = hatvanyjel();
		if (d == 0) error("divide by zero");
		left /= d;
		break;
		}
		default:
			ts.unget(t);
			return left;
		}
	}
}
	//add and deduction
double expression()
{
	double left = term();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}




	//declaration of statement
double declaration()
{
	Token t = ts.get();
	if (t.kind != 'a') error("name expected in declaration");
	string name = t.name;
	if (is_declared(name)) error(name, " declared twice");
	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", name);
	double d = expression();
	var_names.push_back(Variable(name, d));
	return d;
}

double statement()
{
	Token t = ts.get();
	switch (t.kind) {
	case let:
		return declaration();
		break;
	default:
		ts.unget(t);
		return expression();
	}
}
	//clean up
void clean_up_mess()
{
	ts.ignore(print);
}

const string prompt = "> ";
const string result = "= ";


//This is the calculation of the program.This will be call in main() function.
void calculate()
{

	 var_names.push_back(Variable("k", 1000));

	while (true) try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t = ts.get();
		if (t.kind == quit) return;
		ts.unget(t);
		cout << result << statement()<< endl;
	}
	catch (runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}
	//The entry point of the program
int main()

try {
	 
	calculate();
	return 0;
}

//error handling
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	char c;
	while (cin >> c && c != ';');
	return 1;
}
catch (...) {
	cerr << "exception\n";
	char c;
	while (cin >> c && c != ';');
	return 2;
}
