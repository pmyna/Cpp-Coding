#include <iostream>
#include "weather.hpp"

using namespace std;

void median_tag(double daten[5][7][3]){
    double median_t,help{0};
    int week, day;
    
    cout << "For which Week would you like to calculate the average Temperature?\n Week [1]\n Week [2]\n Week [3]\n";
    cin >> week;
    cout << "For which Day would you like to calculate the average Temperature?\n Day [1]\n Day [2]\n Day [3]\n Day [4]\n Day [5]\n Day [6]\n Day [7]\n";
    cin >> day;
    
    for (int i{0}; i < 5; i++)
        help += daten[i][day-1][week-1];

    median_t = help/5;
    cout << "The daily average for Week [" << week << "] Day [" << day << "] is: " << median_t << "\n" << endl;
}

void median_woche(double daten[5][7][3]){
    double median_w, help{0};
    int week;
    
    cout << "For which Week would you like to calculate the average Temperature?\n Week [1]\n Week [2]\n Week [3]\n";
    cin >> week;
    
    for (int i{0}; i < 5; i++)
        for (int j{0}; j < 7; j++)
                help += daten[i][j][week-1];
                
    median_w = help/7;
    cout << "The daily average for Week [" << week << "] is: " << median_w << "\n" << endl;
}

double median_gesamt(double daten[5][7][3]){
    double median_g;
    double help{0};
    
    for (int i{0}; i < 5; i++)
        for (int j{0}; j < 7; j++)
            for (int k{0}; k < 3; k++)
                help += daten[i][j][k];
                
    median_g = help/105;
    return median_g;
}
