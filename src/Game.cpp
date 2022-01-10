//
// Created by pollini on 10/01/2022.
//

#include "Game.h"
#include "fmt/core.h"



void Game::run() {
    fmt::print("Game running...\n");

    while (!renderer_->shouldEnd())
    {
        // process input
        if (waitUserInput_) {
            auto inputReceived = processInput();
            if (inputReceived) {
                waitUserInput_ = false;
            }
        }

        // update
        if(!waitUserInput_) {
            update();
            waitUserInput_ = true;
        }

        // draw
        renderer_->prepare();

        Renderer::drawEntity({hero_.x(),hero_.y(),"@"});

        renderer_->draw();

    }
}

void Game::setup(const GameOptions& options) {
    renderer_->setup();
}

bool Game::processInput() {
    if(IsKeyPressed(KEY_LEFT)){
        fmt::print("Left pressed\n");
        hero_.moveLeft();
        return true;
    }

    if(IsKeyPressed(KEY_RIGHT)){
        fmt::print("Right pressed\n");
        hero_.moveRight();
        return true;
    }

    if(IsKeyPressed(KEY_UP)){
        fmt::print("Up pressed\n");
        hero_.moveUp();
        return true;
    }

    if(IsKeyPressed(KEY_DOWN)){
        fmt::print("Down pressed\n");
        hero_.moveDown();
        return true;
    }

    return false;
}

void Game::update() {
    fmt::print("Game updated\n");
}
