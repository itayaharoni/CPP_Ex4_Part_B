#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
#include "City.hpp"
#include "Color.hpp"
namespace pandemic{
    
class Board{
    unordered_map<City,int> disease_lvl;
    unordered_map<City,unordered_map<City,bool>> connectivity;
    unordered_map<City,Color> color;
    unordered_map<Color, bool> cures;
    unordered_map<City,string> names;
    unordered_map<City,bool> stations;

    string color_to_string(const Color& c);

    public:
    Board();
    int& operator[](City c);
    friend ostream& operator<<(ostream& output,Board& b);
    bool is_clean();
    void remove_cures();
    void remove_stations();
    bool drive(City from, City to);
    bool is_research_city(City c);
    void build(City c);
    bool is_cure(Color c);
    void discover_cure(Color c);
    Color city_color(City c);
    bool is_connected(City a,City b);
};
};