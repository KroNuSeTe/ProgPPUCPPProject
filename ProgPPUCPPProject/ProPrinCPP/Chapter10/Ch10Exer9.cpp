// Copyright by Javier Dueñas

// Chapter 10 - Exercise 9
// Write a program that takes files containing sorted 
// whitespace-separated words and merges them, preserving order.

#include "../std_lib_facilities.h"

int main()
{
	try {
		cout << "This program concatenate 2 files in one.\n";
		// Open first file for input
		cout << "Insert the first file name: ";
		string firstFilename;
		cin >> firstFilename;
		ifstream ifsFirst{ firstFilename };
		if (!ifsFirst) error("can´t open first input file", firstFilename);
		ifsFirst.exceptions(ifsFirst.exceptions() | ios_base::badbit);	// throw for bad()

		// Open second file for input
		string secondFilename;
		cout << "\nInsert the second file name: ";
		cin >> secondFilename;
		ifstream ifsSecond{ secondFilename };
		if (!ifsSecond) error("can´t open first input file", firstFilename);
		ifsSecond.exceptions(ifsSecond.exceptions() | ios_base::badbit);	// throw for bad()

		// Open result file for output
		string resultFilename;
		cout << "\nInsert the result file name: ";
		cin >> resultFilename;
		ofstream ofsResult{ resultFilename };
		if (!ofsResult) error("can´t open output file", resultFilename);

		// Reading the files, and save in a vector.
		vector<string> fileData;
		string value;
		while (ifsFirst >> value)
		{
			fileData.push_back(value);
		}
		while (ifsSecond >> value)
		{
			fileData.push_back(value);
		}
		ifsFirst.close();
		ifsSecond.close();

		// Sorting the vector
		sort(fileData.begin(), fileData.end());

		// Writing the result file
		for (string word : fileData)
		{
			ofsResult << word << " ";
		}

		ofsResult.close();

		cout << "\n Files concatenated.";
	}
	catch (runtime_error e) {
		cout << e.what() << endl;
		keep_window_open();
	}
	catch (...) {
		cout << "Exiting" << endl;
		keep_window_open();
	}
}