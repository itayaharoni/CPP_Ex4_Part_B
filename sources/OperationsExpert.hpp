#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"
#include "Player.hpp"
namespace pandemic{
class OperationsExpert: public Player{
    public:
    OperationsExpert(Board& b,City c);
    void build();
    string role();
};
};