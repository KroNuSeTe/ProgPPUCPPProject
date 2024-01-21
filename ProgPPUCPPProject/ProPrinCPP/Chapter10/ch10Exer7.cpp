
// Revised by Javier Dueñas April 2023

// Chapter 10 - Exercise 7
// Make a version of the calculator from Chapter 7 that accepts Roman
// numerals rather than the usual Arabic ones, for example, XXI + CIV = CXXV.


#include "../std_lib_facilities.h"
#include <map>

vector<char> romanChars {
	'I', 'V', 'X', 'L', 'C', 'D', 'M',
		'i', 'v', 'x', 'l', 'c', 'd', 'm'
};

map<char, int> romanToIntVal{
	{ 'I', 1 }, { 'V', 5 }, { 'X', 10 }, { 'L', 50 }, { 'C', 100 }, { 'D', 500 }, { 'M', 1000 }
};

map<int, string> intToRomanVal{
	{1, "I"}, { 4,"IV" }, { 5,"V" }, { 9,"IX" }, { 10,"X" }, { 40,"XL" }, { 50,"L" },
	{ 90,"XC" }, { 100,"C" }, { 400,"CD" }, { 500,"D" }, { 900,"CM" }, { 1000,"M" }
};

int numDiv[] = { 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 };

struct Token {
	char kind = ' ';
	int value = 0;

	Token(char ch) :kind(ch) { }
	Token(char ch, int val) :kind(ch), value(val) { }
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

const char quit = 'q';		   // Quit token
const char print = ';';		   // Print token
const char number = '8';	   // Number token
const char help = 'h';

int romanToInt(string& romanString)
{
	// romanString to Uppercase
	transform(romanString.begin(), romanString.end(), romanString.begin(), ::toupper);
	// convert the string romanChars to a vector romanChars
	vector<char> romanChars(romanString.begin(), romanString.end());
	int result = 0;
	int len = romanChars.size();
	result = romanToIntVal.at(romanChars.at(len - 1));
	for (int i = len - 2; i >= 0; i--)
	{
		if (romanToIntVal.at(romanChars.at(i)) >= romanToIntVal.at(romanChars.at(i + 1)))
		{
			result += romanToIntVal.at(romanChars.at(i));
		}
		else
		{
			result -= romanToIntVal.at(romanChars.at(i));
		}
	}
	return result;
}

string IntToRoman(int dNum)
{
	string romanString;
	int len = end(numDiv) - begin(numDiv);
	while (dNum > 0)
	{
		int quotient = dNum / numDiv[len - 1];
		dNum = dNum % numDiv[len - 1];
		while (quotient--)
		{
			romanString += intToRomanVal.at(numDiv[len -1]);
		}
		len--;
	}
	return romanString;
}

bool isARomanChar(char romChar)
{
	for (char rchar : romanChars)
	{
		if (rchar == romChar)
		{
			return true;
		}
	}
	return false;
}

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
			return Token(ch);	// Returns a character token.
		case '\n':
			return Token(print);
		default:
		{
			if (isalpha(ch)) {  // isalpha is a <cctype> function that Checks that a character is an alphabetic letter
				string s;		//adds the first character to the string
				s += ch;
				if (isARomanChar(ch))
				{
					while (cin.get(ch) && isARomanChar(ch))
					{
						s += ch;
					}
					cin.unget();
					int val = romanToInt(s);
					return Token(number, val);
				}
				else
				{		
					while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_')) s += ch; // this bucle creates the string
					cin.unget(); // returns the last character read in the bucle to the buffer

					if (s == "exit" || s == "quit") return Token(quit);
					if (s == "help") return Token(help);    // prints help
				}
			}
			error("Bad token");
		}
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

void helpPrint() {
	cout << "-----------------------------------\n";
	cout << "------Help of Roman Calculator-----\n";
	cout << "----------by Javier Dueñas---------\n";
	cout << "-----------------------------------\n";
	cout << "It allows you to perform operations\n";
	cout << "with Roman Numbers\n";
	cout << "(I To MMMCMXCIX('3999')), such as\n";
	cout << "addition, subtraction, multiplica- \n";
	cout << "tion and division.\n\n";
	cout << "Example: 'MDXII + MLII'  = MMDLXIV\n";
	cout << "         'm*III-ix'  = MMCMXCI\n";
	cout << "         'x*V/ii'   = XXV\n\n";
	cout << "Other Commands:\n";
	cout << "'help' -- prints this help\n";
	cout << "';' to Reset\n";
	cout << "'quit' or 'exit' -- Exit program\n\n";
}

Token_stream ts;

int expression(); // primary() can call expression()

// Parentheses, + and - sign, numbers and names.
int primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{
		int d = expression();
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
	default:
		error("primary expected");
	}
}

// Multiply (*), Divide (/), Module operator(%)
int term()
{
	int left = primary();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '*':
			left *= primary();
			break;
		case '/':
		{
			int d = primary();
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
int expression()
{
	int left = term();
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

int statement()
{
	Token t = ts.get();
	switch (t.kind) {
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
		int number = statement();
		string romanString = IntToRoman(number);
		cout << result << romanString << endl;
	}
	catch (runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

int main()
{
	try {
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
}

