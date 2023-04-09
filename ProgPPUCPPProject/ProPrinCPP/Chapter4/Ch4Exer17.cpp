#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int IsNumberRep(string value, vector<string> vectorNum){
    int counter = 0;
    for (int i=0;i<vectorNum.size();i++){
        if (vectorNum[i]==value){
            ++counter;
        }
    }
    return counter;
}

vector<string> vectorNoReps(vector<string> vectorStr){
    vector<string> VectorUserNoReps;
    vector<string> NumUserNoReps;
    for (int i=0;i<vectorStr.size();++i){
        bool equal = false;
        for (int j=0;j<VectorUserNoReps.size();++j){
            if (vectorStr[i]==VectorUserNoReps[j]){
                equal = true;
                break;
            }
        }
        if (equal!=true){
            VectorUserNoReps.push_back(vectorStr[i]);
        }
    }
    return VectorUserNoReps;
}

main()
{
    stringstream ss;
    vector<string> stringsUser;
    string stringInput;
    cout<<"Insert strings (insert exit to finish): ";
    while(cin>>stringInput){
        if (stringInput!="exit"){
            stringsUser.push_back(stringInput);
        } else { 
            break;
        } 
    }
    vector<string> stringsNoReps = vectorNoReps(stringsUser);
    vector<string> stringsWithRep;
    for (int j=0;j<stringsNoReps.size();j++){
        stringsWithRep.push_back(stringsNoReps[j]);
        stringsWithRep.push_back(to_string(IsNumberRep(stringsNoReps[j], stringsUser)));
    }
    int greaterModal = 0;
    for (string temp:stringsWithRep){
        cout<<temp<<" ";
    }
    for (int i=1;i<stringsWithRep.size();i+=2){
        if (stoi(stringsWithRep[i])>greaterModal){
            ss<<stringsWithRep[i];
            ss>>greaterModal;
        }
    }
    int AmountModals = 0;
    for (int i=1;i<stringsWithRep.size();i+=2){
        if (stoi(stringsWithRep[i])==greaterModal){
            AmountModals++;
        }
    }
    if (AmountModals==1){
        for(int i=1;i<stringsWithRep.size();i+=2){
            if (stoi(stringsWithRep[i])==greaterModal){
                cout<<"\nThe mode of ur numbers is: "<<stringsWithRep[i-1]<<" with "<<stringsWithRep[i]<<" repetitions.\n";
            }
        }
    } else if (AmountModals>1){
        cout<<"\nThere are more than one modal:\n";
        for(int i=1;i<stringsWithRep.size();i+=2){
            if(stoi(stringsWithRep[i])==greaterModal){
                cout<<stringsWithRep[i-1]<<" with "<<stringsWithRep[i]<<" repetitions.\n";
            }
        }
    }
}