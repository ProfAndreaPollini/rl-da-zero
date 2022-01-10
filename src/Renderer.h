//
// Created by pollini on 10/01/2022.
//

#ifndef RL_DA_ZERO_RENDERER_H
#define RL_DA_ZERO_RENDERER_H

#include <memory>

#include "raylib-cpp.hpp"

struct RenderOptions {
    int width;
    int height;
    const char *title;

    RenderOptions() : width(80), height(50), title("RL-DA-Zero") {}

};

struct DrawEntityInfo {
    int x;
    int y;
    const char* c;
};

class Renderer {

public:
    Renderer(const RenderOptions& options = RenderOptions()) : options(options) {}

    void setup();
    void prepare() const;
    void draw() const;

    [[maybe_unused]] static void drawEntity(DrawEntityInfo drawInfo)  {
        DrawText(drawInfo.c,drawInfo.x, drawInfo.y,20, RED);
    }
    bool shouldEnd() const { return window_->ShouldClose(); }

private:


    RenderOptions options;
    std::unique_ptr<raylib::Window> window_;
};


#endif //RL_DA_ZERO_RENDERER_H
