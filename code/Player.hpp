#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include "Pokemon.hpp"

class Player {
    private:
        std::vector<Pokemon> party_;
        std::string name_;

    public:
        Player(const std::string& name);
        std::string name() const;
        std::vector<Pokemon>& party();
        void add_pokemon(const Pokemon& pokemon);
        void remove_pokemon(int index);
        void print_party();
};

#endif