#include <iostream>
#include <string>
using namespace std;
#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"
#include "Player.hpp"
#include "Researcher.hpp"
namespace pandemic{
    Researcher::Researcher(Board& b,City c):Player(b,c){}
    void Researcher::discover_cure(Color c){
        const int FIVE=5;
        if(this->board.is_cure(c)){
            return;
        }
        unsigned int num_of_cards=0;
        unordered_map<City,unsigned int>::iterator itr;
        for (itr=this->hand_cards.begin(); itr!=this->hand_cards.end() ; itr++)
        {
            City city=itr->first;
            if(this->board.city_color(city)==c){
                this->hand_cards[city]=0;
                num_of_cards++;
            }
            if(num_of_cards==FIVE){
                break;
            }
        }
        if (num_of_cards!=FIVE)
        {
            throw out_of_range{"Insufficient number of cards to discover cure."};
        }
        this->board.discover_cure(c);
    }
    string Researcher::role(){return string("Researcher");}
};