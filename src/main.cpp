#include <string>
#include "game.hpp"
#include <SDL2/SDL_thread.h>
#include <SDL2/SDL.h>

volatile int started = 0;

int updatePos(void *obj) {
    while (!started);
    while (!((Game*) obj)->ended()) {
        ((Game*) obj)->update(1.0/30.0);
        SDL_Delay(1);
    }
    return 0;
}

int main(int argc, char* args[]) {
    bool AI = (argc > 1 && args[1] == std::string("True"));
    Game *game = new Game("Pong", 1400, 800, AI);

    SDL_CreateThread(updatePos, "Updater", game);
    while (!(game->ended())) {
        started = 1;
        game->eventHandler();
        // game->update(1.0/30.0);
        game->render();
    }
    delete game;
    return 0;
}
