#include <iostream>
using namespace std;
#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"
#include "Player.hpp"
#include "Medic.hpp"
namespace pandemic{
    Medic::Medic(Board& b,City c): Player(b,c){}
    Player& Medic::drive(City c){
        City city=this->current_city;
        this->Player::drive(c);
        Color color=this->board.city_color(this->current_city);
        if (city!=this->current_city && this->board.is_cure(color))
        {
            this->board[this->current_city]=0;
        }
        return *this;
    }
    Player& Medic::fly_direct(City c){
        City city=this->current_city;
        this->Player::fly_direct(c);
        Color color=this->board.city_color(this->current_city);
        if (city!=this->current_city && this->board.is_cure(color))
        {
            this->board[this->current_city]=0;
        }
        return *this;
    }
    Player& Medic::fly_charter(City c){
        City city=this->current_city;
        this->Player::fly_charter(c);
        Color color=this->board.city_color(this->current_city);
        if (city!=this->current_city && this->board.is_cure(color))
        {
            this->board[this->current_city]=0;
        }
        return *this;
    }
    Player& Medic::fly_shuttle(City c){
        City city=this->current_city;
        this->Player::fly_shuttle(c);
        Color color=this->board.city_color(this->current_city);
        if (city!=this->current_city && this->board.is_cure(color))
        {
            this->board[this->current_city]=0;
        }
        return *this;
    }
    Player& Medic::treat(City c){
        this->Player::treat(c);
        this->board[this->current_city]=0;
        return *this;
    }
    string Medic::role(){return string("Medic");}
};