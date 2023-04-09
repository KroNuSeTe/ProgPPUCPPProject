#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	try {
		return 0;
	}
	catch (exception& e) {
		cerr << "error: " << e.what() << '\n';
		cin.ignore();
		return 1;
	}
	catch (...) {
		cerr << "Oops: unknown exception!\n";
		cin.ignore();
		return 2;
	}
}