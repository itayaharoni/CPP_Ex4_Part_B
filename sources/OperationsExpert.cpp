#include <iostream>
#include <string>
using namespace std;
#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"
#include "Player.hpp"
#include "OperationsExpert.hpp"
namespace pandemic{
    OperationsExpert::OperationsExpert(Board& b,City c):Player(b,c){}
    void OperationsExpert::build(){
        this->board.build(this->current_city);
    }
    string OperationsExpert::role(){return string("OperationsExpert");}
};