
/*
	calculator08buggy.cpp

	Helpful comments removed.

	We have inserted 3 bugs that the compiler will catch and 3 that it won't.
*/

#include "../std_lib_facilities.h"

struct Token {
	char kind = ' ';
	double value = 0.f;
	string name = "";
	Token(char ch) :kind(ch) { }
	Token(char ch, double val) :kind(ch), value(val) { }
	Token(char ch, string nam) :kind(ch), name(nam) { }
	Token(string nam) :name(nam) { }
};

class Token_stream {
	bool full;	// get token already?
	Token buffer;	// store tokens
public:
	Token_stream() :full(0), buffer(0) { }; // Constructor
	Token get();	// gets a token a define the type of token
	void unget(Token t) { buffer = t; full = true; };  // istream function, returns to the buffer the las character extracted
	void ignore(char); // Ignore a token, and dont buffer it
};


const char let = 'L';		   // To create variables, ex: x=12;
const char quit = 'q';		   // Quit token
const char print = ';';		   // Print token
const char number = '8';	   // Number token
const char const_token = 'c';  // Const token, ex: const x=13.4;
const char name = 'a';	       // Name token
const char square_token = 's'; // Square root token
const char power_token = 'p';  // Power token
const char help = 'h';

Token Token_stream::get()
{
	if (full) { full = false; return buffer; }
	char ch = ' ';


	while (isspace(ch) && ch != '\n') {
		ch = cin.get();	// Ignore spaces and allow endl '\n'
	}

	switch (ch) {
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case ';':
	case '=':
	case ',':
		return Token(ch); // Returns a character token.
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
	{	cin.unget();			// Returns the character to the buffer.
	double val;
	cin >> val;					// And reads all the number.
	return Token(number, val);  // Returns a numeric token
	}
	case '#':
		return Token(let);  // isalpha dont recognice it as an alphabetic character
	case '\n':
		return Token(print);
	default:
		if (isalpha(ch)) {  // isalpha is a <cctype> function that Checks that a character is an alphabetic letter
			string s;
			s += ch;		//adds the first character to the string
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_')) s += ch; // this bucle creates the string
			cin.unget(); // returns the last character read in the bucle to the buffer
			if (s == "L" || s == "let") return Token(let); // Checks if the string is a variable creation token
			if (s == "exit" || s == "quit") return Token(quit);
			if (s == "const") return Token(const_token);        // Checks if is a const
			if (s == "a") return Token(name);					// Checks if is a name
			if (s == "sqrt" || s == "sq") return Token(square_token);		// Square
			if (s == "pow" || s == "p") return Token(power_token);			// Pow
			if (s == "help") return Token(help);    // prints help

			return Token(name, s);
		}
		error("Bad token");
	}
}


// Discard tokens until gets a char c
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

// Variables, Get, Set and Define a name if is not declared
struct Variable {
	bool constant;
	string name;
	double value;
	Variable(bool c, string n, double v) : constant(c), name(n), value(v) { }
};

class Symbol_table {

public:
	vector<Variable> var_table;
	double get_value(string name);
	void set_value(string name, double value);
	bool is_declared(string name);
	bool is_constantVar(string name);
	int search_variable(string s);
	double define_name(bool constant, string name, double value);
};

Symbol_table names;

double Symbol_table::get_value(string s)
{
	for (int i = 0; i < names.var_table.size(); ++i)
		if (names.var_table[i].name == s) return names.var_table[i].value;
	error("get: undefined name ", s);
}

void Symbol_table::set_value(string s, double d)
{
	for (int i = 0; i < names.var_table.size(); ++i)
		if (names.var_table[i].name == s) {
			names.var_table[i].value = d;
			return;
		}
	error("set: undefined name ", s);
}

bool Symbol_table::is_declared(string s)
{
	for (int i = 0; i < names.var_table.size(); ++i)
		if (names.var_table[i].name == s) return true;
	return false;
}

bool Symbol_table::is_constantVar(string s)
{
	for (int i = 0; i < names.var_table.size(); ++i)
		if (names.var_table[i].name == s) {
			return names.var_table[i].constant;
		}
	return false;
}

int Symbol_table::search_variable(string s) {
	for (int i = 0; i < names.var_table.size(); ++i)
		if (names.var_table[i].name == s) return i;
}

double Symbol_table::define_name(bool cons, string var, double val)
{
	if (is_declared(var)) error(var, "declared twice");
	names.var_table.push_back(Variable{ cons, var, val });
	return val;
}
// ---------------------------------------------------------

