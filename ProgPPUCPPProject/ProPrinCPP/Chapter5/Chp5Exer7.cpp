#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
    double a = 0;
    double b = 0;
    double c = 0;
    cout<<"-------------------------------------------\n";
    cout<<"------------Quadratic Equation-------------\n";
    cout<<"-------------------------------------------\n";
    cout<<"------------ ax² + bx + c = 0  ------------\n";
    cout<<"-------------------------------------------\n";
    cout<<"Insert values a: ";
    cin>>a;
    cout<<"\nInsert values b: ";
    cin>>b;
    cout<<"\nInsert values c: ";
    cin>>c;
    if ((pow(b,2)-(4*a*c))>0){
        // Two Real solutions;
        double x = 0;
        double x2 = 0;
        x = (-b + sqrt(pow(b,2)-(4*a*c)))/(2*a);
        x2 = (-b - sqrt(pow(b,2)-(4*a*c)))/(2*a);
        cout<<"\nThe first Real solution is x = "<<x;
        cout<<"\nThe second Real solution is x = "<<x2;
    } else if ((pow(b,2)-(4*a*c))==0){
        // Two solutions, the same so One solution.
        double x = 0;
        double x2 = 0;
        x = (-b + sqrt(abs(pow(b,2)-(4*a*c))))/(2*a);
        cout<<"\nThe only Solution is x = "<<x;
    } else {
        // Two Complex solutions
        double x = 0;
        double imagNumber = sqrt(abs(pow(b,2)-(4*a*c)));
        cout<<"\nThe Solution is to Complex Solutions, x = "<<-b/(2*a)<<" ± "<<imagNumber/(2*a)<<"i";
    }

    return 0;
}