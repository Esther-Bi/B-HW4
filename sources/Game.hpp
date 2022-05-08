#include <iostream>
#include <string>
#include <vector>
// #include <bits/stdc++.h>
using namespace std;

#pragma once
#ifndef GAME_HEADER
#define GAME_HEADER

namespace coup{

    class Player;
    class Game{
        private:
            int _turn;
            std::vector<Player*> _players;
            std::string _winner;
            bool _started;
        public:
            Game();
            int last_player()const;
            std::string turn();
            int turn_num()const;
            void update_turn();
            std::vector<std::string> players()const;
            std::string winner()const;
            void add_player(Player * player);
            bool start()const;
            void make_start();
            ~Game();

    };

}

#endif