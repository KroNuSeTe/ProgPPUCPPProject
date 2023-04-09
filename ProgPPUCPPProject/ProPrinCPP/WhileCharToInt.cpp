#include <iostream>

using namespace std;

int main()
{
    
    char character='a';
    int i=97;
    while(i<123)
    {
        cout<<char(character)<<"\t"<<i<<"\n";
        ++character;
        ++i;
    }

    return 0;

}