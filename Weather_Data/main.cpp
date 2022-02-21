/*
* Analysing Weather Data
*
* Created: 01-2021
* Author: pmyna
*/
#include <iostream>
#include "weather.hpp"
using namespace std;

int main(){
    int choice;
    bool weiter{true};
    double wetterdaten[5][7][3];
    
    cout << "Enter your Data: "; //Entry as follows: 5x Data Points Day 1, 5x Data Points Day 2 ...
    for (int k{0}; k < 3; k++)
        for (int j{0}; j < 7; j++)
            for (int i{0}; i < 5; i++)
                cin >> wetterdaten[i][j][k];
    
    cout << "Data Entry Successful!" << endl;
    
    do{
        cin.clear();
        cin.ignore();
        cout << "Which average would you like to calculate?\n [0] for Day X\n [1] for Week X \n [2] Overall" << endl;
        cin >> choice;
        switch (choice) {
            case 0:
                median_tag(wetterdaten);
                break;
            case 1:
                median_woche(wetterdaten);
                break;
            case 2:
                cout << "The overall average Temperature is: " << median_gesamt(wetterdaten) << endl;
                break;
            default:
                cout << "Program finished.";
                weiter = false;
                break;
        }
    }while (weiter);

    return 0;
}
