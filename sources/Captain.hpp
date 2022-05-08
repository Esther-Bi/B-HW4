#include <iostream>
#include <string>
#include "Game.hpp"
#include "Player.hpp"
using namespace std;

#ifndef CAPTAIN_HEADER
#define CAPTAIN_HEADER

namespace coup{

    class Captain : public Player{
        private:
            // int p_role;
        public:
            Captain(coup::Game & game , string name);
            void steal(coup::Player & other);
            void block(coup::Player & other);
            std::string role();
            ~Captain();

    };

}

#endif