#include <iostream>

using namespace std;

// convert from yens ('y'), kroner('k') and pounds ('p')
// to Dollars
// other suffix is an error

int main()
{
    constexpr double yen=132.15;
    constexpr double kroner=6.92;
    constexpr double pounds=0.82;
    double length=1;

    char unit=0;
    cout<<"y=yen, k=kroner, p=pounds\n";
    cout<<"Please enter a length followed by a unit (y, k or p):\n";
    cin>>length>>unit;

    if (unit =='y'){
        cout<<length<<"yenes=="<<length/yen<<"dollars\n";
    } else if (unit=='k') {
        cout<<length<<"kroners=="<<length/kroner<<"dollars\n";
    } else if (unit=='p'){
        cout<<length<<"pounds=="<<length/pounds<<"dollars\n";
    } else {
        cout<<"Sorry, I don't know a unit called '"<<unit<<"'\n";
    }

    return 0;
}