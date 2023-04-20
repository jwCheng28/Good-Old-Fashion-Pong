#include <string>
#include "game.hpp"

int main(int argc, char* args[]) {
    bool AI = (argc > 1 && args[1] == std::string("True"));
    Game *game = new Game("Pong", 1400, 800, AI);

    while (!(game->ended())) {
        game->eventHandler();
        #if WIN
        game->update(1.0/30.0);
        #else
        game->update(1.0/100.0);
        #endif
        game->render();
    }
    delete game;
    return 0;
}
