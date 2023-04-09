#include <iostream>
#include <vector>

using namespace std;

bool IsNameUsed(string name, vector<string>names){
    for(string temp:names){
        if (temp==name){
            return true;
        }
    }
    return false;
}

string ScoreName(string name, vector<string>names, vector <string>scores) {
    for (int i = 0;i<names.size();++i) {
        if (names[i] == name) {
            return scores[i];
        }
    }
}

int main()
{
    vector<string> names;
    vector<string> scores;
    cout<<"Insert Name and score (Noname 0 - End): ";
    string value;
    int counter = 0;
    string tempName;
    while(cin>>value){
        if(counter == 1){
            if (tempName=="Noname" && value=="0"){
                break;
            } else {
                if (IsNameUsed(tempName, names)){
                    cout<<"Name is in use.... insert other.\n";
                    counter=0;
                } else {
                    names.push_back(tempName);
                    scores.push_back(value);
                    counter=0;
                }
            }
        } else {
            tempName = value;
            counter++;
        }
    }
    for(int i=0;i<names.size();++i){
        cout<<"\n"<<names[i]<<" - "<<scores[i];
    }
    cout << "\nInsert a Name (| to exit): ";
    string value2;
    string scoreFinal;
    while (cin >> value2) {
        if (value2 == "Exit") return 0;
        if (IsNameUsed(value2, names)) {
            scoreFinal = ScoreName(value2, names, scores);
            cout<<"\nThe Score for "<<value2<<" is "<<scoreFinal;
            cout << "\nInsert other Name (Type 'Exit' to exit):";
        } else {
            cout << "\nName not found. Insert other Name (Type 'Exit' to exit):";
        }
    }

}