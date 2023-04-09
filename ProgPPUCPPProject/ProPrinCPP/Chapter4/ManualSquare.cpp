#include <iostream>

using namespace std;

int SumSquare(int value){
    int TotalValue=0;
    for (int j=1;j<=value;++j){
        TotalValue += value;
    }
    return TotalValue;
}

int main()
{
    for (int i=0;i<100;++i){
        cout<<i<<"\t"<<SumSquare(i)<<"\n";
    }

    return 0;

}