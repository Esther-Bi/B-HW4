#include <iostream>
#include <string>
#include "Game.hpp"
#include "Player.hpp"
#include "Captain.hpp"
using namespace std;

#ifndef AMBASSADOR_HEADER
#define AMBASSADOR_HEADER

namespace coup{

    class Ambassador : public Player{
        // private:
            // int p_role;
        public:
            Ambassador(coup::Game & game , string name);
            void transfer(coup::Player & from, coup::Player & to);
            void block(coup::Player & other);
            std::string role();
            ~Ambassador();

    };

}

#endif