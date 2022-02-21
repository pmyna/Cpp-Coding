/*
* CD Collection Library
*
* Created: 11-2020
* Author: pmyna
*/

#include <iostream>
#include <string>
#include <vector>
#include "collection.hpp"

using namespace std;

int main(){
    Collection entry;
    vector<Album>collection;
    int menu;
    bool keep_run{true};
    
    do{
    cout << " [0] New Entry \n [1] Edit Entry \n [2] Delete Entry \n [3] Search\n\n";
        cout << "What would you like to do? ";
    cin >> menu;
    
    switch (menu) {
        case 0:
            entry.new_album(collection);
            break;
        case 1:
            entry.change_album(collection);
            break;
        case 2:
           entry.delete_album(collection);
            break;
        case 3:
            entry.search_album(collection);
            break;
        default: cout << "Programm beendet\n";
            keep_run = false;
            break;
    }}while(keep_run);
    
    
    
    return 0;
}
