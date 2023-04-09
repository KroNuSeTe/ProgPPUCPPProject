#include <iostream>
#include <vector>

using namespace std;


const enum daysWeek{
	sun,
	mon,
	tue,
	wed,
	thu,
	fri,
	sat,
	exitGame,
	error
};

const vector<string> sunWords = { "Sunday", "sunday", "Sun", "sun" };
const vector<string> monWords = { "Monday", "monday", "mon", "Mon" };
const vector<string> tueWords = { "Tuesday", "tuesday", "Tue", "tue", "Tues", "tues", "Tu", "tu" };
const vector<string> wedWords = { "Wednesday", "wednesday", "Wed", "wed" };
const vector<string> thuWords = { "Thursday", "thursday", "Th", "th", "Thu", "thu", "Thur", "thur", "Thurs", "thurs" };
const vector<string> friWords = { "Friday", "friday", "Fri", "fri" };
const vector<string> satWords = { "Saturday", "saturnday", "Sat", "sat" };
const vector<string> exitWords = { "Exit", "exit", "|" };



daysWeek ChooseDay() {
	string userDay;
	while (cin >> userDay) {
		for (string temp : sunWords) {
			if (userDay == temp) {
				return sun;
			}
		}
		for (string temp : monWords) {
			if (userDay == temp) {
				return mon;
			}
		}
		for (string temp : tueWords) {
			if (userDay == temp) {
				return tue;
			}
		}
		for (string temp : wedWords) {
			if (userDay == temp) {
				return wed;
			}
		}
		for (string temp : thuWords) {
			if (userDay == temp) {
				return thu;
			}
		}
		for (string temp : friWords) {
			if (userDay == temp) {
				return fri;
			}
		}
		for (string temp : satWords) {
			if (userDay == temp) {
				return sat;
			}
		}
		for (string temp : exitWords) {
			if (userDay == temp) {
				return exitGame;
			}
		}

		return error;
	}
}

void SumValuesDay(vector<int> dayVector, string day) {
	int sumAllValues = 0;
	for (int temp : dayVector) {
		sumAllValues += temp;
	}
	cout << "\nThe sum of all the values on "<<day<<" is : "<<sumAllValues;
}

int main()
{
	int rejectedValues = 0;

	vector<int> sunValues;
	vector<int> monValues;
	vector<int> tueValues;
	vector<int> wedValues;
	vector<int> thuValues;
	vector<int> friValues;
	vector<int> satValues;

	bool canInput = true;

	cout << "\nInsert the Day and the Value (e: Friday 23) (Type 'Exit' to finish): ";

	while (canInput) {
		daysWeek userDay;
		userDay = ChooseDay();
		if (userDay == error) {
			cout<<"\nInsert a valid Day: ";
			++rejectedValues;
		} else if (userDay == exitGame) {
			canInput = false;
		}
		else {
			int valueDay = 0;
			while (cin >> valueDay) {
				switch (userDay){
				case sun:
					sunValues.push_back(valueDay);
					break;
				case mon:
					monValues.push_back(valueDay);
					break;
				case tue:
					tueValues.push_back(valueDay);
					break;
				case wed:
					wedValues.push_back(valueDay);
					break;
				case thu:
					thuValues.push_back(valueDay);
					break;
				case fri:
					friValues.push_back(valueDay);
					break;
				case sat:
					satValues.push_back(valueDay);
					break;
				default:
					cout << "default";
					break;
				}
				break;
			}
			
		}

	}
	
	SumValuesDay(sunValues, "Sunday");
	SumValuesDay(monValues, "Monday");
	SumValuesDay(tueValues, "Tuesday");
	SumValuesDay(wedValues, "Wednesday");
	SumValuesDay(thuValues, "Thursday");
	SumValuesDay(friValues, "Friday");
	SumValuesDay(satValues, "Saturday");

	cout << "\n\nThe number of rejected values is: " << rejectedValues;

	return 0;
}