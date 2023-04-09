#include <iostream>
#include <vector>

using namespace std;

vector<int> FibonacciCalc(int numAmount) {
	vector<int> FibonacciSeries;
	for (int i = 0; i < numAmount; ++i) {
		if (i > 1) {
			FibonacciSeries.push_back(FibonacciSeries[i - 2] + FibonacciSeries[i - 1]);
		}
		else {
			FibonacciSeries.push_back(1);
		}
	}
	return FibonacciSeries;
}

vector<int> FibonacciTotalIntCalc() {
	vector<int> FibonacciSeries;
	int sumFiboInt = 0;
	int counter = 0;
	bool finalLoop = true;
	while (finalLoop) {
		if (counter > 1) {
			sumFiboInt = FibonacciSeries[counter - 2] + FibonacciSeries[counter - 1];
			if (sumFiboInt > 2147445) {
				finalLoop = false;
			}
			else {
				FibonacciSeries.push_back(sumFiboInt);
			}
		}
		else {
			FibonacciSeries.push_back(1);
		}
		++counter;
	}
	return FibonacciSeries;
}

int main()
{
	int numbersAmount;
	vector<int> FibonacciSeries;
	cout << "\nInsert how much numbers of Fibonacci series: ";
	cin >> numbersAmount;
	FibonacciSeries = FibonacciCalc(numbersAmount);
	cout << "\n\nThis are the Fibonacci series numbers u choose:\n";
	for (int temp : FibonacciSeries) {
		cout << temp << " ";
	}
	
	vector<int> FibonacciIntAll = FibonacciTotalIntCalc();
	cout << "\n\nThis are all Integer Fibonacci series numbers \n";
	for (int temp : FibonacciIntAll) {
		cout << temp << " ";
	}

	return 0;
}