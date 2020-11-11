#ifndef _BALL_H
#define _BALL_H

#include <SDL2/SDL.h>
#include <vector>

class Ball{
    private:
        std::vector<float> ball_pos;
        std::vector<float> velocity;
        SDL_Rect pos;
        void _updatePos(int, float, bool);
        int _randVelocity();
    public:
        Ball(int, int, SDL_Renderer*);
        ~Ball() = default;
        std::vector<float> getBallAttr();
        void draw(SDL_Renderer*);
        int backWallCollision(int);
        void paddleBallCollision(bool, float);
        int update(int, int, float, bool);
};

#endif
