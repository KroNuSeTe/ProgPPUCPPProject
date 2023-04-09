#include <iostream>
#include <vector>

using namespace std;

bool isBleep(string value){
    vector<string> awfullWords = {"Brocolli", "spiders", "spider", 
        "snake", "snakes", "illness", "hospital", "hospitals", "death"};
    for (string str:awfullWords){
        if(value==str){
            return true;
        }
    }
    return false;
}

int main()
{
    vector<string> words;
    cout<<"Insert words: ";
    for (string temp;cin>>temp;){
        if(isBleep(temp)) {
            words.push_back("BLEEP");
        } else {
            words.push_back(temp);
        }
    }

    for (string temp2:words){
        cout<<temp2<<"\n";
    }

    return 0;

}