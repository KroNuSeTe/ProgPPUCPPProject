#include <iostream>

using namespace std;

int main()
{
    int value1 = 0;
    int value2 = 0;
    int value3 = 0;
    int value_exchange = 0;
    cout<<"Insert one integer number:";
    cin>>value1;
    cout<<"Insert other integer number:";
    cin>>value2;
    cout<<"Insert a last integer number:";
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
    cout<<"This are the numbers ordered from low to high value:\n";
    cout<<value1<<" - "<<value2<<" - "<<value3;

    return 0;
}