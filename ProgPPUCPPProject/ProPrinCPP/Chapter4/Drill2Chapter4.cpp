#include <iostream>
#include <vector>

using namespace std;

bool AlmostEqual(vector<double> valueVector){
    if (valueVector[0]-valueVector[1]>-1 && valueVector[0]-valueVector[1]<1){
        return true;
    } else {
        return false;
    }
}

main()
{
    
    double temp;
    cout<<"Insert 2 Int Values (| to exit): ";
    vector<double> valuesVector;
    while(cin>>temp){
        valuesVector.push_back(temp);
        if (valuesVector.size()==2){
            if (valuesVector[0]==valuesVector[1]){
                cout<<"the numbers are equal. \n";
            } else if (valuesVector[0]>valuesVector[1]){
                cout<<"the smaller value is: "<<valuesVector[1]<<"\n";
                cout<<"the larger value is: "<<valuesVector[0]<<"\n"; 
                if(AlmostEqual(valuesVector)){
                    cout<<"the numbers are almost equal. \n";
                }
            } else {
                cout<<"the smaller value is: "<<valuesVector[0]<<"\n";
                cout<<"the larger value is: "<<valuesVector[1]<<"\n";    
                if(AlmostEqual(valuesVector)){
                    cout<<"the numbers are almost equal";
                }
            }            
            cout<<"Insert 2 Int Values (| to exit): ";
            valuesVector.clear();
        }
    }
}