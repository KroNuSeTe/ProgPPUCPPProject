#include <iostream>

using namespace std;

inline void simple_error(string s)	// write ``error: sТТ and exit program
{
	cerr << "error: " << s << '\n';
    		// for some Windows environments
	exit(1);
}

main()
{
    string your_name;
    string first_name;
    string friend_name;
    string friend_sex;
    int age = 0;
    cout<<"Enter your name: ";
    cin>>your_name;
    cout<<"Enter the name of the person you want to write to ";
    cin>>first_name;
    cout<<"How many years have? ";
    cin>>age;
    if (age<=0 || age>=110) simple_error("You're kidding!");
    cout<<"Enter the name of you friend: ";
    cin>>friend_name;
    cout<<"is Male of Female? m/f: ";
    cin>>friend_sex;
    cout<<"Dear "<<first_name<<",";
    cout<<"\n\nHow are you? I am fine. I miss you.\n";
    cout<<"Since last day i see you, a lot of things happends.\n\n";
    cout<<"But, i told u when u come here budy.\n";
    cout<<"Have you seen "<<friend_name<<" lately?";
    if (friend_sex=="m") {
        cout<<"If u see "<<friend_name<<" please ask him to call me.";
    } else if (friend_sex=="f"){
        cout<<"If u see "<<friend_name<<" please ask her to call me.\n\n";
    }
    if (age<12){
        cout<<"Next year you will be "<<age+1<<".";
    } else if (age==17){
        cout<<"Next year you will be able to vote.";
    } else if (age>70){
        cout<<"I hope you are enjoying retirement.";
    }
    cout<<"\n\nYours sincerely, \n\n"<<your_name<<".\n";

}