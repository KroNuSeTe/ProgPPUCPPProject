#include <iostream>
#include <vector>

using namespace std;

int main()
{
    
    int temp;
    cout<<"Insert 2 Int Values (| to exit): ";
    vector<int> valuesVector;
    while(cin>>temp){
        valuesVector.push_back(temp);
        if (valuesVector.size()==2){
            cout<<valuesVector[0]<<", "<<valuesVector[1]<<"\n";
            cout<<"Insert 2 Int Values (| to exit): ";
            valuesVector.clear();
        }
    }

    return 0;

}