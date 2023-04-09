#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

main()
{
    int maxValue=0;
    cout<<"-----------------------------------\n";
    cout<<"-------Sieve of Eratosthenes-------\n";
    cout<<"-----------------------------------\n";
    cout<<"Insert a Number: ";
    cin>>maxValue;
    vector<int> intVectorHundred;
    for (int i=2;i<=maxValue;++i){
        intVectorHundred.push_back(i);
    }
    vector<int> intPrimes;
    intPrimes.push_back(intVectorHundred[0]);
    for(int i=1;i<=intVectorHundred.size()-1;i++){
        if(intVectorHundred[i]%2 != 0){
            intPrimes.push_back(intVectorHundred[i]);
        }
    }
    vector<int> intPrimes2;
    intPrimes2.push_back(intPrimes[0]);
    intPrimes2.push_back(intPrimes[1]);
    for(int i=2;i<=intPrimes.size()-1;++i){
        if(intPrimes[i]%3 != 0){
            intPrimes2.push_back(intPrimes[i]);
        } 
    }
    vector<int> intPrimes3;
    intPrimes3.push_back(intPrimes2[0]);
    intPrimes3.push_back(intPrimes2[1]);
    intPrimes3.push_back(intPrimes2[2]);
    for(int i=3;i<=intPrimes2.size()-1;++i){
        if(intPrimes2[i]%5 != 0){
            intPrimes3.push_back(intPrimes2[i]);
        } 
    }
    vector<int> intPrimes4;
    intPrimes4.push_back(intPrimes3[0]);
    intPrimes4.push_back(intPrimes3[1]);
    intPrimes4.push_back(intPrimes3[2]);
    intPrimes4.push_back(intPrimes3[3]);
    for(int i=4;i<=intPrimes3.size()-1;++i){

        if(intPrimes3[i]%7 != 0){
            intPrimes4.push_back(intPrimes3[i]);
        } 
    }

    cout<<"\n---------- Sieve of Eratosthenes (1-"<<maxValue<<") ----------\n";
    for(int temp:intPrimes4){
        cout<<temp<<"  ";
    }
}