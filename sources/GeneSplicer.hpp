#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"
#include "Player.hpp"
namespace pandemic{
class GeneSplicer: public Player{
    public:
    GeneSplicer(Board& b,City c);
    void discover_cure(Color c);
    string role();
};
};