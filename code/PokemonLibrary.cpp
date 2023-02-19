#include "PokemonLibrary.hpp"
#include "MoveLibrary.hpp"
#include "Pokemon.hpp"
#include "Move.hpp"
#include "Type.hpp"
#include <iostream>
#include <fstream>

PokemonLibrary::PokemonLibrary() {
    MoveLibrary move_library;

    import_pokemon("data/pokemonlist.csv", move_library);
}

PokemonBase PokemonLibrary::get_pokemon(const std::string& name) {
    return library_.at(name);
}

void PokemonLibrary::add_pokemon(const std::string& name, const PokemonBase& pokemon) {
    library_.emplace(name, pokemon);
}

void PokemonLibrary::remove_pokemon(const std::string& name) {
    library_.erase(name);
}

void PokemonLibrary::print_pokemon(const std::string &name) {
//    check if pokemon exists
    if (library_.find(name) == library_.end()) {
        std::cout << "Pokemon not found: " << name << std::endl;
        return;
    }

    PokemonBase pokemon = library_.at(name);
    pokemon.print_pokemon();

}

void PokemonLibrary::import_pokemon(const std::string& filename, MoveLibrary& move_library) {
    // import pokemon from file
    // File will be in the format:
    // id,name,type1,type2,hp,attack,defense,sp_attack,sp_defense,speed,move1,move2,move3,move4

    // open file
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error opening file: " << filename << std::endl;
        return;
    }

    // read file
    std::string line;
    while (std::getline(file, line)) {
    
        // Get basic pokemon info (id, name, types)
        // get id
        int id = std::stoi(line.substr(0, line.find(',')));

        // get name
        line = line.substr(line.find(',') + 1);
        std::string name = line.substr(0, line.find(','));

        // Get types
        std::vector<Type> types;

        // type1
        line = line.substr(line.find(',') + 1);
        std::string type1 = line.substr(0, line.find(','));
        types.push_back(Type(type1));

        // type2
        line = line.substr(line.find(',') + 1);
        std::string type2 = line.substr(0, line.find(','));
        if (type2 != "None") {
            types.push_back(Type(type2));
        }




        // Get base stats (hp, attack, defense, sp_attack, sp_defense, speed)
        std::array<int, 6> base_stats;

        // get hp
        line = line.substr(line.find(',') + 1);
        int hp = std::stoi(line.substr(0, line.find(',')));
        base_stats[0] = hp;

        // get attack
        line = line.substr(line.find(',') + 1);
        int attack = std::stoi(line.substr(0, line.find(',')));
        base_stats[1] = attack;

        // get defense
        line = line.substr(line.find(',') + 1);
        int defense = std::stoi(line.substr(0, line.find(',')));
        base_stats[2] = defense;

        // get sp_attack
        line = line.substr(line.find(',') + 1);
        int sp_attack = std::stoi(line.substr(0, line.find(',')));
        base_stats[3] = sp_attack;

        // get sp_defense
        line = line.substr(line.find(',') + 1);
        int sp_defense = std::stoi(line.substr(0, line.find(',')));
        base_stats[4] = sp_defense;

        // get speed
        line = line.substr(line.find(',') + 1);
        int speed = std::stoi(line.substr(0, line.find(',')));
        base_stats[5] = speed;




        // Get possible moves (rest of line)
        std::vector<Move> possible_moves;
        while (line.find(',') != std::string::npos) {
            line = line.substr(line.find(',') + 1);
            std::string move_name = line.substr(0, line.find(','));
            possible_moves.push_back(move_library.get_move(move_name));
        }


        // add pokemon to library
        PokemonBase pokemon(id, name, types, base_stats, possible_moves);
        add_pokemon(name, pokemon);
    }
}