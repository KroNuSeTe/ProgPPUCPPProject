#include <iostream>

using namespace std;

double ctok(double c) //Converts Celsius to Kelvin
{
	double k = c + 273.15;
	return k;
}

int main()
{
	double c = 0; //declare input variable
	cout <<"\nInsert a temperature in Celsius: ";
	cin >> c; //retrieve temperature to input variable
	double k = ctok(c); //convert temperature
	if (k < -273.15) {
		cout <<"\nThe temperature u Insert is bellow the Absolute zero.";
	}
	else {
		cout <<"\n"<<c<<" Celsius in Kelvin is: " << k << '/n'; //print out temperature
	}
}