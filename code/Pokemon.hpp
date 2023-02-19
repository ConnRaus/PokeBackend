#ifndef POKEMON_HPP
#define POKEMON_HPP

#include <string>
#include <vector>
#include <array>
#include <iostream>
#include "Type.hpp"
#include "Move.hpp"

class PokemonBase {
    public:
        PokemonBase(int id, const std::string& name, const std::vector<Type>& types, const std::array<int, 6>& base_stats, const std::vector<Move>& possible_moves);
        int id() const;
        std::string name() const;
        std::vector<Type> types() const;
        std::array<int, 6> base_stats() const;
        std::vector<Move> possible_moves() const;
        virtual void print_pokemon() const;

    private:
        int id_;
        std::string name_;
        std::array<int, 6> base_stats_;
        std::vector<Type> types_;
        std::vector<Move> possible_moves_;
};

class Pokemon: public PokemonBase {
    public:
        Pokemon(const PokemonBase& base, int level);
        int level() const;
        std::array<int, 6> current_stats() const;
        std::array<int, 6> ivs() const;
        std::array<int, 6> evs() const;
        std::vector<Move> moves() const;
        int move_pp(int index) const;
        bool set_move(int index, Move move);
        bool add_move(Move move);
        bool remove_move(int index);
        void set_move_pp(int index, int pp);
        void set_ivs(const std::array<int, 6>& ivs);
        void set_evs(const std::array<int, 6>& evs);
        void randomize_ivs();
        void randomize_evs();
        void randomize_moves();
        void calculate_stats();
        void print_pokemon() const;

    private:
        int level_;
        std::vector<Move> moves_;
        std::vector<int> move_pp_;
        std::array<int, 6> current_stats_;
        std::array<int, 6> ivs_ = {0, 0, 0, 0, 0, 0};
        std::array<int, 6> evs_ = {0, 0, 0, 0, 0, 0};
        
};

#endif