#include <iostream>
#include <string>
using namespace std;
#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"
#include "Player.hpp"
#include "Dispatcher.hpp"
namespace pandemic{
    Dispatcher::Dispatcher(Board& b,City c):Player(b,c){}
    Player& Dispatcher::fly_direct(City c){
        if(this->current_city==c){
            throw out_of_range{"Can't fly to the city you are already in."};
        }
        if(this->board.is_research_city(this->current_city)){
            this->current_city=c;
        }else{
            this->Player::fly_direct(c);
        }
        return *this;
    }

    Player& Dispatcher::fly_charter(City c){
        if(this->current_city==c){
            throw out_of_range{"Can't fly to the city you are already in."};
        }
        if(this->board.is_research_city(this->current_city)){
            this->current_city=c;
        }else{
            this->Player::fly_charter(c);
        }
        return *this;
    }

    Player& Dispatcher::fly_shuttle(City c){
        if(this->current_city==c){
            throw out_of_range{"Can't fly to the city you are already in."};
        }
        if(this->board.is_research_city(this->current_city)){
            this->current_city=c;
        }else{
            this->Player::fly_shuttle(c);
        }
        return *this;
    }
    string Dispatcher::role(){return string("Dispatcher");}
};