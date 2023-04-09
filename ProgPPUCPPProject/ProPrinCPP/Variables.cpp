#include <iostream>


using namespace std;


int main()
{
    cout<<"Please enter your first name and age\n";
    string first_name="???";
    int age=0;
    cin>>first_name>>age;
    cout<<"Hello, "<<first_name<<"(age "<<age<<")\nU are lived: "<<age*12<<" Months\n";
}