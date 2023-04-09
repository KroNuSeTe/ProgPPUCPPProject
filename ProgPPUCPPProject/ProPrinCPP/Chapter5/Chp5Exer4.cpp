#include <iostream>

using namespace std;

void ctok(double c) //Converts Celsius to Kelvin
{
	double k = c + 273.15;
	if (k < -273.15) {
		cout << "\nThe temperature u Insert is bellow the Absolute zero.";
	}
	else {
		cout << "\n" << c << " Celsius in Kelvin is: " << k << '/n'; //print out temperature
	}
}

void ktoc(double k) //Converts Kelvin to Celsius
{
	double c = k - 273.15;
	if (k < -273.15) {
		cout << "\nThe temperature u Insert is bellow the Absolute zero.";
	}
	else {
		cout << "\n" << k << " Kelvin in Celsius is: " << c << '/n'; //print out temperature
	}
}

int main()
{
	cout << "\nWhat u want to convert? Celsius or Kelvin? (Insert C or K): ";
	char chooseCoK;
	while (cin >> chooseCoK) {
		if (chooseCoK == 'c' || chooseCoK == 'C' || chooseCoK == 'k' || chooseCoK == 'K') {
			break;
		}
		else {
			cout << "\n(Insert C or K): ";
		}
	}
	
	double c = 0; //declare input variable
	cout << "\nInsert the temperature: ";
	cin >> c; //retrieve temperature to input variable
	if (chooseCoK == 'c' || chooseCoK == 'C') {
		ctok(c); //convert temperature
	}
	else if (chooseCoK == 'k' || chooseCoK == 'K') {
		ktoc(c);
	}
}