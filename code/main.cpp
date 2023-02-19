#include <iostream>
#include "Pokemon.hpp"
#include "Player.hpp"
#include "PokemonLibrary.hpp"
#include "MoveLibrary.hpp"

int main() {
    srand(time(NULL));

    auto* pokemon_library = new PokemonLibrary();
    auto* move_library = new MoveLibrary();

    Player player1("user1");
    Player player2("user2");

    pokemon_library->print_pokemon("Bulbasaur");

    Pokemon pokemon1(pokemon_library->get_pokemon("Bulbasaur"), 100);
    Pokemon pokemon2(pokemon_library->get_pokemon("Venusaur"), 100);

    player1.add_pokemon(pokemon1);
    player1.add_pokemon(pokemon2);

    player1.party()[0].set_move(0, move_library->get_move("Tackle"));

    player1.print_party();
    player1.party()[0].print_pokemon();
    player1.party()[1].print_pokemon();


    return 0;
}
