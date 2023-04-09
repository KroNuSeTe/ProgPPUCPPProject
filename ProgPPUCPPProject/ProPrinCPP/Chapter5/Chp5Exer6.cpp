#include <iostream>

using namespace std;

void ctof(double c) //Converts Celsius to Fahrenheit
{
	double f = 1.8f * c + 32;
	cout << "\n" << c << " Celsius in Fahrenheit is: " << f << '/n'; //print out temperature
}

void ftoc(double f) //Converts Fahrenheit to Celsius
{
	double c = (f-32)/1.8f;
	cout << "\n" << f << " Fahrenheit in Celsius is: " << c << '/n'; //print out temperature
}

int main()
{
	cout << "\nWhat u want to convert? Celsius or Fahrenheit? (Insert C or F): ";
	char chooseCoF;
	while (cin >> chooseCoF) {
		if (chooseCoF == 'c' || chooseCoF == 'C' || chooseCoF == 'f' || chooseCoF == 'F') {
			break;
		}
		else {
			cout << "\n(Insert C or F): ";
		}
	}

	double t = 0; //declare input variable
	cout << "\nInsert the temperature: ";
	cin >> t; //retrieve temperature to input variable
	if (chooseCoF == 'c' || chooseCoF == 'C') {
		ctof(t); //convert temperature
	}
	else if (chooseCoF == 'f' || chooseCoF == 'F') {
		ftoc(t);
	}
}