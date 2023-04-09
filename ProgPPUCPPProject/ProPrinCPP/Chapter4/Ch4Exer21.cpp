#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool IsNameUsed(string name, vector<string> names) {
    for (string temp : names) {
        if (temp == name) {
            return true;
        }
    }
    return false;
}

vector<int> IsScoreSaved(string score, vector<string> scores) {
    vector<int> vectorReturn;
    for (int i = 0;i<scores.size();++i) {
        if (scores[i] == score) {
            vectorReturn.push_back(i);
        }
    }
    return vectorReturn;
}

string ScoreName(string name, vector<string>names, vector <string>scores) {
    for (int i = 0; i < names.size(); ++i) {
        if (names[i] == name) {
            return scores[i];
        }
    }
}

int main()
{
    vector<string> names;
    vector<string> scores;
    cout << "Insert Name and score (Noname 0 - End): ";
    string value;
    int counter = 0;
    string tempName;
    while (cin >> value) {
        if (counter == 1) {
            if (tempName == "Noname" && value == "0") {
                break;
            }
            else {
                if (IsNameUsed(tempName, names)) {
                    cout << "Name is in use.... insert other.\n";
                    counter = 0;
                }
                else {
                    names.push_back(tempName);
                    scores.push_back(value);
                    counter = 0;
                }
            }
        }
        else {
            tempName = value;
            counter++;
        }
    }
    for (int i = 0; i < names.size(); ++i) {
        cout << "\n" << names[i] << " - " << scores[i];
    }
    cout << "\nInsert a Score (Type 'Exit' to exit): ";
    string value2;
    string scoreFinal;
    while (cin >> value2) {
        if (value2 == "Exit") return 0;
        vector<int> scoresVector = IsScoreSaved(value2, scores);
        if (scoresVector.size() >= 1) {
            cout << "\nHay " << scoresVector.size() << " Usuarios con " << value2;
            for (int temp : scoresVector) {
                cout << "\n" << names[temp];
            }
            cout << "\nInsert a Score (Type 'Exit' to exit): ";
        }
        else {
            cout << "\nScore not found. Insert other Score (Type 'Exit' to exit): ";
        }
    }
}