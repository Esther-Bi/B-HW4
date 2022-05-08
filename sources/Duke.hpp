#include <iostream>
#include <string>
#include "Game.hpp"
#include "Player.hpp"
using namespace std;

#pragma once
#ifndef DUKE_HEADER
#define DUKE_HEADER

namespace coup{

    class Duke : public Player{
        // private:
        //     int p_role;
        public:
            Duke(coup::Game & game , string name);
            void tax();
            void block(coup::Player & other);
            std::string role();
            ~Duke();

    };

}

#endif