#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"
#include "Player.hpp"
namespace pandemic{
class Researcher: public Player{
    public:
    Researcher(Board& b,City c);
    void discover_cure(Color c);
    string role();
};
};