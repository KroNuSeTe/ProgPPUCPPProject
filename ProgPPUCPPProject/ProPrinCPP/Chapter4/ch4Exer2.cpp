#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

main()
{
    vector<double> temps;
    for (double temp;cin>>temp;)
    {
        temps.push_back(temp);
    }
    double sum = 0;

    // Compute mean temperature:
    for (double x:temps)
    {
        sum +=x;
    }
    cout<<"Average temperature: "<<sum/temps.size()<<'\n';

    // Compute median temperature:
    sort(temps.begin(), temps.end());
    if (temps.size()%2 != 0){
        cout<<"Median temperature: "<<temps[temps.size()/2]<<'\n';
    } else {
        double medianValue = (temps[(temps.size()/2)-1] + temps[temps.size()/2]) / 2;
        cout<<"Median temperature: "<<medianValue;
    }

}