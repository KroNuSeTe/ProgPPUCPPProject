#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

int main()
{
    double temp = 0.f;
    string units;
    double smallest = 0.f;
    double largest = 0.f;
    string smallestString;
    string largestString;
    bool firstTime=true;
    double valueInCM;
    bool valueInvalid=false;
    int numberOfValues = 0;
    double TotalSumValues = 0;
    vector<double> AllValuesInMeters;

    cout<<"Insert a Double Value and Unit(cm, m, in, ft) (| to exit): ";

    while(cin>>temp>>units){
        if(units=="cm"){
            valueInCM=temp;
            double valor=valueInCM/100;
            AllValuesInMeters.push_back(valor);
        } else if (units=="in"){
            valueInCM=temp*2.54;
            double valor=valueInCM/100;
            AllValuesInMeters.push_back(valor);
        } else if (units=="ft"){
            valueInCM=temp*12*2.54;
            double valor=valueInCM/100;
            AllValuesInMeters.push_back(valor);
        } else if (units=="m"){
            valueInCM=temp*100;
            double valor=valueInCM/100;
            AllValuesInMeters.push_back(valor);
        } else {
            cout<<" use cm,m,ft or in, unit not reconocible.";
            valueInvalid="true";
        }
        if(!valueInvalid){
            ++numberOfValues;
            TotalSumValues += valueInCM;
            if (firstTime){
                largest = valueInCM;
                int nodecimals = temp;
                largestString = to_string(nodecimals)+" "+units;
                cout<<"\n"<<largestString<<" is the largest so far.\n";
                smallest = valueInCM;
                firstTime = false;
            } else {
                if (valueInCM<smallest){
                    smallest = valueInCM;
                    int nodecimals = temp;
                    smallestString = to_string(nodecimals)+" "+units;
                    cout<<"\n"<<smallestString<<" is the smallest so far.\n";
                } else if (valueInCM>largest){
                    largest = valueInCM;
                    int nodecimals = temp;
                    largestString = to_string(nodecimals)+" "+units;
                    cout<<"\n"<<largestString<<" is the largest so far.\n";
                }
            }
            cout<<"The number of values entered is: "<<numberOfValues;
            cout<<"\nThe Sum of all the values entered is: "<<TotalSumValues/100<<" m.";
            cout<<"\nInsert a Double Value and Unit(cm, m, in, ft) (| to exit): ";
        } else {
            valueInvalid = false;
            cout<<"\nInsert a Double Value and Unit(cm, m, in, ft) (| to exit): ";
        }
    }
    sort(AllValuesInMeters.begin(), AllValuesInMeters.end());
    for(double tempo:AllValuesInMeters){
        cout<<"\n"<<tempo<<" m, ";
    }

}