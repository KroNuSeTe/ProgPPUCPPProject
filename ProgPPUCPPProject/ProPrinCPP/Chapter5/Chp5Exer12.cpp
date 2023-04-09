#include <iostream>
#include <vector>
#include <string>


using namespace std;

bool PlayAgain() {
	char playAgain;
	cout << "U wanna play again? (Y/N): ";
	while (cin >> playAgain) {
		if (playAgain == 'N' || playAgain == 'n') {
			return false;
		}
		else if (playAgain == 'Y' || playAgain == 'y') {
			return true;
		}
	}
}

int main()
{
	srand(time(NULL)); // new seed from time
	cout << "\nWelcome to Bulls and Cows\n";

	// User insert the number
	int userGuessed;
	bool playAgain = true;
	bool firstTimePlayed = true;
	bool gameEnd = false;
	if (!firstTimePlayed) {
		playAgain = PlayAgain();

	}
	else {
		firstTimePlayed = false;
	}

	while (playAgain) {
		// CPU guess a random number from 0 to 6
		int randomNumber;
		randomNumber = rand() % 7;

		// CPU creates the vector with the number to guess
		vector<int> numberToGuess;
		
		for (int i = randomNumber; i <= randomNumber+3; ++i) {
			numberToGuess.push_back(i);
		}

		vector<string> numberToGuessSTR;
		// Convert the CPU Number to strings
		for (int i = 0; i < numberToGuess.size(); ++i) {
			numberToGuessSTR.push_back(to_string(numberToGuess[i]));
		}
		for (string temp : numberToGuessSTR) {
			cout << temp<<" ";
		}
		cout << "\nInsert ur Number of 4 numbers in a row (1234, 5678, 3456): ";
		while (cin >> userGuessed) {

			// Convert the number entered in a vertor to compare
			string valueUserString = to_string(userGuessed);
			if (valueUserString.size() == 3) {
				valueUserString.insert(0, "0");
			}
			cout<<valueUserString;
			vector<string> userNumber;
			for (int i = 0; i <= 3; ++i) {
				string value = valueUserString.substr(i, 1);
				userNumber.push_back(value);
			}

			int bull = 0;
			int cow = 0;
			for (int i = 0; i < numberToGuess.size(); ++i) {
				for (int j = 0; j < userNumber.size(); ++j) {
					if (i == j) {
						if (userNumber[j] == numberToGuessSTR[i]) {
							++bull;
						}
					}
					else if (userNumber[j] == numberToGuessSTR[i]) {
						++cow;
					}
				}
			}			
			cout << "\nYou have " << bull << " bulls and " << cow << " cows.\n";
			if (bull == 4) {
				cout << "\n\nCongratulations. U guess the number.\n";
				cout << "------------------------------------------\n";
				gameEnd = true;
				break;
			}
			else {
				cout << "\nInsert ur Number of 4 numbers in a row (1234, 5678, 3456): ";
			}
		}
		if (gameEnd) {
			playAgain = PlayAgain();
		}
	}

}