#ifndef _GAME_H
#define _GAME_H

#include <SDL2/SDL.h>
#include "ball.hpp"

class Game{
    private:
        int WIDTH;
        int HEIGHT;
        bool running = false;
        SDL_Window* window;
        SDL_Renderer* renderer;
        SDL_Event event;
        Ball* ball = nullptr;
    public:
        Game(char*, int, int);
        ~Game();
        void eventHandler();
        void render();
        void update();
        bool ended();
};

#endif
