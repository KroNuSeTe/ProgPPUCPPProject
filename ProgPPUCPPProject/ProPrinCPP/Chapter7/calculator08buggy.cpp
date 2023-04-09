
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

Token Token_stream::get()
{
	if (full) { full = false; return buffer; }
	char ch;
	cin >> ch;	// Reads a character, to compare
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
			if (s == "pow" || s== "p") return Token(power_token);			// Pow

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
	Variable(bool c, string n, double v): constant(c), name(n), value(v) { }
};

vector<Variable> names;

double get_value(string s)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return names[i].value;
	error("get: undefined name ", s);
}

void set_value(string s, double d)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) {
			names[i].value = d;
			return;
		}
	error("set: undefined name ", s);
}

bool is_declared(string s)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return true;
	return false;
}

int search_variable(string s) {
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return i;
}

double define_name(bool cons, string var, double val)
{
	if (is_declared(var)) error(var, "declared twice");
	names.push_back(Variable{ cons, var, val });
	return val;
}
// ---------------------------------------------------------


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
		return get_value(t.name);
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
	Token t = ts.get();
	if (t.kind != 'a') error("name expected in declaration");
	string name = t.name;
	if (isConstVariable) error(name, "cant change a const variable");
	if (is_declared(name)) cout << name << " declared twice\n";
	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", name);
	double d = expression();
	if (is_declared(name)) {
		int localizedName = search_variable(name);
		names[localizedName].value = d;
		return d;
	}
	else {
		names.push_back(Variable(isConstVariable, name, d));
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
	// predefine names:
	define_name(true, "pi", 3.1415926535);
	define_name(true, "e", 2.7182818284);
	define_name(true, "k", 1000);

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
