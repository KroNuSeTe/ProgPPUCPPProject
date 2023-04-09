#include <iostream>

using namespace std;

main()
{
    string value1;
    string value2;
    string value3;
    string value_exchange;
    cout<<"Insert one word: ";
    cin>>value1;
    cout<<"Insert other word: ";
    cin>>value2;
    cout<<"Insert a last word: ";
    cin>>value3;
    if(value1>value2)
    {
        value_exchange=value2;
        value2=value1;
        value1=value_exchange;
    }
    if(value2>value3)
    {
        value_exchange=value3;
        value3=value2;
        value2=value_exchange;
        if (value2<value1)
        {
            value_exchange=value1;
            value1=value2;
            value2=value_exchange;
        }
    }
    cout<<"This are the words ordered from low to high value:\n";
    cout<<value1<<" - "<<value2<<" - "<<value3;
}