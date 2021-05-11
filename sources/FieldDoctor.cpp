#include <iostream>
#include <string>
using namespace std;
#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"
#include "Player.hpp"
#include "FieldDoctor.hpp"
namespace pandemic{
    FieldDoctor::FieldDoctor(Board& b,City c):Player(b,c){}
    Player& FieldDoctor::treat(City c){
        if(this->current_city!=c && !(this->board.is_connected(this->current_city,c))){
            throw out_of_range{"Must be in a city to treat it error."};
        }
        if (this->board[c]==0)
        {
            throw out_of_range{"Can't treat a city with 0 disease lvl."};
        }
        Color color=this->board.city_color(c);
        if(this->board.is_cure(color)){
            this->board[c]=0;
        }else{
            this->board[c]=this->board[c]-1;
        }
        return *this;
    }
    string FieldDoctor::role(){return string("FieldDoctor");}
};