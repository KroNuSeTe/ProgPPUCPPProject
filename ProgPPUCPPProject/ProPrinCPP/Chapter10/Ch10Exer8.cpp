// Copyright by Javier Dueñas

// Chapter 10 - Exercise 8
// Write a program that accepts two file names and produces
// a new file that is the contents of the first file followed 
// by the contents of the second, that is, the program 
// concatenates the two files.
// The format of the files is like Exercise 9, that contains
// whitespace-separated words.

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

		// Reading the files, and save in vectors.
		vector<string> firstFileData;
		vector<string> secondFileData;
		string value;
		while (ifsFirst >> value)
		{
			firstFileData.push_back(value);
		}
		while (ifsSecond >> value)
		{
			secondFileData.push_back(value);
		}
		ifsFirst.close();
		ifsSecond.close();

		// Writing the result file
		for (string word : firstFileData)
		{
			ofsResult << word << " ";
		}
		for (string word : secondFileData)
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