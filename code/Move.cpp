#include "Move.hpp"

Move::Move(const std::string& name, Type type, Category category, int power, int accuracy, int pp) : name_(name), type_(type), category_(category), power_(power), accuracy_(accuracy), pp_(pp) {}

//// TODO: Implement move uses
//void Move::use(Pokemon& user, Pokemon& target) {
//    //calculate damage of move use
//    if (category_ == Category::Physical) {
//        // calculate damage using attack and defense
//
//    } else if (category_ == Category::Special) {
//        // calculate damage using special attack and special defense
//
//    } else {
//        // Status moves should typically have their own class and overwrite use()
//        return;
//    }
//}

std::string Move::name() const {
    return name_;
}

Type Move::type() const {
    return type_;
}

Move::Category Move::category() const {
    return category_;
}

int Move::power() const {
    return power_;
}

int Move::accuracy() const {
    return accuracy_;
}

int Move::pp() const {
    return pp_;
}