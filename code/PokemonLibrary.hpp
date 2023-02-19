#ifndef POKEMON_LIBRARY_HPP
#define POKEMON_LIBRARY_HPP

#include <map>
#include <string>
#include "Pokemon.hpp"
#include "Move.hpp"
#include "MoveLibrary.hpp"

class PokemonLibrary {
    private:
        std::map<std::string, PokemonBase> library_;

    public:
        PokemonLibrary();
        PokemonBase get_pokemon(const std::string& name);
        void add_pokemon(const std::string& name, const PokemonBase& pokemon);
        void remove_pokemon(const std::string& name);
        void import_pokemon(const std::string& filename, MoveLibrary& move_library);
        void print_pokemon(const std::string& name);
};

#endif
