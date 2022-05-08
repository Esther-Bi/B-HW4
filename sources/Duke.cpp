#include "Game.hpp"
#include "Player.hpp"
#include "Duke.hpp"
using namespace std;

namespace coup
{

    Duke::Duke(coup::Game & game , string name) : Player(game,std::move(name)){
        // constuctor
        // this->p_role = DU;
    }

    void Duke::tax(){
        this->_game->make_start();
        this->game_ended();
        this->amount_players();
        this->my_turn();
        const int coins = 10;
        if (this->_coins>=coins){
            throw std::domain_error("should coup");
        }
        this->_coins += 3;
        this->_last_act = TAX;
        this->_game->update_turn();
    }

    void Duke::block(coup::Player & other){
        if (!other._in_game || !this->_in_game){
            throw std::domain_error("one of players not in game");
        }
        this->game_started();
        this->game_ended();
        this->same_game(other);
        if (other._last_act != FOREIGN_AID){
            throw std::domain_error("incorrect blocking");
        }
        other._coins -= 2;
        other._last_act = INCOME; // so he will not be blocked again
    }

    std::string Duke::role(){
        return "Duke";
    }

    Duke::~Duke(){
    }

}