#include <iostream>

using namespace std;

main()
{
    int oneMile = 1609;
    int num_miles=0;
    cout<<"Insert a number of miles: ";
    cin>>num_miles;
    int in_kilometers = num_miles * oneMile;
    cout<<"\n"<<num_miles<<" in kilometers are: "<<in_kilometers;

}