#include <iostream>
#include <vector>

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

int toIntFunction(string value)
{
    vector<string> numberSpell = {"zero", "one", "two", "three", "foor", "five", "six", "seven", "eight", "nine"};
    vector<string> numberChar = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    for(int i=0;i<=numberSpell.size()-1;++i){
        if(value==numberSpell[i]){
            return i;
        }
    }
    for(int i=0;i<=numberChar.size()-1;++i){
        if(value==numberChar[i]){
            return i;
        }
    }
}

main()
{
    string value1;
    string value2;
    int value1Double;
    int value2Double;
    double result;
    char operation;
    cout<<"-- Simply Calculator --";
    cout<<"\nInsert first value: (zero-nine, 0-9)";
    cin>>value1;
    value1Double = toIntFunction(value1);
    cout<<"\nInsert second value: ";
    cin>>value2;
    value2Double= toIntFunction(value2);
    cout<<"\nInsert an Operation (+,-,*,/): ";
    operation = AskTillCorrect();
    switch (operation) {
        case '+':
            result = value1Double + value2Double;
            cout<<"\nThe sum of "<<value1<<" and "<<value2<<" is: "<<result;
        break;
        case '-':
            result = value1Double - value2Double;
            cout<<"\nThe rest of "<<value1<<" and "<<value2<<" is: "<<result;
        break;
        case '*':
            result = value1Double * value2Double;
            cout<<"\nThe Multiplication of "<<value1<<" and "<<value2<<" is: "<<result;
        break;
        case '/':
            result = value1Double / value2Double;
            cout<<"\nThe division of "<<value1<<" and "<<value2<<" is: "<<result;
        break;
    }


}