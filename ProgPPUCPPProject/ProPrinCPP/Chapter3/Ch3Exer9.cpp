#include <iostream>

using namespace std;

int main()
{
    string numberword;
    int numberdigit = 0;
    cout<<"Insert a númber from zero to four in words: ";
    cin>>numberword;
    if (numberword=="zero"){
        numberdigit = 0;   
    } else if (numberword=="one"){
        numberdigit = 1;
    } else if (numberword=="two"){
        numberdigit = 2;
    } else if (numberword=="three"){
        numberdigit = 3;
    } else if (numberword=="four"){
        numberdigit = 4;
    } else {
        cout<<"Not a number i know!";
        return 0;
    }
    cout<<"The number "<<numberword<<" in digit is: "<<numberdigit;

    return 0;
}