void helpPrint() {
	cout << "-----------------------------------\n";
	cout << "---------Help of Calculator--------\n";
	cout << "----------by Javier Dueñas---------\n";
	cout << "-----------------------------------\n";
	cout << "It allows you to perform operations\n";
	cout << "such as addition, subtraction, mul-\n";
	cout << "tiplication, division, modulo of   \n";
	cout << "division, square root, power of n, \n";
	cout << "assign variables or constants, and \n";
	cout << "also accepts parentheses.          \n";
	cout << "use ';' to reset\n";

	//--- Code generated by chatGPT ------------------------------------------

	int val1 = 10;
	int val2 = 5;
	int x = 12;
	const int y = 6;

	cout << "Operation\t\tResult" << endl;
	cout << val1 << "+" << val2 << " Addition\t\t" << val1 + val2 << endl;
	cout << val1 << "-" << val2 << " Subtraction\t\t" << val1 - val2 << endl;
	cout << val1 << "*" << val2 << " Multiplication\t" << val1 * val2 << endl;
	cout << val1 << "/" << val2 << " Division\t\t" << val1 / val2 << endl;
	cout << val1 << "%" << val2 << " Modulo\t\t" << val1 % val2 << endl;
	cout << "sqrt(" << val1 << ") Square Root\t\t" << sqrt(val1) << endl;
	cout << "pow(" << val1 << "," << val2 << ") Power of " << val2 << "\t" << pow(val1, val2) << endl;
	cout << "# x=" << x << " Assign variables\t" << endl;
	cout << "# const y=" << y << " Assign constants\t" << endl;
	cout << val1 << "*(" << val1 << "+" << val2 << ") Parentheses allowed\t" << val1 * (val1 + val2) << endl;

	// ------------------------------------------------------------
}



Token_stream ts;

double expression(); // primary() can call expression()

// Parentheses, + and - sign, numbers and names.
double primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{
		double d = expression();
		t = ts.get();
		if (t.kind != ')') error("')' expected");
		return d;
	}
	case '-':
		return -primary();
	case '+':
		return primary();
	case number:
		return t.value;
	case name:
		return names.get_value(t.name);
	default:
		error("primary expected");
	}
}

// Multiply (*), Divide (/), Module operator(%)
double term()
{
	double left = primary();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '*':
			left *= primary();
			break;
		case '/':
		{
			double d = primary();
			if (d == 0) error("divide by zero");
			left /= d;
			break;
		}
		case '%':
		{
			int i1 = narrow_cast<int>(left);
			int i2 = narrow_cast<int>(primary());
			if (i2 == 0) error("%:divide by zero");
			left = i1 % i2;
			break;
		}
		default:
			ts.unget(t);
			return left;
		}
	}
}

// Add and Subtract
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

// Variable Declaration
double declaration()
{
	bool isConstVariable = false;
	Token c = ts.get();
	if (c.kind == 'c') {
		isConstVariable = true;
	}
	else {
		ts.unget(c);
	}
	Token t = ts.get();
	if (t.kind != 'a') error("name expected in declaration");
	string name = t.name;
	if (names.is_declared(name)) cout << name << " declared twice\n";
	if (names.is_declared(name) && names.is_constantVar(name)) error(name, " cant change a const variable");
	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", name);
	double d = expression();
	if (names.is_declared(name)) {
		int localizedName = names.search_variable(name);
		names.var_table[localizedName].value = d;
		return d;
	}
	else {
		names.var_table.push_back(Variable(isConstVariable, name, d));
		return d;
	}

}

double squareUser() {
	double d = expression();
	return sqrt(d);
}

double powerUser() {
	Token t = ts.get();
	if (t.kind != '(') error("'(' expected");
	double base = expression();
	t = ts.get();
	if (t.kind != ',') error("',' expected");
	int power = narrow_cast<int>(expression());
	t = ts.get();
	if (t.kind != ')') error("')' expected");
	return pow(base, power);
}

double statement()
{
	Token t = ts.get();
	switch (t.kind) {
	case let:
		return declaration();
	case square_token:
		return squareUser();
	case power_token:
		return powerUser();
	case help:
		helpPrint();
		return 0;
	default:
		ts.unget(t);
		return expression();
	}
}

// Ignore tokens until last print (;)
void clean_up_mess()
{
	ts.ignore(print);
}


const string prompt = "> ";
const string result = "= ";

void calculate()
{
	while (true) try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t = ts.get();
		if (t.kind == quit) return;
		ts.unget(t);
		cout << result << statement() << endl;
	}
	catch (runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

int main()

try {

	// predefine constant names:
	names.define_name(true, "pi", 3.1415926535);
	names.define_name(true, "e", 2.7182818284);
	names.define_name(true, "k", 1000);
	helpPrint(); // prints help at start
	calculate();
	return 0;
}
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
