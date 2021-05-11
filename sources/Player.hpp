#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"
#include <unordered_map>
namespace pandemic{
class Player{
    protected:
        Board& board;
        City current_city;
        unordered_map<City,unsigned int> hand_cards;
    public:
        Player(Board& b,City c);
        virtual Player& drive(City c);
        virtual Player& fly_direct(City c);
        virtual Player& fly_charter(City c);
        virtual Player& fly_shuttle(City c);
        virtual void build();
        virtual void discover_cure(Color c);
        virtual Player& treat(City c);
        virtual string role();
        Player& take_card(City c);
        void remove_cards();
};
};