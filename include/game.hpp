#ifndef _GAME_H
#define _GAME_H

#include <string>
#include <memory>
#include <ctime>
#include "ball.hpp"
#include "paddle.hpp"
#include "score.hpp"

class Game {
    private:
        int WIDTH;
        int HEIGHT;
        bool running = false;
        clock_t time;
        SDL_Window* window;
        SDL_Renderer* renderer;
        SDL_Event event;
        std::unique_ptr<Ball> ball;
        std::unique_ptr<Paddle> paddle1;
        std::unique_ptr<Paddle> paddle2;
        std::unique_ptr<Score> scores;
    public:
        Game(const std::string& title, int win_width, int win_height, bool AI);
        ~Game();
        void eventHandler();
        void render();
        void update(float frame_rate);
        bool ended();
};

#endif
