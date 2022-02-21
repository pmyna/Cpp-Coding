#ifndef Sammlung_hpp
#define Sammlung_hpp

#include <string>
#include <vector>

using namespace std;

class Album{
    string interpret;
    string titel;
    string stil;
    
public:
    Album();
    
    void set_interpret(const string interpret);
    void set_titel(const string titel);
    void set_stil(const string stil);
    
    string get_interpret() const;
    string get_titel() const;
    string get_stil() const;
};

class Collection{
    vector<Album>collection;
    
public:
    void new_album(vector<Album>&collection);
    void change_album(vector<Album>&collection);
    void delete_album(vector<Album>&collection);
    void search_album(vector<Album>&collection);
};

#endif
