#ifndef _BALL_H
#define _BALL_H

#include <SDL2/SDL.h>
#include <vector>

class Ball {
    private:
        std::vector<float> ball_pos;
        std::vector<float> velocity;
        SDL_Rect pos;
        void _updatePos(int ax, float frame_rate, bool randC);
    public:
        Ball(int x, int y, SDL_Renderer* renderer);
        ~Ball() = default;
        std::vector<float> getBallAttr();
        void draw(SDL_Renderer* renderer);
        int backWallCollision(int winw);
        void paddleBallCollision(bool paddleCollision, float frame_rate);
        int update(int winw, int winh, float frame_rate, bool paddleCollision);
};

#endif
