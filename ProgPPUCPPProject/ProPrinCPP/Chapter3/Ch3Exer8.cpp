#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int number_compare = 0;
    cout<<"Insert a Number: ";
    cin>>number_compare;
    cout<<"\n\nThe number "<<number_compare<<" is ";
    if ((number_compare%2)!=0)
    {
        cout<<"odd.\n";
    } else {
        cout<<"even.\n";
    }

    return 0;
}