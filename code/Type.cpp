#include "Type.hpp"

Type::Type(const std::string& name) : name_(name) {}



double Type::effectiveness(const std::vector<Type>& types) const {
    double effectiveness = 1.0;
    for(int i = 0; i < (int)types.size(); i++) {
        effectiveness *= type_matchups_[get_index()][types[i].get_index()];
    }
    return effectiveness;
}

std::string Type::name() const {
    return name_;
}

int Type::get_index() const {
    int index = -1;
    for(int i = 0; i < NUM_TYPES; i++) {
        if(name_ == type_names[i]) {
            index = i;
        }
    }
    return index;
}