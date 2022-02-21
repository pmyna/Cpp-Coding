/*
* Soccer Team Manager
*
* Created: 02-2021
* Author: pmyna
*/

#ifndef SPIELER_H
#define SPIELER_H

#include<iostream>
#include<vector>
#include<string>
#include<stdexcept>

using namespace std;

enum class Position {Tor, Abwehr, Mitte, Sturm};
const vector<string> positionsnamen{"Tor","Abwehr","Mitte","Sturm"}; //German for Goalie, Defence, Midfield, Striker

//Definition der Klasse Spieler (Player)
class Spieler{
	string name;
  int transfer;
  Position position;
  
public: 
  Spieler(string name, int transfer, const Position position = Position::Tor) : name{name}, transfer{transfer}, position{position}{
  if(name.empty() || transfer < 10 || transfer > 500)
    throw runtime_error{"Ungültige Eingabe"};
  }
  
  bool operator==(const Spieler&s) const{
  return name == s.name;
  }
   
  Position get_position()const{return position;}
  
	ostream& print(ostream&o) const{
  return o << "[" << name << ", " << transfer << " Mio Euro, " << positionsnamen.at(static_cast<size_t>(position)) << "]";
  }
};

inline ostream& operator<<(ostream&o, const Spieler&s){
	return s.print(o);
}
#endif
