#include <iostream>
#include <vector>
#include <ctype.h>

using namespace std;

class Token {
public:
    string name;
    string value;
    Token(string nam)
        :name(nam), value(0) { }
    Token(string nam, string val)
        :name(nam), value(val) { }
};

bool IsNameUsed(vector<Token> NamesScores, string tempName){
    for (int i = 0;i<NamesScores.size();++i) {
        if (tempName == NamesScores[i].name) {
            return true;
        }
    }
    return false;
}

int main()
{
    vector<Token> NamesScores;
    cout<<"Insert Name and score (Noname 0 - End): ";
    string val;
    int counter = 0;
    string tempName;
    while(cin>>val){
        if(counter == 1){
            if (tempName=="Noname" && val=="0"){
                break;
            } else {
                if (IsNameUsed(NamesScores, tempName)){
                    cout<<"Name is in use.... insert other.\n";
                    counter=0;
                } else {
                        Token className = { tempName, val };
                        NamesScores.push_back(className);
                        counter = 0;
                }
            }
        } else {
            tempName = val;
            counter++;
        }
    }
    for(int i=0;i<NamesScores.size();++i){
        cout<<"\n"<< NamesScores[i].name<<" - "<< NamesScores[i].value;
    }
    cout << "\nInsert a Name ('Exit to quit): ";
    string value2;
    while (cin >> value2) {
        if (value2 == "Exit" || value2 == "exit") return 0;
        if (IsNameUsed(NamesScores, value2)) {
            for (int i = 0; i < NamesScores.size(); ++i) {
                if (value2 == NamesScores[i].name) {
                    cout << "\nThe Score for " << value2 << " is " << NamesScores[i].value;
                    cout << "\nInsert other Name (Type 'Exit' to exit):";
                    break;
                }
                
            }
        } else {
            cout << "\nName not found. Insert other Name (Type 'Exit' to exit):";
        }
    }

}