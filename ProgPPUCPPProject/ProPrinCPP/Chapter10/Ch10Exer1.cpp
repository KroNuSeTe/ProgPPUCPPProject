// Copyright by Javier Dueñas

//	Exercice 1 Chapter 10
//	Write a program that produces the sum of all the numbers in a file
//	of witespace-separated integers.

#include "../std_lib_facilities.h"

const string filename = "Ch10Exer1.txt";

int main()
{
	ifstream ist{ filename };
	if (!ist) error("Can't open input file", filename);
	int number{ 0 };
	int sum{ 0 };
	vector<int> numbers;
	cout << "The numbers in " << filename << " are: ";
	while (ist >> number)
	{
		cout << number << " ";
		sum += number;
	}
	ist.close();
	cout << "\n\nThe sum of numbers is: " << sum;
}