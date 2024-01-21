#include "Ch10Exer6.h"
// Copyright by Javier Dueñas & Bjarne Stroustrup

// Chapter 10 Exercise 6.
// Define a Roman_int class for holding Roman numerals (as ints)
// with a << and >>. Provide Roman_int with an as_int() member 
// that returns the int value, so that if r is a Roman_int, 
// we can write cout<<"Roman"<<r<<" equals"<<r.as_int()<<'\n';

// https://tutorialhorizon.com/algorithms/convert-roman-number-to-integer/
// Aproach:
// Iterate through given roman number from right to left (reverse).
// Initialize result = 0;
// Take one character at a time and check its corresponding numeral from the table and add it to the result.
// The only special case that needs to be considered is when the character at left has smaller value than
// the character at right. for example 'IX' for 9 or 'IV' for 4, in such cases subtract left character value 
// from the result. Except for this special case, in all other cases, all the pairs have
// left character value >= right character value

#include "Ch10Exer6.h"


Roman_int::Roman_int(){}

int Roman_int::as_int()
{
	return romanInt;
}

void Roman_int::set_romanInt(int intRoman)
{
	romanInt = intRoman;
}

void Roman_int::set_romanString(string strRoman)
{
	romanString = strRoman;
}

bool isARomanCharacter(char rnum)
{
	for (char rChar : roman_Chars)
	{
		if (rChar == rnum) return true;
	}
	return false;
}

int romanToInt(string& romanString)
{
	// romanString to Uppercase
	transform(romanString.begin(), romanString.end(), romanString.begin(), ::toupper);
	// convert the string romanChars to a vector romanChars
	vector<char> romanChars(romanString.begin(), romanString.end());
	int result = 0;
	int len = romanChars.size();
	result = intToRomanVal.at(romanChars.at(len - 1));
	for (int i = len - 2; i >= 0; i--)
	{
		if (intToRomanVal.at(romanChars.at(i)) >= intToRomanVal.at(romanChars.at(i + 1)))
		{
			result += intToRomanVal.at(romanChars.at(i));
		}
		else
		{
			result -= intToRomanVal.at(romanChars.at(i));
		}
	}
	return result;
}

istream& operator>>(istream& is, Roman_int& r)
{
	is.exceptions(is.exceptions() | ios_base::badbit);

	string charstring;
	char romanChar;
	while (is.get(romanChar) )
	{
		if (isARomanCharacter(romanChar))
		{
			charstring += romanChar;
		}
		else
		{
			is.putback(romanChar);
			is.clear(ios::failbit);
		}
	}

	int romanInt = romanToInt(charstring);
	r.set_romanInt(romanInt);
	r.set_romanString(charstring);
	return is;

}

ostream& operator<<(ostream& os, Roman_int& r)
{
	cout << r.get_romanString();
	return os;
}

int main()
{
	try {
		Roman_int r;
		cout << "Insert an Roman Number(I-MMMCMXCIX): ";
		cin >> r;
		cout << "Roman " << r << " equals " << r.as_int() << '\n';
	}
	catch (runtime_error e) {
		cout << e.what() << endl;
		keep_window_open();
	}
	catch (...) {
		cout << "Exiting" << endl;
		keep_window_open();
	}
}

