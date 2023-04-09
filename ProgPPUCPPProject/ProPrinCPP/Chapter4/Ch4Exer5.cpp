#include <iostream>

using namespace std;

bool CharCorrect (char charValue){
    if (charValue == '+' || charValue=='*' || charValue =='/' || charValue=='-')
    {
        return true;       
    } else {
        return false;
    }
}

char AskTillCorrect()
{
    char operatorComp;
    while(cin>>operatorComp){
        if (CharCorrect(operatorComp)){
            return operatorComp;
        } else {
            cout<<"(+,-,*,/): ";
        }
    }
}

main()
{
    double value1;
    double value2;
    double result;
    char operation;
    cout<<"-- Simply Calculator --";
    cout<<"\nInsert first value: ";
    cin>>value1;
    cout<<"\nInsert second value: ";
    cin>>value2;
    cout<<"\nInsert an Operation (+,-,*,/): ";
    operation = AskTillCorrect();
    switch (operation) {
        case '+':
            result = value1 + value2;
            cout<<"\nThe sum of "<<value1<<" and "<<value2<<" is: "<<result;
        break;
        case '-':
            result = value1 - value2;
            cout<<"\nThe rest of "<<value1<<" and "<<value2<<" is: "<<result;
        break;
        case '*':
            result = value1 * value2;
            cout<<"\nThe Multiplication of "<<value1<<" and "<<value2<<" is: "<<result;
        break;
        case '/':
            result = value1 / value2;
            cout<<"\nThe division of "<<value1<<" and "<<value2<<" is: "<<result;
        break;
    }


}