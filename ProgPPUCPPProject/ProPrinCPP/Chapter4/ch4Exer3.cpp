#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

main()
{
    cout<<"Insert distances between Cities (| to finish): ";
    vector<double> tempDistances; 
    for(double temp;cin>>temp;)
    {
        tempDistances.push_back(temp);
    }
    sort(tempDistances.begin(), tempDistances.end());
    double sumTotalDistances = 0;
    for(double temp:tempDistances){
        sumTotalDistances += temp;
    }
    double meanDistance = sumTotalDistances/2;
    cout<<"\nThe sum of all distances are : "<<sumTotalDistances<<" Km.\n";
    cout<<"The Smallest distance are: "<<tempDistances[0]<<" Km.\n";
    cout<<"The Greatest distance are: "<<tempDistances[tempDistances.size()-1]<<" Km.\n";
    cout<<"The mean distance are: "<<meanDistance<<" Km.\n";

}