#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"
#include "Player.hpp"
#include "GeneSplicer.hpp"
namespace pandemic{
    GeneSplicer::GeneSplicer(Board& b,City c): Player(b,c){}
    void GeneSplicer::discover_cure(Color c){
        const int FIVE=5;
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
            City city=itr->first;
            if(this->hand_cards[city]>0){
                v.push_back(city);
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
        for (unsigned int i = 0; i < FIVE; i++)
        {
            this->hand_cards[v[i]]=0;
        }
        
        this->board.discover_cure(c);   
    }
    string GeneSplicer::role(){return string("GeneSplicer");}
};