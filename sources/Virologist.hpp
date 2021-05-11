#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"
#include "Player.hpp"
namespace pandemic{
class Virologist: public Player{
    public:
    Virologist(Board& b,City c);
    Player& treat(City c);
    string role();
};
};