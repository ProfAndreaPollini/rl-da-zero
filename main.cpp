
#include "Game.h"

int main() {
    std::unique_ptr<Renderer> renderer = std::make_unique<Renderer>();

    Game game{std::move(renderer)};
    game.setup();
    game.run();
    return 0;
}
