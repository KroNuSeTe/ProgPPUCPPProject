#include <iostream>
#include <vector>

using namespace std;

main()
{
    vector<string> numberSpell = {"zero", "one", "two", "three", "foor", "five", "six", "seven", "eight", "nine", "ten",
        "eleven", "twelve", "thirteen", "fourteen", "fiveteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty"};
    int numberUser;
    cout<<"Insert a number (1-20): ";
    while(cin>>numberUser){
        if (numberUser>-1 && numberUser<21){
            break;
        } else {
            cout<<"(1-20)";
        }
    }
    cout<<"The input "<<numberUser<<" gives the output "<<numberSpell[numberUser]<<".";
}
