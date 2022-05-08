#include "Game.hpp"
#include "Player.hpp"
#include "Captain.hpp"
using namespace std;

namespace coup
{

    Captain::Captain(coup::Game & game , string name) : Player(game,std::move(name)){
        // constuctor
        this->_from = NULL;
    }

    void Captain::steal(coup::Player & other){
        if (!other._in_game || !this->_in_game){
            throw std::domain_error("one of players not in game");
        }
        this->_game->make_start();
        this->game_ended();
        this->amount_players();
        this->my_turn();
        this->same_game(other);
        const int coins = 10;
        if (this->_coins>=coins){
            throw std::domain_error("should coup");
        }
        if (other.coins()<2){
            this->_coins += other._coins;
            other._coins = 0 ;
        } else{
            other._coins -= 2;
            this->_coins += 2;
        }
        this->_from = & other;
        this->_last_act = STEAL;
        this->_game->update_turn();
    }

    void Captain::block(coup::Player & other){
        if (!other._in_game || !this->_in_game){
            throw std::domain_error("one of players not in game");
        }
        if (other.role() != "Captain"){
            throw std::domain_error("blocks only captain");
        }
        this->game_started();
        this->game_ended();
        this->same_game(other);
        if (other._last_act != STEAL){
            throw std::domain_error("incorrect blocking");
        }
        other.stealed_from()->_coins += 2;
        other._coins -= 2;
        other._last_act = INCOME; // so he will not be blocked again
    }

    std::string Captain::role(){
        return "Captain";
    }

    Captain::~Captain(){
    }

}