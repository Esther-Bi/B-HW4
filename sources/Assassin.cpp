#include "Game.hpp"
#include "Player.hpp"
#include "Assassin.hpp"
using namespace std;

namespace coup
{

    Assassin::Assassin(coup::Game & game , string name) : Player(game,std::move(name)){
        // constuctor
        this->_coup = NULL;
    }

    void Assassin::coup(coup::Player & other){
        if (!other._in_game || !this->_in_game){
            throw std::domain_error("one of players not in game");
        }
        this->_game->make_start();
        if (this->_coins<3){
            throw std::domain_error("player has less than 3 coins");
        }
        const int coins = 7;
        if (this->_coins >= coins){
            Player::coup(other);
            this->_last_act = INCOME; // so he will not be blocked
        }
        else{
            this->game_ended();
            this->amount_players();
            this->my_turn();
            this->same_game(other);
            this->_coup = & other;
            other._in_game = false;
            this->_coins -= 3;
            this->_last_act = COUP;
            this->_game->update_turn();
        }
    }

    std::string Assassin::role(){
        return "Assassin";
    }

    // Player* Assassin::coup_to(){
    //     return this->_coup;
    // }

    Assassin::~Assassin(){
    }

}