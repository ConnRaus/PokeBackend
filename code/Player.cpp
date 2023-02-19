#include "Player.hpp"

Player::Player(const std::string& name) : name_(name) {}

std::string Player::name() const {
    return name_;
}

std::vector<Pokemon>& Player::party() {
    return party_;
}

void Player::add_pokemon(const Pokemon& pokemon) {
    party_.push_back(pokemon);
}

void Player::remove_pokemon(int index) {
    party_.erase(party_.begin() + index);
}

void Player::print_party() {
    for (size_t i = 0; i < party_.size(); i++) {
        std::cout << i << ": " << party_[i].name() << std::endl;
    }
}
