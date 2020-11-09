#ifndef _BALL_H
#define _BALL_H

#include <SDL2/SDL.h>

class Ball{
    private:
        int velocity;
        int ball_pos;
        SDL_Rect pos;
    public:
        Ball(int, int);
        ~Ball();
        void draw(SDL_Renderer*);
        void update();
};

#endif
