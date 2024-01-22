#pragma once
// Copyright by Javier Dueñas

// Chapter 10 Exercise 6.

#include "../std_lib_facilities.h"
#include <map>

vector<char> roman_Chars {
	'I', 'V', 'X', 'L', 'C', 'D', 'M',
	'i', 'v', 'x', 'l', 'c', 'd', 'm'
};

map<char, int> intToRomanVal{
	{ 'I', 1 }, {'V', 5}, { 'X', 10 }, { 'L', 50 }, { 'C', 100 }, { 'D', 500 }, { 'M', 1000 }
};

class Roman_int
{
public:
	Roman_int();
	int as_int();
	void set_romanInt(int intRoman);
	void set_romanString(string strRoman);
	int get_romanInt() { return romanInt; }
	string get_romanString() { return romanString; }
	
private:
	string romanString;
	int romanInt{ 0 };
};

istream& operator>>(istream& is, Roman_int& r);

ostream& operator<<(ostream& os, Roman_int& r);

bool isARomanCharacter(char rNum);

int romanToInt(string& romanString);


