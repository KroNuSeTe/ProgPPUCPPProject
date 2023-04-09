#include <iostream>
#include <vector>

using namespace std;

main()
{
    double grains = 1;
    vector<double> allSquares;
    allSquares.push_back(grains);
    bool doneThousand = false;
    bool doneMillion = false;
    bool doneBillion = false;
    for(int i=2;i<=64;++i){
        grains += grains;
        allSquares.push_back(grains);
        if (grains>=1000 && !doneThousand){
            cout<<"Needs "<<i<<" squares to obtain "<<to_string(grains)<<" grains.\n";
            doneThousand = true;
        }
        if (grains>=1000000 && !doneMillion){
            cout<<"Needs "<<i<<" squares to obtain "<<to_string(grains)<<" grains.\n";
            doneMillion = true;
        }
        if (grains>=1000000000 && !doneBillion){
            cout<<"Needs "<<i<<" squares to obtain "<<to_string(grains)<<" grains.\n";
            doneBillion = true;
        }
    }
    for(int i=0;i<=allSquares.size()-1;++i){
        cout<<i+1<<" squares, are "<<allSquares[i]<<" grains.\n";
    }
    
}