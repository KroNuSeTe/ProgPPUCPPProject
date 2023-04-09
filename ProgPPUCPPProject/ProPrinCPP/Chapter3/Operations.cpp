#include <iostream>

using namespace std;

main()
{
    string operand_input;
    double number1 = 0;
    double number2 = 0;
    double operand_result = 0;
    cout<<"Insert the operand (+,-,*,/,plus,minus,mul,div): ";
    cin>>operand_input;
    cout<<"Insert One Number: ";
    cin>>number1;
    cout<<"Insert Second Number: ";
    cin>>number2;
    if (operand_input=="+" || operand_input=="plus")    
    {
        operand_result = number1 + number2;
    } else if ( operand_input=="-" || operand_input=="minus")
    {
        operand_result = number1 - number2;
    } else if ( operand_input=="*" || operand_input=="mul")
    {
        operand_result = number1 * number2;
    }else if ( operand_input=="/" || operand_input=="div")
    {
        operand_result = number1 / number2;
    } else {
        cout<<"Operation not valid.";
        return 0;
    }
    cout<<"The operation "<<number1<<" "<<operand_input<<" "<<number2<<" = "<<operand_result;
}