#include <iostream>
#include <vector>

using namespace std;

int IsNumberRep(int value, vector<int> vectorNum){
    int counter = 0;
    for (int i=0;i<vectorNum.size();i++){
        if (vectorNum[i]==value){
            ++counter;
        }
    }
    return counter;
}

vector<int> vectorNoReps(vector<int> vectorNum){
    vector<int> VectorUserNoReps;
    vector<int> NumUserNoReps;
    for (int i=0;i<vectorNum.size();++i){
        bool equal = false;
        for (int j=0;j<VectorUserNoReps.size();++j){
            if (vectorNum[i]==VectorUserNoReps[j]){
                equal = true;
                break;
            }
        }
        if (equal!=true){
            VectorUserNoReps.push_back(vectorNum[i]);
        }
    }
    return VectorUserNoReps;
}

main()
{
    vector<int> numbersUser;
    int numberInput = 0;
    cout<<"Insert numbers (| to end): ";
    while(cin>>numberInput){
        if (numberInput>=0){
            numbersUser.push_back(numberInput);
        } else { 
            cout<<numberInput<<" is not a positive integer.\n, i skipped it.";
        } 
    }
    vector<int> numbersNoReps = vectorNoReps(numbersUser);
    vector<int> numbersWithRep;
    for (int j=0;j<numbersNoReps.size();j++){
        numbersWithRep.push_back(numbersNoReps[j]);
        numbersWithRep.push_back(IsNumberRep(numbersNoReps[j], numbersUser));
    }
    int greaterModal = 0;
    for (int temp:numbersWithRep){
        cout<<temp<<" ";
    }
    for (int i=1;i<numbersWithRep.size();i+=2){
        if (numbersWithRep[i]>greaterModal){
            greaterModal = numbersWithRep[i];
        }
    }
    int AmountModals = 0;
    for (int i=1;i<numbersWithRep.size();i+=2){
        if (numbersWithRep[i]==greaterModal){
            AmountModals++;
        }
    }
    if (AmountModals==1){
        for(int i=1;i<numbersWithRep.size();i+=2){
            if (numbersWithRep[i]==greaterModal){
                cout<<"\nThe mode of ur numbers is: "<<numbersWithRep[i-1]<<" with "<<numbersWithRep[i]<<" repetitions.\n";
            }
        }
    } else if (AmountModals>1){
        cout<<"\nThere are more than one modal:\n";
        for(int i=1;i<numbersWithRep.size();i+=2){
            if(numbersWithRep[i]==greaterModal){
                cout<<numbersWithRep[i-1]<<" with "<<numbersWithRep[i]<<" repetitions.\n";
            }
        }
    }
}