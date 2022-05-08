#include <iostream>
#include <string>
#include "Game.hpp"
#include "Player.hpp"
#include "Assassin.hpp"
using namespace std;

#ifndef CONTESSA_HEADER
#define CONTESSA_HEADER

namespace coup{

    class Contessa : public Player{
        public:
            Contessa(coup::Game & game , string name);
            void block(coup::Player & other);
            std::string role();
            ~Contessa();

    };

}

#endif