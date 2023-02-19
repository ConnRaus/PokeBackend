#ifndef MOVE_LIBRARY_HPP
#define MOVE_LIBRARY_HPP

#include <map>
#include <string>
#include "Move.hpp"


class MoveLibrary {
    private:
        std::map<std::string, Move> library_;

    public:
        MoveLibrary();
        Move get_move(const std::string& name);
        bool move_exists(const std::string& name);
        void add_move(const std::string& name, const Move& move);
        void remove_move(const std::string& name);
        void import_moves(const std::string& filename);
};


#endif