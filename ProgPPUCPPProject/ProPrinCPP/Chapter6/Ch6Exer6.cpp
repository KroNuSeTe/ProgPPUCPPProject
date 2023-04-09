
#include "./std_lib_facilities.h"

using namespace std;


string Verb(string word);
string Noun(string word);
string Conjunction(string word);
//string Sentence(string word);


string Verb(string word){
	string value = Conjunction(word);
	if (word == "rules") {
		value += " " + word;
		return value;
	}
	else if (word == "fly") {
		value += " " + word;
		return value;
	}
	else if (word == "swim") {
		value += " " + word;
		return value;
	}
	return word;
}

string Noun(string word) {
	string value = Verb(word);
	if (word=="birds"){
		value += " " + word;
		return value;
	}
	else if (word == "fish") {
		value += " " + word;
		return value;
	}
	else if (word == "C++") {
		value += " " + word;
		return value;
	}
	return word;
}

string Conjunction(string word) {
	string value = Noun(word);
	if (word == "and") {
		value += " " + word;
		return value;
	}
	else if (word == "or") {
		value += " " + word;
		return value;
	}
	else if (word == "but") {
		value += " " + word;
		return value;
	}

	return word;
}

//string Sentence(string word) {
//	string value = Noun(word);
//	
//}

int main(){
	try {
		cout << "Insert a sentence ('x' to exit): ";
		string sentence;
		string value;
		string sentString;
		while (getline(cin, sentence)) {
			stringstream streamValue(sentence);
			if (sentence == "x") return 0;
			int counter = 0;
			while (getline(streamValue, value, ' ')) {
				sentString += Noun(value);
				counter++;
				cout << counter;
			}
			cout << sentString;
			if (sentence[sentence.size() - 1] == '.' && sentence[sentence.size() - 2] != ' ') {
				cout << "\nOK";
			}
			else {
				cout << "\nnot OK.";
			}
			cout << "\nInsert a sentence ('x' to exit): ";
		}
	}
	catch (exception& e) {
		cerr << e.what() << endl;
		keep_window_open("~1");
		return 1;
	}
	catch (...) {
		cerr << "exception \n";
		keep_window_open("~2");
		return 2;
	}
}