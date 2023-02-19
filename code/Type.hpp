#ifndef TYPE_HPP
#define TYPE_HPP

#include <string>
#include <array>
#include <vector>

constexpr int NUM_TYPES = 18;

class Type {
    public:
        Type(const std::string& name);
        double effectiveness(const std::vector<Type>& types) const;
        std::string name() const;
        static constexpr const char* type_names[NUM_TYPES] = {"Normal", "Fire", "Water", "Electric", "Grass", "Ice", "Fighting", "Poison", "Ground", "Flying", "Psychic", "Bug", "Rock", "Ghost", "Dragon", "Dark", "Steel", "Fairy"};
        int get_index() const;

    private:
        std::string name_;
        static constexpr std::array<std::array<double, NUM_TYPES>, NUM_TYPES> type_matchups_ = {{
            {{1,1,1,1,1,1,1,1,1,1,1,1,0.5,0,1,1,0.5,1}},
            {{1,0.5,0.5,1,2,2,1,1,1,1,1,2,0.5,1,0.5,1,2,1}},
            {{1,2,0.5,1,0.5,1,1,1,2,1,1,1,2,1,0.5,1,1,1}},
            {{1,1,2,0.5,0.5,1,1,1,0,2,1,1,1,1,0.5,1,1,1}},
            {{1,0.5,2,1,0.5,1,1,0.5,2,0.5,1,0.5,2,1,0.5,1,0.5,1}},
            {{1,0.5,0.5,1,2,0.5,1,1,2,2,1,1,1,1,2,1,0.5,1}},
            {{2,1,1,1,1,2,1,0.5,1,0.5,0.5,0.5,2,0,1,2,2,0.5}},
            {{1,1,1,1,2,1,1,0.5,0.5,1,1,1,0.5,0.5,1,1,0,2}},
            {{1,2,1,2,0.5,1,1,2,1,0,1,0.5,2,1,1,1,2,1}},
            {{1,1,1,0.5,2,1,2,1,1,1,1,2,0.5,1,1,1,0.5,1}},
            {{1,1,1,1,1,1,2,2,1,1,0.5,1,1,1,1,0,0.5,1}},
            {{1,0.5,1,1,2,1,0.5,0.5,1,0.5,2,1,1,0.5,1,2,0.5,0.5}},
            {{1,2,1,1,1,2,0.5,1,0.5,2,1,2,1,1,1,1,0.5,1}},
            {{0,1,1,1,1,1,1,1,1,1,2,1,1,2,1,0.5,1,1}},
            {{1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,0.5,0}},
            {{1,1,1,1,1,1,0.5,1,1,1,2,1,1,2,1,0.5,1,0.5}},
            {{1,0.5,0.5,0.5,1,2,1,1,1,1,1,1,2,1,1,1,0.5,2}},
            {{1,0.5,1,1,1,1,2,0.5,1,1,1,1,1,1,2,2,0.5,1}}
        }};

};

#endif