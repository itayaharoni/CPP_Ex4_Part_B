#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"
#include "Player.hpp"
namespace pandemic{
class Dispatcher: public Player{
    public:
    Dispatcher(Board& b,City c);
    Player& fly_direct(City c);
    Player& fly_charter(City c);
    Player& fly_shuttle(City c);
    string role();
};
};