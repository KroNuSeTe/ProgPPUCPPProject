#include <iostream>
#include <vector>

using namespace std;

main()
{
    srand((unsigned) time(NULL));
    char userChooseChar;
    string userChooseWord;
    int randNumber;
    char aiChooseChar;
    string aiChooseWord;
    vector<string> RockPaperScissors = {"Rock", "Paper", "Scissors"};
    cout<<"-------------------------------------\n";
    cout<<"------- Rock, Paper, Scissors -------\n";
    cout<<"-------------------------------------\n";
    cout<<"Let´s Play: Insert an object (R--Rock, P--Paper, S--Scissors): ";
    cin>>userChooseChar;
    switch(userChooseChar){
        case 'R':
            userChooseWord = RockPaperScissors[0];
            break;
        case 'P':
            userChooseWord = RockPaperScissors[1];
            break;
        case 'S':
            userChooseWord = RockPaperScissors[2];
            break;
    }
    randNumber = 1+(rand()%3);
    cout<<"\n"<<randNumber;
    cout<<"I Choose: ";
    cin.ignore();
    
    switch (randNumber){
        case 1:
            cout<<"Rock!";
            aiChooseChar = 'R';
            aiChooseWord = RockPaperScissors[0];
            break;
        case 2:
            cout<<"Paper!";
            aiChooseChar = 'P';
            aiChooseWord = RockPaperScissors[1];
            break;
        case 3:
            cout<<"Scissors!";
            aiChooseChar = 'S';
            aiChooseWord = RockPaperScissors[2];
            break;
    }
    if (aiChooseChar == userChooseChar){
        cout<<"\nur "<<userChooseWord<<" versus my "<<aiChooseWord<<" is a Tie.";
    } else if (aiChooseChar == 'R' && userChooseChar=='P'){
        cout<<"\nur "<<userChooseWord<<" Envelops my "<<aiChooseWord<<", u Win!!!!!! Congrats!!!";
    } else if (aiChooseChar == 'P' && userChooseChar=='R'){
        cout<<"\nmy "<<aiChooseWord<<" Envelops ur "<<userChooseWord<<", u Lose!!!! I Win!!! HaHaHaHaHa...";
    } else if (aiChooseChar == 'R' && userChooseChar=='S'){
        cout<<"\nmy "<<aiChooseWord<<" Hits ur "<<userChooseWord<<", u Lose!!!! I Win!!! HaHaHaHaHa...";
    } else if (aiChooseChar== 'S' && userChooseChar=='R'){
        cout<<"\nur "<<userChooseWord<<" Hits my "<<aiChooseWord<<", u Win!!!!!! Congrats!!!";
    } else if (aiChooseChar == 'P' && userChooseChar=='S'){
        cout<<"\nur "<<userChooseWord<<" Cuts my "<<aiChooseWord<<", u Win!!!!!! Congrats!!!";
    } else if (aiChooseChar =='S' && userChooseChar=='P'){
        cout<<"\nmy "<<aiChooseWord<<" Cuts ur "<<userChooseWord<<", u Lose!!!! I Win!!! HaHaHaHaHa...";
    }

}