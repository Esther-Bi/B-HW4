#include "Game.hpp"
#include "Player.hpp"
using namespace std;

namespace coup
{

    Game::Game(){
        // constuctor
        this->_turn = 0;
        this->_winner = "?";
        this->_started = false;
    }

    int Game::last_player()const{
        return this->_players.size();
    }

    std::string Game::turn(){
        return this->_players.at((unsigned long)this->_turn)->_name;
    }

    int Game::turn_num()const{
        return this->_turn;
    }

    void Game::update_turn(){
        int in_game = 0;
        Player * who = 0;
        for(Player *p : this->_players){
            if (p->_in_game){
                in_game++;
                who = p;
            }
        }
        if (in_game != 1){
            this->_turn = (this->_turn + 1) % (int)this->_players.size();
            if (!this->_players.at((unsigned long)this->_turn)->_in_game){
                update_turn();
            }
        }
        else{
            this->_winner = who->_name;
        }
    }

    std::vector<std::string> Game::players()const{
        std::vector<string> players;
        for(Player *p : this->_players){
            if (p->_in_game){
                players.push_back(p->_name);
            }  
        }
        return players;
    }

    std::string Game::winner()const{
        if (this->_winner == "?"){
            throw std::domain_error("there is no winner yet");
        }
        return this->_winner;
    }

    void Game::add_player(coup::Player * player){
        const int up_to = 6;
        if (this->last_player() == up_to){
            throw std::domain_error("can't add more than 6 players");
        }
        if (this->_started){
            throw std::domain_error("game started");
        }
        this->_players.push_back(player);
    }

    bool Game::start()const{
        return this->_started;
    }

    void Game::make_start(){
        if (this->last_player() < 2){
            throw std::domain_error("can't start with less than 2 players");
        }
        this->_started = true;
    }

    Game::~Game(){
    }

}