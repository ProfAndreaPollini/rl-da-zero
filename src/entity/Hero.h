//
// Created by pollini on 10/01/2022.
//

#ifndef RL_DA_ZERO_HERO_H
#define RL_DA_ZERO_HERO_H


#include "Entity.h"
#include "fmt/core.h"

class Hero : public Entity {
public:
    Hero() : Entity{10,10} {}

    void draw() {
        fmt::print("Hero\n");
    }

    void moveLeft() {
        fmt::print("Hero move left\n");
        move(-14, 0);
    }

    void moveRight() {
        fmt::print("Hero move right\n");
        move(14, 0);
    }

    void moveUp() {
        fmt::print("Hero move up\n");
        move(0, -14);
    }

    void moveDown() {
        fmt::print("Hero move down\n");
        move(0, 14);
    }
};


#endif //RL_DA_ZERO_HERO_H
