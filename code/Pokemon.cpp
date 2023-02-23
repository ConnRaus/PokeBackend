#include "Pokemon.hpp"
#include "Type.hpp"

PokemonBase::PokemonBase(int id, const std::string& name, const std::vector<Type>& types, const std::array<int, 6>& base_stats, const std::vector<Move>& possible_moves) {
    id_ = id;
    name_ = name;
    types_ = types;
    base_stats_ = base_stats;
    possible_moves_ = possible_moves;
}

int PokemonBase::id() const {
    return id_;
}

std::string PokemonBase::name() const {
    return name_;
}

std::vector<Type> PokemonBase::types() const {
    return types_;
}

std::array<int, 6> PokemonBase::base_stats() const {
    return base_stats_;
}

std::vector<Move> PokemonBase::possible_moves() const {
    return possible_moves_;
}

void PokemonBase::print_pokemon() const {
    std::cout << "ID: " << id_ << std::endl;
    std::cout << "Name: " << name_ << std::endl;
    std::cout << "Types: ";
    for (size_t i = 0; i < types_.size(); i++) {
        std::cout << types_[i].name() << " ";
    }
    std::cout << std::endl;

    std::cout << "Base Stats: ";
    for (size_t i = 0; i < base_stats_.size(); i++) {
        std::cout << base_stats_[i] << ", ";
    }
    std::cout << std::endl;

    std::cout << "Possible Moves: ";
    for (size_t i = 0; i < possible_moves_.size(); i++) {
        std::cout << possible_moves_[i].name() << " ";
    }
    std::cout << std::endl;
}


Pokemon::Pokemon(const PokemonBase& base, int level): PokemonBase(base) {
    level_ = level;
    randomize_ivs();
    randomize_evs();
    randomize_moves();
    calculate_stats();
}

int Pokemon::level() const {
    return level_;
}

std::array<int, 6> Pokemon::stats() const {
    return stats_;
}

std::array<int, 6> Pokemon::ivs() const {
    return ivs_;
}

std::array<int, 6> Pokemon::evs() const {
    return evs_;
}

std::vector<Move> Pokemon::moves() const {
    return moves_;
}

int Pokemon::move_pp(int index) const {
    return move_pp_[index];
}

void Pokemon::set_move_pp(int index, int pp) {
    if(pp > moves_[index].pp() || pp < 0) {
        std::cout << "PP cannot be greater than max PP or less than 0." << std::endl;
        return;
    }
    move_pp_[index] = pp;
}

bool Pokemon::add_move(Move move) {
    // if move is already in use, dont add it
    for(int i = 0; i < (int)moves_.size(); i++) {
        if(move.name() == moves_[i].name()) {
            return false;
        }
    }
    
    //if move is in possible moves, add it
    for(int i = 0; i < (int)possible_moves().size(); i++) {
        if(move.name() == possible_moves()[i].name()) {
            moves_.push_back(move);
            move_pp_.push_back(move.pp());
            return true;
        }
    }

    // otherwise print error
    std::cout << "Move not in possible moves." << std::endl;
    return false;
}

bool Pokemon::remove_move(int index) {
    if((int)moves_.size() < index) {
        std::cout << "Move index out of range." << std::endl;
        return false;
    }

    moves_.erase(moves_.begin() + index);
    move_pp_.erase(move_pp_.begin() + index);
    return true;
}

bool Pokemon::set_move(int index, Move move) {

    if(index >= (int)moves_.size()) {
        std::cout << "Move index out of range." << std::endl;
        return false;
    }

    // if move is already in use, dont set it
    for(int i = 0; i < (int)moves_.size(); i++) {
        if(move.name() == moves_[i].name()) {
            std::cout << "Move already in use." << std::endl;
            return false;
        }
    }
    
    //if move is in possible moves, set it
    for(int i = 0; i < (int)possible_moves().size(); i++) {
        if(move.name() == possible_moves()[i].name()) {
            moves_[index] = move;
            move_pp_[index] = move.pp();
            std::cout << "Move set." << std::endl;
            return true;
        }
    }

    // otherwise print error
    std::cout << "Move not in possible moves." << std::endl;
    return false;
}

void Pokemon::set_ivs(const std::array<int, 6>& ivs) {
    ivs_ = ivs;
}

void Pokemon::set_evs(const std::array<int, 6>& evs) {
    evs_ = evs;
}

void Pokemon::randomize_ivs() {
    for(int i = 0; i < 6; i++) {
        ivs_[i] = rand() % 32;
    }
}

void Pokemon::randomize_evs() {
    for(int i = 0; i < 510; i++) {
        int stat = rand() % 6;
        if(evs_[stat] < 255) {
            evs_[stat]++;
        }
    }
}

void Pokemon::randomize_moves() {
    // generate 4 random moves from possible moves
    // clear moves and then generate 4 new ones
    moves_.clear();
    move_pp_.clear();
    for(int i = 0; i < 4; i++) {
        int move_index = rand() % possible_moves().size();
        if(!add_move(possible_moves()[move_index])) {
            i--;
        } else {
            move_pp_[i] = moves_[i].pp();
        }
    }

}

void Pokemon::calculate_stats() {
    //HP stat calculated differently
    stats_[0] = (2 * base_stats()[0] + ivs_[0] + evs_[0] / 4) * level_ / 100 + level_ + 10;

    //Other stats all calculated the same way
    for(int i = 1; i < 6; i++) {
        stats_[i] = (2 * base_stats()[i] + ivs_[i] + evs_[i] / 4) * level_ / 100 + 5;
    }
}

void Pokemon::print_pokemon() const {
//    PokemonBase::print_pokemon();
    std::cout << "Name: " << name() << std::endl;
    std::cout << "Level: " << level_ << std::endl;
    std::cout << "Current Stats: ";
    for (size_t i = 0; i < stats_.size(); i++) {
        std::cout << stats_[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "IVs: ";
    for (size_t i = 0; i < ivs_.size(); i++) {
        std::cout << ivs_[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "EVs: ";
    for (size_t i = 0; i < evs_.size(); i++) {
        std::cout << evs_[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Moves: ";
    for (size_t i = 0; i < moves_.size(); i++) {
        std::cout << moves_[i].name() << " | ";
    }
    std::cout << std::endl;

    std::cout << "Move PP: ";
    for (size_t i = 0; i < move_pp_.size(); i++) {
        std::cout << move_pp_[i] << " ";
    }
    std::cout << std::endl;
}