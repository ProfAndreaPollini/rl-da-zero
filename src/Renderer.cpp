//
// Created by pollini on 10/01/2022.
//

#include "Renderer.h"

void Renderer::prepare() const {
    BeginDrawing();
    window_->ClearBackground(RAYWHITE);
}

void Renderer::draw() const {

//    DrawText("@", 190, 200, 20, RED);
    EndDrawing();
}

void Renderer::setup() {
    auto ptr = std::make_unique<raylib::Window>(options.width *14, options.height *20, options.title);
    window_.swap(ptr);
}
