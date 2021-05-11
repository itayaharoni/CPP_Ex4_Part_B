#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"
#include "Player.hpp"
namespace pandemic{
class Scientist: public Player{
    int n;
    public:
    Scientist(Board& b,City c,int n);
    void discover_cure(Color c);
    string role();
};
};