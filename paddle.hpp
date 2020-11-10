#ifndef _PADDLE_H
#define _PADDLE_H

#include <SDL2/SDL.h>

class Paddle{
    private:
        SDL_Rect pos;
        int player;
        float pad_pos;
        int direction;
        void _padEve(const Uint8*, int, int);
    public:
        Paddle(int, int, int);
        ~Paddle() = default;
        void paddleEvent();
        void update(int, float);
        void draw(SDL_Renderer*);
};

#endif
