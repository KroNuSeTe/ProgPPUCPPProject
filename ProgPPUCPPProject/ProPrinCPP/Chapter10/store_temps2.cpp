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

struct Reading {
	int hour;
	double temperature;
};

const string filename = "raw_temps.txt";

int main()
{
	srand(time(NULL));
	ofstream ost{ filename };
	if (!ost) error("Can't open output file ", filename);

	// 50 Random Temperature in range -20 / 50
	for (int i = 0; i < 50; i++)
	{
		int randomHour = rand() % 24;
		int minusTemp = rand() % 2;		// 0 - Neg | 1 - Pos
		int celsOrFahr = rand() % 2;	// 0 - Celsius | 1 - Fahrenheit
		double randomTemp = 0;
		if (minusTemp == 1)
		{
			int randomfloatMultp = rand() % 21;
			randomTemp = double(rand()) / double((RAND_MAX)) - randomfloatMultp;
		}
		else
		{
			int randomfloatMultp = rand() % 51;
			randomTemp = double(rand()) / double((RAND_MAX)) + randomfloatMultp;
		}
		char tempType{};
		if (celsOrFahr)
		{
			tempType = 'c';
		}
		else
		{
			// Alt + 0176 = °
			// Fahrenheit(°F) = (Temperature in degrees Celsius(°C)*9/5) + 32
			randomTemp = (randomTemp * 9 / 5) + 32;
			tempType = 'f';
		}
		ost << "(" << randomHour << "," << randomTemp << tempType << ")" << "\n";
	}

	ost.close();

}