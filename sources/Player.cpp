#include "Game.hpp"
#include "Player.hpp"
using namespace std;

namespace coup
{

    Player::Player(coup::Game & game , std::string name){
        // constuctor
        this->_name = std::move(name);
        this->_game = & game;
        this->_coins = 0;
        this->_last_act = 0;
        this->_turn = (int)game.players().size();
        this->_in_game = true;
        this->_game->add_player(this);
        this->_coup = NULL;
        this->_from = NULL;
    }

    void Player::income(){
        this->_game->make_start();
        const int coins = 10;
        game_ended();
        amount_players();
        my_turn();
        if (this->_coins>=coins){
            throw std::domain_error("should coup");
        }
        this->_coins += 1;
        this->_last_act = INCOME;
        this->_game->update_turn();
    }

    void Player::foreign_aid(){
        this->_game->make_start();
        const int coins = 10;
        game_ended();
        amount_players();
        my_turn();
        if (this->_coins>=coins){
            throw std::domain_error("should coup");
        }
        this->_coins += 2;
        this->_last_act = FOREIGN_AID;
        this->_game->update_turn();
    }

    void Player::coup(coup::Player & other){
        this->_game->make_start();
        const int coins = 7;
        game_ended();
        amount_players();
        my_turn();
        same_game(other);
        if (this->_coins<coins){
            throw std::domain_error("not enough coins");
        }
        if (!other._in_game){
            throw std::domain_error("player not in game");
        }
        other._in_game = false;
        this->_coins -= coins;
        this->_last_act = COUP;
        this->_game->update_turn();
    }

    int Player::coins() const{
        return this->_coins;
    }

    std::string Player::role(){
        return "--";
    }

    void Player::my_turn(){
        if (this->_turn != this->_game->turn_num()){
            throw std::domain_error("incorrect turn");
        }
    }

    void Player::game_ended(){
        try{
            this->_game->winner();
            throw std::domain_error("game ended");
        }
        catch(...){
        }
    }

    void Player::game_started(){
        if (!this->_game->start()){
            throw std::domain_error("game didn't start yet");
        }
    }

    void Player::amount_players(){
        const int f = 2;
        const int t = 6;
        if (this->_game->last_player()<f || this->_game->last_player()>t){
            throw std::domain_error("not a good amount of players");
        }
    }

    Game * Player::my_game(){
        return this->_game;
    }

    void Player::same_game(coup::Player & other){
        if (this->_game != other.my_game()){
            throw std::domain_error("players are not from the same game");
        }
    }

    Player* Player::coup_to(){
        return this->_coup;
    }

    Player* Player::stealed_from(){
        return this->_from;
    }

    Player::~Player(){
    }

}