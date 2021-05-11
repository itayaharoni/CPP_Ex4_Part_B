#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"
#include "Player.hpp"
namespace pandemic{
    Player::Player(Board& b,City c): board{b},current_city{c}{}
    Player& Player::drive(City c){ 
        if(this->current_city==c){
            throw out_of_range{"Can't drive to the city you are already in."};
        }
        if(!(this->board.drive(this->current_city,c))){
            throw out_of_range{"Can't drive the two cities aren't connected!"};
        }
        this->current_city=c;
        return *this; 
    }
    Player& Player::fly_direct(City c){
        if(this->current_city==c){
            throw out_of_range{"Can't fly to the city you are already in."};
        }
        if(this->hand_cards.find(c)==this->hand_cards.end() || this->hand_cards[c]==0){
            throw out_of_range{"Insufficient number of cards to commit this action."};
        }
        hand_cards[c]=0;
        this->current_city=c;
        return *this;     
    }
    Player& Player::fly_charter(City c){
        if(this->current_city==c){
            throw out_of_range{"Can't fly to the city you are already in."};
        }
        if(this->hand_cards.find(this->current_city)==this->hand_cards.end()
        || this->hand_cards[this->current_city]==0){
            throw out_of_range{"Insufficient number of cards to fly-charter."};
        }
        hand_cards[this->current_city]=0;
        this->current_city=c;
        return *this;   
        }
    Player& Player::fly_shuttle(City c){
        if(this->current_city==c){
            throw out_of_range{"Can't fly to the city you are already in."};
        }
         if(!(this->board.is_research_city(c) && this->board.is_research_city(this->current_city)))
         {
            throw out_of_range{"Invalid action while shuttle-flying."};
         }
         this->current_city=c;
         return *this; 
         }
    void Player::build(){
        if (this->board.is_research_city(this->current_city))
        {
            return;
        }
        if(this->hand_cards.find(this->current_city)==this->hand_cards.end()){
            throw out_of_range{"Insufficient number of cards to build."};
        }
        if(this->hand_cards[this->current_city]==0){
            throw out_of_range{"Insufficient number of cards to build."};
        }
        this->hand_cards[this->current_city]=0;
        this->board.build(this->current_city);
    }
    
    void Player::discover_cure(Color c){
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

    Player& Player::treat(City c){
        if(this->current_city!=c){
            throw out_of_range{"Must be in a city to treat it error."};
        }
        if (this->board[c]==0)
        {
            throw out_of_range{"Can't treat a city with 0 disease lvl."};
        }
        City city=this->current_city;
        Color color=this->board.city_color(city);
        if(this->board.is_cure(color)){
            this->board[this->current_city]=0;
        }else{
            this->board[this->current_city]--;
        }
        return *this; 
        }
    string Player::role(){ return string("Player"); }
    Player& Player::take_card(City c){ 
            this->hand_cards[c]=1;
        return *this; 
    }
    void Player::remove_cards(){
        unordered_map<City,unsigned int> temp;
        this->hand_cards=temp;
    }
};