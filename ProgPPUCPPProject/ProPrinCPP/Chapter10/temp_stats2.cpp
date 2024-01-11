// Copyright by Javier Dueñas

//	Exercice 4 Chapter 10
//	Modify the store_temps.cpp program from exercise 2 to include
//	a temperature suffix c for Celsius or f for Fahrenheit temperatures.
//	Then modify the temp_stats.cpp program to test each temperature,
//	converting the Celsius readings to Fahrenheit before putting them
//	into the vector.
// 
//	Duplicate and rename the files to store_temps2 and temp_stats2
//	to keep the exercices.

#include "../std_lib_facilities.h"

const string filename = "raw_temps.txt";

int main()
{
	ifstream ist{ filename };
	if (!ist) error("Can't open input file ", filename);

	vector<double> temperatures;
	char char1{}, char2{}, char3{}, tempType{};
	int hourValue{ 0 };
	double tempValue{ 0.0 };
	while (ist >> char1 >> hourValue >> char2 >> tempValue >> tempType >> char3)
	{
		if (tempType == 'f')
		{
			// Fahrenheit to Celsius -- C = (F - 32) * (5 / 9)
			tempValue = (tempValue - 32.0) * (5.0 / 9.0);
		}
		temperatures.push_back(tempValue);
	}

	sort(temperatures.begin(), temperatures.end());
	double mean{ 0.0 };
	for (double temp : temperatures)
	{
		cout << temp << "\n";
		mean += temp;
	}

	// The mean is the average you're used to, where you add up
	// all the numbers and then divide by the number of numbers.
	mean = mean / temperatures.size();
	cout << "\n\nThe mean is:" << mean;
	// The median is the middle value in the list of numbers. 
	// To find the median, your numbers have to be listed in 
	// numberical order from smallest to largest.
	int medianPos = (temperatures.size() + 1) / 2;
	cout << "\nThe median is: " << temperatures[medianPos];
}