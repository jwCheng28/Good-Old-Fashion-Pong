#include <cstdlib>
#include <ctime>
#include "ball.hpp"

Ball::Ball(int x, int y){
    pos.x = x, pos.y = y;
    pos.w = 20, pos.h = 20;
    ball_pos = {pos.x, pos.y};
    srand(time(NULL));
    velocity = {0, 0};
    rand() % 2 ? velocity[0] = 2 : velocity[0] = -2;
    rand() % 2 ? velocity[1] = 3 : velocity[1] = -3;
}

void Ball::draw(SDL_Renderer* renderer){
    SDL_RenderFillRect(renderer, &pos);
}

void Ball::_updatePos(int ax, float fr, bool randC){
    int C = (randC ? rand() % 4 + 1 : 1);
    ball_pos[ax] += (C * velocity[ax] * fr); 
    if (!ax)
        pos.x = ball_pos[ax];
    else
        pos.y = ball_pos[ax];
}

void Ball::update(int winw, int winh, float fr){
    bool x_bound = ball_pos[0] > 50 && ball_pos[0] < (winw - 50);
    bool y_bound = ball_pos[1] > 5 && ball_pos[1] < (winh - 5);
    if (x_bound && y_bound) {
        // Update Ball X Pos
        _updatePos(0, fr, 0);
        // Update Ball Y Pos
        _updatePos(1, fr, 0);
    } else if (!y_bound) {
        // Update Ball Y Pos (Bounce Off Wall)
        velocity[1] *= -1;
        _updatePos(1, fr, 1);
    } else {
        // Reset Position to Center
        ball_pos[0] = (winw - 20) / 2;
        ball_pos[1] = (winh - 20) / 2;
        pos.x = ball_pos[0];
        pos.y = ball_pos[1];
    }
}
