#ifndef MOVE_HPP
#define MOVE_HPP

#include "Type.hpp"
#include <string>

class Move {
    public:
        enum class Category {Physical, Special, Status};
        Move(const std::string& name, Type type, Category category, int power, int accuracy, int pp);

        std::string name() const;
        Type type() const;
        Category category() const;
        int power() const;
        int accuracy() const;
        int pp() const;

        //virtual void use(Pokemon& user, Pokemon& target);

    private:
        std::string name_;
        Type type_;
        Category category_;
        int power_;
        int accuracy_;
        int pp_;
        int priority_ = 0;
        bool contact_ = false;
};

// TODO: Implement Recoil Moves
//class RecoilMove : public Move {
//    public:
//        RecoilMove(const Move& move, int recoil);
//        RecoilMove(const std::string& name, Type type, Category category, int power, int accuracy, int pp, int recoil);
//
//        int recoil() const;
//
//    private:
//        int recoil_;
//};

// TODO: Implement Multi-Turn Moves
//class MultiTurnMove : public Move {
//    public:
//        MultiTurnMove(const Move& move, int turns);
//        MultiTurnMove(const std::string& name, Type type, Category category, int power, int accuracy, int pp, int turns);
//
//        int turns() const;
//
//    private:
//        int turns_;
//};

// TODO: Implement Priority Moves
//class PriorityMove : public Move {
//    public:
//        PriorityMove(const Move& move, int priority);
//        PriorityMove(const std::string& name, Type type, Category category, int power, int accuracy, int pp, int priority);
//
//    private:
//        int priority_;
//
//
//};

#endif
