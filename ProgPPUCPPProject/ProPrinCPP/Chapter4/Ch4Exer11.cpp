#include <iostream>
#include <vector>

using namespace std;

const vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

bool IsAPrime(int value){
    for(int temp:primes){
        if (temp<value){
            if (value%temp == 0){
                return false;
                break;
            }
        } else {
            return true;
            break;
        }
    }
}

main()
{
    vector<int> myPrimes;
    for(int i=2;i<=100;++i){
        if (IsAPrime(i)){
            myPrimes.push_back(i);
        }
    }
    cout<<"This are my primes: \n";
    for(int temp:myPrimes)
    {
        cout<<temp<<"  ";
    }
    cout<<"\nThis are stored primes: \n";
    for(int temp:primes)
    {
        cout<<temp<<"  ";
    }
}