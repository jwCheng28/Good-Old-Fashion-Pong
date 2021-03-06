#ifndef _GAME_H
#define _GAME_H

#include "ball.hpp"
#include "paddle.hpp"
#include "score.hpp"

class Game{
    private:
        int WIDTH;
        int HEIGHT;
        bool running = false;
        SDL_Window* window;
        SDL_Renderer* renderer;
        SDL_Event event;
        Ball* ball = nullptr;
        Paddle* paddle1 = nullptr;
        Paddle* paddle2 = nullptr;
        Score* scores = nullptr;
    public:
        Game(char*, int, int, bool);
        ~Game();
        void eventHandler();
        void render();
        void update(float);
        bool ended();
};

#endif
