#ifndef _BALL_H
#define _BALL_H

#include <SDL2/SDL.h>
#include <vector>

class Ball{
    private:
        std::vector<float> ball_pos;
        std::vector<int> velocity;
        SDL_Rect pos;
        void _updatePos(int, float, bool);
    public:
        Ball(int, int);
        ~Ball() = default;
        void draw(SDL_Renderer*);
        void update(int, int, float);
};

#endif
