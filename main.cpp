#include "game.hpp"

int main(int argc, char* args[]){
    Game *game = new Game("Pong", 1400, 800);
    
    while (!(game -> ended())) {
        game -> eventHandler();
        game -> update(1.0/15.0);
        game -> render();
    }

    delete game;
    
    return 0;
}
