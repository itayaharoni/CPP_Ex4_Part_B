#pragma once
#include <iostream>
using namespace std;
#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"
#include "Player.hpp"
namespace pandemic{
class Medic: public Player{
    public:
    Medic(Board& b,City c);
    Player& drive(City c);
    Player& fly_direct(City c);
    Player& fly_charter(City c);
    Player& fly_shuttle(City c);
    Player& treat(City c);
    string role();
};
};