#include <iostream>
#include <vector>

using namespace std;

main()
{
    vector<string> numberSpelled = {"zero", "one", "two", "three", "foor", "five", "six", "seven", "eight", "nine", "ten",
        "eleven", "twelve", "thirteen", "fourteen", "fiveteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty"};
    string stringUser;
    cout<<"Insert a spelled number (one-twenty): ";
    cin>>stringUser;

    for(int i=0;i<=numberSpelled.size();++i)
    {
        if(stringUser==numberSpelled[i])
        {
            cout<<"\nThe input "<<stringUser<<" gives the output "<<i<<".";
        }
    }

}