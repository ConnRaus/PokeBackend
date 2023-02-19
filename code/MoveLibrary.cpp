#include "MoveLibrary.hpp"
#include "Move.hpp"
#include "Type.hpp"
#include <iostream>
#include <fstream>

MoveLibrary::MoveLibrary() {
    // import moves from file
    import_moves("data/movelist.csv");
}

Move MoveLibrary::get_move(const std::string& name) {
    if (!move_exists(name)) {
        std::cout << "Error: Move " << name << " does not exist" << std::endl;
        exit(1);
    }
    return library_.at(name);
}

bool MoveLibrary::move_exists(const std::string& name) {
    return library_.find(name) != library_.end();
}

void MoveLibrary::add_move(const std::string& name, const Move& move) {
    library_.emplace(name, move);
}

void MoveLibrary::remove_move(const std::string& name) {
    library_.erase(name);
}

void MoveLibrary::import_moves(const std::string& filename) {
    // import moves from file
    // File will be in the format:
    // name,type,category,power,accuracy,pp

    //open file
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error opening file" << std::endl;
        return;
    }

    //read file
    // move list is in format: name,type,category,power,accuracy,pp
    std::string line;
    while(std::getline(file, line)) {
        
        // get name
        std::string name = line.substr(0, line.find(','));
        line = line.substr(line.find(',') + 1);

        // get type
        std::string type = line.substr(0, line.find(','));
        line = line.substr(line.find(',') + 1);

        // get category
        Move::Category category;
        std::string categoryStr = line.substr(0, line.find(','));
        line = line.substr(line.find(',') + 1);
        if (categoryStr == "Physical") {
            category = Move::Category::Physical;
        } else if (categoryStr == "Special") {
            category = Move::Category::Special;
        } else if (categoryStr == "Status") {
            category = Move::Category::Status;
        } else {
            std::cout << "Error: Invalid category" << std::endl;
            return;
        }

        // get power
        int power = std::stoi(line.substr(0, line.find(',')));
        line = line.substr(line.find(',') + 1);

        // get accuracy
        int accuracy = std::stoi(line.substr(0, line.find(',')));
        line = line.substr(line.find(',') + 1);

        // get pp
        int pp = std::stoi(line.substr(0, line.find(',')));
        line = line.substr(line.find(',') + 1);

        // create move
        Move move(name, Type(type), category, power, accuracy, pp);
        add_move(name, move);

    }
    
}