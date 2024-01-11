// Copyright by Javier Dueñas

//	Exercice 3 Chapter 10
//	Write a program that reads the data from raw_temps.txt
//	created in exercise 2 into a vector and then calculates
//	the mean and median temperatures in your data set. 
//	Call this program temp_stats.cpp

#include "../std_lib_facilities.h"

const string filename = "raw_temps.txt";

int main()
{
	ifstream ist{ filename };
	if (!ist) error("Can't open input file ", filename);

	vector<double> temperatures;
	char char1{}, char2{}, char3{};
	int hourValue{ 0 };
	double tempValue{ 0.0 };
	while (ist >> char1 >> hourValue >> char2 >> tempValue >> char3)
	{
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