#include <iostream>
#include <string>
#include "Game.hpp"
using namespace std;

#pragma once
#ifndef PLAYER_HEADER
#define PLAYER_HEADER

namespace coup{

    const int mag = 8;

    const int INCOME = 1;
    const int FOREIGN_AID = 2;
    const int COUP = 3;
    const int BLOCK = 4;
    const int TAX = 5;
    const int TRANSFER = 6;
    const int STEAL = 7;

    const int DU = 11;
    const int AS = 22;
    const int AM = 33;
    const int CA = 44;
    const int CO = 55;

    class Game;
    class Player{
        protected:
            coup::Game * _game;
            Player * _coup;
            Player * _from;
        
        public:
            std::string _name;
            int _turn;
            int _coins;
            int _last_act;
            bool _in_game;

            Player(coup::Game & game , std::string name);
            void income();
            void foreign_aid();
            virtual void coup(coup::Player & other);
            int coins()const;
            virtual std::string role();
            void my_turn();
            void game_ended();
            void game_started();
            void amount_players();
            Game * my_game();
            void same_game(coup::Player & other);
            Player* coup_to();
            Player* stealed_from();
            ~Player();

    };

}

#endif