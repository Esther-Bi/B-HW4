#include <iostream>
#include <string>
#include "Game.hpp"
#include "Player.hpp"
using namespace std;

#ifndef ASSASSIN_HEADER
#define ASSASSIN_HEADER

namespace coup{

    class Assassin : public Player{
        public:
            Assassin(coup::Game & game , string name);
            void coup(coup::Player & other); // של עצמו מיוחד
            std::string role();
            ~Assassin();

    };

}

#endif