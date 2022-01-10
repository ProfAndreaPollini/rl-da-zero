//
// Created by pollini on 10/01/2022.
//

#ifndef RL_DA_ZERO_GAME_H
#define RL_DA_ZERO_GAME_H

#include <memory>

#include "Renderer.h"
#include "Hero.h"

struct GameOptions {
    int width;
    int height;
    const char *title;

    GameOptions() : width(80), height(50), title("RL-DA-Zero") {}

};

class Game {
public:
    Game(std::unique_ptr<Renderer> renderer) : renderer_(std::move(renderer)) {}
    void setup(const GameOptions& options = GameOptions());
    void run();

    bool processInput();
    void update();
private:
    std::unique_ptr<Renderer> renderer_;
    bool waitUserInput_ = true;
    Hero hero_;
};


#endif //RL_DA_ZERO_GAME_H
