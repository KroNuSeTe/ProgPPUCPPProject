#include <iostream>
#include <vector>

using namespace std;

int main()
{
	try {
		int numAmount = 0;
		vector<double> numbVector;
		double sumNumbers = 0;
		vector<double> numDifNumbers;
		cout << "Please enter the number of values you want to sum: ";
		cin >> numAmount;
		cout << "\nPlease enter some doubles (press '|' to stop): \n";
		double temp;
		while (cin >> temp) {
			numbVector.push_back(temp);
		}
		//Control Exception with code
		if (numAmount <= numbVector.size()) {
			cout << "The sum of the first " << numAmount << " numbers (";
			for (int i = 0; i < numAmount; ++i) {
				if (i != numAmount - 1) {
					cout << numbVector[i] << " ";
				}
				else {
					cout << numbVector[i];
				}
				sumNumbers = sumNumbers + numbVector[i];
			}
			cout << ") is " << sumNumbers << ".\n";
			for (int i = 0; i < numbVector.size(); ++i) {
				if (i == 0) {
					numDifNumbers.push_back(numbVector[i]);
				}
				else {
					numDifNumbers.push_back(numbVector[i] - numbVector[i - 1]);
				}
			}
			cout << "\nThe original Vector is:";
			for (double temp : numbVector) {
				cout << " " << temp;
			}
			cout << "\nThe diferences Vector is:";
			for (double temp : numDifNumbers) {
				cout << " " << temp;
			}
		}
		else {
			cout << "\nNo has introducido los valores suficientes para realizar la suma.";
		}




		return 0;
	}
	catch (exception& e) {
		cerr << "\nerror: " << e.what() << '\n';
		return 1;
	}
	catch (...) {
		cerr << "\nOops: unknown exception!\n";
		return 2;
	}

}