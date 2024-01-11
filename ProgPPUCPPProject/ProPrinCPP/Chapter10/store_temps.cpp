// Copyright by Javier Dueñas

//	Exercice 2 Chapter 10
//	Write a program that creates a file of data in
//	the form of the temperature Reading type defined in $10.5. 
//	For testing, fill the file with at least 50 "temperature readings."
//	Call this program store_temps.cpp and the file it creates raw_temps.txt.

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
		int MinusTemp = rand() % 2;
		double randomTemp = 0;
		if (MinusTemp == 1) 
		{
			int randomfloatMultp = rand() % 21;
			randomTemp = double(rand()) / double((RAND_MAX)) - randomfloatMultp;
		}
		else
		{
			int randomfloatMultp = rand() % 51;
			randomTemp = double(rand()) / double((RAND_MAX)) + randomfloatMultp;
		}
		ost << "(" << randomHour << "," << randomTemp << ")" << "\n";
	}

	ost.close();

}