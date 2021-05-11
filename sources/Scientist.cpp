#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"
#include "Player.hpp"
#include "Scientist.hpp"
namespace pandemic{
    Scientist::Scientist(Board& b,City c,int n): Player(b,c),n{n}{}
    void Scientist::discover_cure(Color c){
        if(this->board.is_cure(c)){
            return;
        }
        if (!this->board.is_research_city(this->current_city))
        {
            throw out_of_range{"Can't discover cure in a city without a research station."};
        }
        unsigned int num_of_cards=0;
        unordered_map<City,unsigned int>::iterator itr;
        vector<City> v;
        for (itr=this->hand_cards.begin(); itr!=this->hand_cards.end() ; itr++)
        {
            if(num_of_cards==this->n){
                break;
            }
            City city=itr->first;
            if(this->board.city_color(city)==c){
                this->hand_cards[city]=0;
                num_of_cards++;               
            }
        }
        if (num_of_cards!=this->n)
        {
            throw out_of_range{"Insufficient number of cards to discover cure."};
        }
        this->board.discover_cure(c);
    }
    string Scientist::role(){return string("Scientist");}
};