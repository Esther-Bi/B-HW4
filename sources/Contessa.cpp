#include "Game.hpp"
#include "Player.hpp"
#include "Contessa.hpp"
using namespace std;

namespace coup
{

    Contessa::Contessa(coup::Game & game , string name) : Player(game,std::move(name)){
        // constuctor
        // this->p_role = CO;
    }

    void Contessa::block(coup::Player & other){
        if (!other._in_game || !this->_in_game){
            throw std::domain_error("one of players not in game");
        }
        if (other.role() != "Assassin"){
            throw std::domain_error("blocks only captain");
        }
        this->game_started();
        this->game_ended();
        this->same_game(other);
        if (other._last_act != COUP){
            throw std::domain_error("incorrect blocking");
        }
        other.coup_to()->_in_game = true;
        other._last_act = INCOME; // so he will not be blocked again
    }

    std::string Contessa::role(){
        return "Contessa";
    }

    Contessa::~Contessa(){
    }

}