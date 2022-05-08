#include "Game.hpp"
#include "Player.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
using namespace std;

namespace coup
{

    Ambassador::Ambassador(coup::Game & game , string name) : Player(game,std::move(name)){
        // constuctor
        // this->p_role = AM;
    }

    void Ambassador::transfer(coup::Player & from, coup::Player & to){
        if (!from._in_game || !to._in_game){
            throw std::domain_error("one of players not in game");
        }
        this->_game->make_start();
        this->game_ended();
        this->amount_players();
        this->my_turn();
        this->same_game(from);
        this->same_game(to);
        const int coins = 10;
        if (this->_coins>=coins){
            throw std::domain_error("should coup");
        }
        if (from.coins()<1){
            throw std::domain_error("one of players has less than 1 coin");
        }
        from._coins -= 1;
        to._coins += 1;
        this->_last_act = TRANSFER;
        this->_game->update_turn();
    }

    void Ambassador::block(coup::Player & other){
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

    std::string Ambassador::role(){
        return "Ambassador";
    }

    Ambassador::~Ambassador(){
    }

}