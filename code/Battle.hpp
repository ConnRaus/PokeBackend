#ifndef BATTLE_HPP
#define BATTLE_HPP

#include "Player.hpp"

class Battle {

    public:
        Battle(Player& player1, Player& player2) : player1_(player1), player2_(player2) {}
        // get player1 and player2's pokemon health (first in party)
        int battle(Player& player1, Player& player2) {
            Pokemon player1Pokemon = player1.party()[0];
            Pokemon player2Pokemon = player2.party()[0];

            // get health stats
            int pokemon1Health = player1Pokemon.stats()[0];
            int pokemon2Health = player2Pokemon.stats()[0];



            // while both pokemon are alive, continue battle
            while (pokemon1Health > 0 && pokemon2Health > 0) {
                // player1's turn
                // player1 chooses fight or switch
                // player1's move is used on player2's pokemon
                // player2's pokemon's health is updated
                // player2's turn
                // player2 chooses move
                // player2's move is used on player1's pokemon
                // player1's pokemon's health is updated
            }
            // if player1's pokemon is alive, player1 wins
            if (pokemon1Health > 0) {
                return 1;
            // if player2's pokemon is alive, player2 wins
            } else if (pokemon2Health > 0) {
                return 2;
            // if both pokemon are dead, it's a tie
            } else {
                return 0;
            }
        }


    private:
        Player& player1_;
        Player& player2_;

}


#endif