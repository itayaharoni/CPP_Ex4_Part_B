#include <iostream>
#include <string>
using namespace std;
#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"
#include "Player.hpp"
#include "Virologist.hpp"
namespace pandemic{
    Virologist::Virologist(Board& b,City c): Player(b,c){}
    Player& Virologist::treat(City c){
        if (this->board[c]==0)
        {
            throw out_of_range{"Can't treat a city with 0 disease lvl."};
        }
        if(this->current_city!=c){
            if(this->hand_cards.find(c)==this->hand_cards.end() || this->hand_cards[c]==0){
            throw out_of_range{"Must be in a city to treat it error."};
            }
        this->hand_cards[c]=0;
        }
        City city=this->current_city;
        Color color=this->board.city_color(city);
        if(this->board.is_cure(color)){
            this->board[c]=0;
        }else{
            this->board[c]--;
        }
        return *this; 
    }
    string Virologist::role(){return string("Virologist");}
};