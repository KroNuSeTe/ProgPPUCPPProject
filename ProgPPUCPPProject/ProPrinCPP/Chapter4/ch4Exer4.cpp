#include <iostream>
#include <Math.h>

using namespace std;

bool CharCorrect (char charValue){
    if (charValue == 'Y' || charValue=='y' || charValue =='N' || charValue=='n')
    {
        return true;       
    } else {
        return false;
    }
}

char AskTillCorrect()
{
    char characterYesNo;
    while(cin>>characterYesNo){
        if (CharCorrect(characterYesNo)){
            return characterYesNo;
        } else {
            cout<<"(Y/N)?";
        }
    }
}

int AskQuestion(int numConstante, int numGuess, string moreOrLess){
    if(moreOrLess=="more"){
        numGuess += numConstante;
    } else if(moreOrLess=="less"){
        numGuess -= numConstante;
    }
    cout<<"Is "<<numGuess<<" your number? (Y/N): ";
    char replyYesNo = AskTillCorrect();
    if (replyYesNo == 'Y' || replyYesNo == 'y'){
        cout<<"Your Number is "<<numGuess<<"\n";
        numGuess= 9999;
        return numGuess;
    } else if (replyYesNo == 'N' || replyYesNo == 'n'){
        if(numGuess<=100 && numGuess>=1){
            cout<<"Is ur number more than "<<numGuess<<"? (Y/N): ";
        }
        return numGuess;     
    }
}

main()
{
    double constanteDouble = 50.f;
    int constante = 50;
    int numGuesing = 100;            ;
    cout<<"Think a number between 1 and 100 (Press Enter): ";
    cin.ignore();
    numGuesing = AskQuestion(constante, numGuesing, "less");
    while (constante >= 2){
        constanteDouble = round(constanteDouble /= 2);
        constante = constanteDouble;
        if (numGuesing>100){
            numGuesing=100;
            break;
        } else if (numGuesing<1){
            numGuesing=1;
            break;
        }
        char replyYesNo = AskTillCorrect();
        if (replyYesNo == 'Y' || replyYesNo == 'y'){
            numGuesing = AskQuestion(constante, numGuesing, "more");
        } else if (replyYesNo == 'N' || replyYesNo == 'n'){
            numGuesing = AskQuestion(constante, numGuesing, "less");
        }
        if (numGuesing==9999){
            return 0;
        }
    }
    if (numGuesing=9999){
        return 0;
    }
    cout<<"Your Number is "<<numGuesing<<"\n";

}