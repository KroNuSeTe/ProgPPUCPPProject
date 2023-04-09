#include <iostream>

using namespace std;

int main()
{
    int pennies = 0;
    int nickels = 0;
    int dimes = 0;
    int quarters = 0;
    int half_dollars = 0;
    int dollars = 0;
    double total_cents = 0;
    double total_dolars = 0.0;

    cout<<"Insert the number of coins in your Wallet:\n";
    cout<<"Pennies(1-cent coins): ";
    cin>>pennies;
    cout<<"\nNickels(5-cent coins): ";
    cin>>nickels;
    cout<<"\nDimes(10-cent coins): ";
    cin>>dimes;
    cout<<"\nQuarters(25-cent coins): ";
    cin>>quarters;
    cout<<"\nHalf Dollars(50-cent coins): ";
    cin>>half_dollars;
    cout<<"\nDollars(100-cent coins): ";
    cin>>dollars;
    if (pennies>1){
        cout<<"\n\nYou have "<<pennies<<" pennies.";
    } else if(pennies==1){
        cout<<"\n\nYou have 1 penny.";
    }       
    if (nickels>1){
        cout<<"\n\nYou have "<<nickels<<" nickels.";
    } else if(nickels==1){
        cout<<"\n\nYou have 1 nickel.";
    }
    if (dimes>1){
        cout<<"\n\nYou have "<<dimes<<" dimes.";
    } else if(dimes==1){
        cout<<"\n\nYou have 1 dime.";
    }
    if (quarters>1){
        cout<<"\n\nYou have "<<quarters<<" quarters.";
    } else if(quarters==1){
        cout<<"\n\nYou have 1 quarter.";
    }
    if (half_dollars>1){
        cout<<"\n\nYou have "<<half_dollars<<" half dollars.";
    } else if(half_dollars==1){
        cout<<"\n\nYou have 1 half of a dollar.";
    }
    if (dollars>1){
        cout<<"\n\nYou have "<<dollars<<" dollars.";
    } else if(dollars==1){
        cout<<"\n\nYou have 1 dollar.";
    }
    total_cents=pennies+(nickels*5)+(dimes*10)+(quarters*25)+(half_dollars*50)
        +(dollars*100);
    cout<<"\n\nThe Total of Cents in your Wallet is "<<total_cents<<" Cents.";
    total_dolars=total_cents/100;
    cout<<"\n\nThe Total of Dollars in y0our Wallet is "<<total_dolars<<" Dollars.";

    return 0;
}