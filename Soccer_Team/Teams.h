#ifndef MANNSCHAFT_H
#define MANNSCHAFT_H

#include<iostream>
#include<vector>
#include<string>
#include<stdexcept>
#include"spieler.h"
using namespace std;

//Definition der Klasse Mannschaft (Teams)
class Mannschaft{
	string m_name;
  vector<Spieler>spieler;
  
public:
  Mannschaft(string m_name, const vector<Spieler>spieler = {}) : m_name{m_name}, spieler{spieler}{
    if (m_name.empty())
      throw runtime_error{"Kein Name"};
    
  	for(size_t i{0}; i < spieler.size(); ++i)
      for(size_t j{0}; j < spieler.size(); ++j)
      if(i !=j && spieler.at(i) == spieler.at(j))
        throw runtime_error{"Spieler doppelt"};
  }
  
vector<Spieler> engagieren(const vector<Spieler>& s){
 	auto it{s.begin()};
  vector<Spieler> doubles;
  int count{0};
  
  while(it != end(s)){
  	for (const auto& sp:spieler){
    	if(*it==sp)
        count++;
    }
   
    if (count < 1)
      spieler.push_back(*it);
    else
      doubles.push_back(*it);
    count = 0;
    ++it;
  }
  return doubles;
}
  
  string aufstellung() const{
  if(spieler.size()!= 11)
    throw runtime_error{"Ungültige Spieleranzahl"};
	int a{0}, b{0}, c{0}, d{0};
  string aufstellung;
      
    for(const auto& s:spieler){
    	if(s.get_position() == Position::Tor)
        	a++;
      if(s.get_position() == Position::Abwehr)
        	b++;
       if(s.get_position() == Position::Mitte)
        	c++;
       if(s.get_position() == Position::Sturm)
        	d++;
    }  
    if(a != 1)
      throw runtime_error{"Ungültuges Tor"};
    aufstellung = to_string(b)+"-"+to_string(c)+"-"+to_string(d);
    return aufstellung;
  }
  
vector<Spieler> entlassen(vector<Position> p){
	vector<Spieler> entlassen;
	auto it{spieler.begin()};
  bool match{false};
		while (it != end(spieler)){
      for(auto& w : p ){
        if (it->get_position() == w )
        	match = true;
      } 
      if(match){
        entlassen.push_back(*it);
        it = spieler.erase(it);
      }
      else
        ++it;
      
      match = false;
        
    }
	
	return entlassen;
}
    
  
  ostream& print(ostream&o)const{
  	o << "[" << m_name << ", {";
      if(spieler.empty())
      o << "}]";
    
    size_t i{1};
    for(const auto& s:spieler){ 
    	o << s << (i < spieler.size() ? ", " : "}]");
        ++i;
   	}
     return o;
    }
};

  inline ostream& operator<<(ostream&o, const Mannschaft&m){
  return m.print(o);
  }
#endif
