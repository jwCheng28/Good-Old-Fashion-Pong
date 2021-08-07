#include <string>
#include "game.hpp"
#include <SDL2/SDL_thread.h>
#include <SDL2/SDL.h>

int main(int argc, char* args[]) {
    bool AI = (argc > 1 && args[1] == std::string("True"));
    Game *game = new Game("Pong", 1400, 800, AI);

    while (!(game->ended())) {
        game->eventHandler();
        game->update(1.0/30.0);
        game->render();
    }
    delete game;
    return 0;
}
