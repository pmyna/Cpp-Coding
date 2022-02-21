#include "collection.hpp"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

    Album::Album() //Default Constructor
    {
        interpret = "NA";
        titel = "NA";
        stil = "NA";
    }
    // Setters
    void Album::set_interpret(const string interpret){
        this->interpret = interpret;
    }
    void Album::set_titel(const string titel){
        this->titel = titel;
    }
    void Album::set_stil(const string stil){
        this->stil = stil;
    }
    //Getters
    string Album::get_interpret() const{
        return interpret;
    }
    string Album::get_titel() const{
        return titel;
    }
    string Album::get_stil() const{
        return stil;
    }

ostream & operator << (ostream&out, const Album&a){
    out << a.get_titel() << '\t' << a.get_interpret() << '\t' << a.get_stil() << '\n';
    return out;}
    
    void Collection::new_album(vector<Album>&collection){
        Album entry;
        string in,ti,st;
        cin.clear();
        cin.ignore();
        
        cout << "Enter Album Name: ";
            getline(cin, ti);
            entry.set_titel(ti);
        cout << "Enter Interpreter: ";
            getline(cin, in);
            entry.set_interpret(in);
        cout << "Enter Music Style: ";
            getline(cin,st);
            entry.set_stil(st);
        cout << "New Entry saved!\n\n";
        
       collection.push_back(entry);
    }
    
    void Collection::change_album(vector<Album>&collection){
        int x{0}, y;
        char choice;
        string new_title, new_interpret, new_stil;
        
        cout << "Which Album would you like to edit?\n";
        cout << "[#]\t[Name]\t[Interpreter]\t[Style]\n";
        do{
            for(auto i{0}; i < collection.size(); i++){
                cout << "[" << x << "]" << '\t';
                cout << collection.at(i);
                x++;}
        }while (x < collection.size());
        
        cin >> y;
        cout << "Would you like to edit the [A]lbum Name, [I]nterpreter or [S]tyle? ";
        cin >> choice;
            if (choice == 'A' || choice == 'a'){
                cin.clear();
                cin.ignore();
                cout << "New Album Name: ";
                getline(cin, new_title);
                collection.at(y).set_titel(new_title);}
            if (choice == 'I' || choice == 'i'){
                cin.clear();
                cin.ignore();
                cout << "New Interpreter: ";
                getline(cin, new_interpret);
                collection.at(y).set_interpret(new_interpret);}
            if (choice == 'S' || choice == 's'){
                cin.clear();
                cin.ignore();
                cout << "New Style: ";
                getline(cin, new_stil);
                collection.at(y).set_stil(new_stil);}
        cout << "Album edited!\n\n";
        }
    
    void Collection::delete_album(vector<Album>&collection){
        int x{0}, y;
        cout << "Which Album would you like to delete?\n\n";
        cout << "[#]\t[Name]\t[Interpreter]\t[Style]\n";
        do{
            for(auto i{0}; i < collection.size(); i++){
                cout << "[" << x << "]" << '\t';
                cout << collection.at(i);
                x++;}
        }while (x < collection.size());
        cout << '\n';
        cin >> y;
        collection.erase(collection.begin()+y);
        cout << "Album deleted!\n\n";
    }
    void Collection::search_album(vector<Album>&collection){
        char choice;
        string interpret, titel, stil;
        
        cout << "Are you looking for [A]lbum Name, [I]nterpreter oder [S]tyle? ";
        cin >> choice;
        if (choice == 'I' || choice == 'i'){
            cout << "Search Interpreter: ";
            cin >> interpret;
            cout << "\n[Name]\t[Interpreter]\t[Style]\n";
            for(auto i{0}; i < collection.size(); i++)
            if (interpret == collection.at(i).get_interpret())
                cout << collection.at(i) << "\n";
            }
        if (choice == 'a' || choice == 'A'){
            cout << "Search Album Name: ";
            cin >> titel;
            cout << "\n[Name]\t[Interpreter]\t[Style]\n";
            for(auto i{0}; i < collection.size(); i++)
            if (titel == collection.at(i).get_titel())
                cout << collection.at(i) << "\n";
        }
        if (choice == 's' || choice == 'S'){
            cout << "Search Style: ";
            cin >> stil;
            cout << "\n[Name]\t[Interpreter]\t[Style]\n";
            for(auto i{0}; i < collection.size(); i++)
            if (stil == collection.at(i).get_stil())
                cout << collection.at(i) << "\n";
        }
    }

