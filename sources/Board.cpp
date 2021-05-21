#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <unordered_map>
using namespace std;
#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"
namespace pandemic{
    
    string color_to_string(const Color c){
        string ans;
        if(c==Color::Black){
            ans="Black";
        }else if(c==Color::Blue){
            ans="Blue";
        }else if(c==Color::Yellow){
            ans="Yellow";
        }else{
            ans="Red";
        }
        return ans;
    }

    Color string_to_color(const string& str){
        Color ans;
        if(str=="Black"){
            ans= Color::Black;
        }else if(str=="Blue"){
            ans= Color::Blue;
        }else if(str=="Yellow"){
            ans= Color::Yellow;
        }else{
            ans=Color::Red;
        }
        return ans;
    }

    Board::Board(){
        ifstream city_file{"cities_map.txt"};
        string line;
        while(getline(city_file,line)){
            stringstream words{line};
            string city_name;
            string city_color;
            string city_neighbor;
            words >> city_name >> city_color;
            color[pandemic::string_to_enum[city_name]]=string_to_color(city_color);
            if(names.find(pandemic::string_to_enum[city_name])==names.end()){
                names[pandemic::string_to_enum[city_name]]=city_name;
            }
            while(words >> city_neighbor){
                connectivity[pandemic::string_to_enum[city_name]][pandemic::string_to_enum[city_neighbor]]=true;
                connectivity[pandemic::string_to_enum[city_neighbor]][pandemic::string_to_enum[city_name]]=true;
            }
        }
    }

    int& Board::operator[](City c){
        return this->disease_lvl[c];
    }
    ostream& operator<<(ostream& output,Board& b){
        output << "Diesease level according to cities:" << endl;
        unordered_map<City,int> :: iterator itr_disease;
        for ( itr_disease=b.disease_lvl.begin() ; itr_disease != b.disease_lvl.end(); itr_disease++)
        {
            output << b.names[itr_disease->first] << " : " << itr_disease->second << endl;
        }
        unordered_map<Color,bool> :: iterator itr_cures;
        output << endl << "Cures exists for the following colors:" << endl;
        for ( itr_cures = b.cures.begin(); itr_cures!= b.cures.end() ; itr_cures++)
        {
            if(itr_cures->second){
                output << color_to_string(itr_cures->first) << endl;
            }
        }
        unordered_map<City,bool> :: iterator itr_stations;
        output << endl << "Reasearch stations exists in the following cities:" << endl;
        for ( itr_stations = b.stations.begin(); itr_stations!= b.stations.end() ; itr_stations++)
        {
            if(itr_stations->second){
                output << b.names[itr_stations->first] << endl;
            }
        }
        return output;
    }
    bool Board::is_clean(){
        unordered_map<City,int>::iterator itr_disease;
        for (itr_disease=disease_lvl.begin() ; itr_disease!=disease_lvl.end() ; itr_disease++)
        {
            if (itr_disease->second!=0)
            {
                return false;
            }
        }
        return true;
    }

    void Board::remove_cures(){
        unordered_map<Color,bool> :: iterator itr_cures;
        for ( itr_cures = this->cures.begin(); itr_cures!= this->cures.end() ; itr_cures++)
        {
            itr_cures->second=false;
        }
    }

    void Board::remove_stations(){
        unordered_map<City,bool> :: iterator itr_stations;
        for ( itr_stations = this->stations.begin(); itr_stations!= this->stations.end() ; itr_stations++)
        {
            itr_stations->second=false;
        }
    }

    bool Board::drive(City from, City to){
        bool flag=true;
        if(this->connectivity[from].find(to)==this->connectivity[from].end()) {
            flag= false;
        }
        return flag;
    }

    bool Board::is_research_city(City c){
        if (stations.find(c)==stations.end())
        {
            return false;
        }
        return stations[c];
    }

    void Board::build(City c){
        this->stations[c]=true;
    }

    bool Board::is_cure(Color c){
        if (this->cures.find(c)==this->cures.end())
        {
            return false;
        }
        return this->cures[c];
    }

    void Board::discover_cure(Color c){
        this->cures[c]=true;
    }

    Color Board::city_color(City c){
        return this->color[c];
    }


    bool Board::is_connected(City a,City b){
        bool flag=true;
        if (this->connectivity[a].find(b)==this->connectivity[a].end())
        {
            flag= false;
        }
        return flag;
    }
};
