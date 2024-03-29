// Copyright by Javier Due�as & Bjarne Stroustrup

// Chapter 10 Exercise 5.
// Write the function print_year() mentioned in $10.11.2

#include "../std_lib_facilities.h"

const int not_a_reading = -7777;
const int not_a_month = -1;
constexpr int implausible_min = -200;
constexpr int implausible_max = 200;

struct Day 
{
	vector<double> hour {vector<double>(24, not_a_reading)};
};

struct Month 
{
	int month{ not_a_month };
	vector<Day> day{32};
};

struct Year
{
	int year;
	vector<Month> month{12};
};

struct Reading 
{
	int day;
	int hour;
	double temperature;
};

vector<string> month_input_tbl = {
	"jan", "feb", "mar", "apr", "may", "jun",
	"jul", "aug", "sep", "oct", "nov", "dec"
};

vector<string> month_print_tbl = {
	"January", "February", "March", "April", "May", "June",
	"July", "August", "September", "October", "November", "December"
};

// is s the name of a month? if so return it's index [0:11] otherwise -1
int month_to_int(string s)
{
	for (int i = 0; i < 12; ++i)
	{
		if (month_input_tbl[i] == s) return i;
	}
	return -1;
}

// months [0:11]
string int_to_mont(int i)
{
	if (i < 0 || 12 <= i) error("bad month index");
	return month_print_tbl[i];
}

// a rough test
bool is_valid(const Reading& r)
{
	if (r.day < 1 || 31 < r.day) return false;
	if (r.hour < 0 || 23 < r.hour) return false;
	if (r.temperature < implausible_min || implausible_max < r.temperature) return false;

	return true;
}

void end_of_loop(istream& ist, char term, const string& message)
{
	if (ist.fail())			// use term as terminator and/or separator
	{
		ist.clear();
		char ch;
		if (ist >> ch && ch == term) return;		// all is fine
		error(message);
	}
}

// read a temperature reading from is into r
// format: ( 3 4 9.7 )
// check format, but don't bother with data validity
istream& operator>>(istream& is, Reading& r)
{
	char ch1;
	if (is >> ch1 && ch1 != '(')		// could it be a Reading?
	{
		is.unget();
		is.clear(ios_base::failbit);
		return is;
	}

	char ch2;
	int d;
	int h;
	double t;
	is >> d >> h >> t >> ch2;
	if (!is || ch2 != ')') error("bad reading");	// messed-up reading
	r.day = d;
	r.hour = h;
	r.temperature = t;
	return is;
}

// read a month from is into m
// format: { month feb ...}
istream& operator>>(istream& is, Month& m)
{
	char ch = 0;
	if (is >> ch && ch != '{')
	{
		is.unget();
		is.clear(ios_base::failbit);		// we failed to read a Month	
		return is;
	}

	string month_marker;
	string mm;
	is >> month_marker >> mm;

	if (!is || month_marker != "month")
	{
		error("bad start of month");
	}
	m.month = month_to_int(mm);

	int duplicates = 0;
	int invalids = 0;
	for (Reading r; is>>r;)
	{
		if (is_valid(r))
		{
			if (m.day[r.day].hour[r.hour] != not_a_reading)	++duplicates;
			m.day[r.day].hour[r.hour] = r.temperature; 
		}
		else
		{
			++invalids;
		}
	}
	if (invalids) error("invalid readings in month", invalids);
	if (duplicates) error("duplicate readings in month", duplicates);
	end_of_loop(is, '}', "bad end of month");
	return is;
}

// read a year from is into y
// format: { year 1972...}
istream& operator>>(istream& is, Year& y)
{
	char ch;
	is >> ch;
	if (ch != '{')
	{
		is.unget();
		is.clear(ios::failbit);
		return is;
	}

	string year_marker;
	int yy;
	is >> year_marker >> yy;
	if (!is || year_marker != "year") error("bad start of year");
	y.year = yy;

	while (true)
	{
		Month m;			// get a clean m each time around
		if (!(is >> m)) break;
		y.month[m.month] = m;
	}

	end_of_loop(is, '}', "bad end of year");
	return is;
}

ostream& operator<<(ostream& os, Year& y)
{
	os << y.year;
	return os;
}

void print_year(ostream& of, Year& y)
{
	of << y << endl;
}

int main()
{
	try {
		//open an input file:
		cout << "Please enter input file name\n";
		string iname;
		cin >> iname;
		ifstream ifs{ iname };
		if (!ifs) error("can't open input file", iname);

		ifs.exceptions(ifs.exceptions() | ios_base::badbit);	// throw for bad()

		// open an output file
		cout << "Please enter output file name\n";
		string oname;
		cin >> oname;
		ofstream ofs{ oname };
		if (!ofs) error("can't open output file", oname);

		// read an arbitrary number of years:
		vector<Year> ys;
		while (true)
		{
			Year y;			// get a freshly initialized Year each time around
			if (!(ifs >> y)) break;
			ys.push_back(y);
		}
		cout << "read" << ys.size() << "years of readings\n";
		for (Year& y : ys) print_year(ofs, y);
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