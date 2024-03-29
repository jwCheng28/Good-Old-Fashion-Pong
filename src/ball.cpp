#include <cstdlib>
#include <ctime>
#include "ball.hpp"

int _randVelocity(int range, int lower) {
    return (rand() % range + lower) * (rand() % 2 ? 1 : -1);
}

Ball::Ball(int x, int y, SDL_Renderer* renderer) {
    srand(time(NULL));
    pos.x = x, pos.y = y;
    pos.w = 20, pos.h = 20;
    ball_pos = {pos.x, pos.y};
    velocity = {(float) _randVelocity(2, 8),(float) _randVelocity(4, 10)};
    draw(renderer);
}

std::vector<float> Ball::getBallAttr() {
    std::vector<float> attr = {pos.x, pos.y, pos.w, pos.h};
    return attr;
}

void Ball::draw(SDL_Renderer* renderer) {
    SDL_RenderFillRect(renderer, &pos);
}

int Ball::backWallCollision(int winw) {
    // Left Wall Collision
    if (ball_pos[0] <= 5)
        return -1;
    // Right Wall Collision
    else if (ball_pos[0] >= winw-20)
        return 1;
}

void Ball::paddleBallCollision(bool paddleCollision, float frame_rate) {
    if (paddleCollision) {
        velocity[0] *= (velocity[0] < 18) ? -1.25 : -1;
        _updatePos(0, 3, 0);
    }
}

void Ball::_updatePos(int ax, float frame_rate, bool randC) {
    int C = (randC ? rand() % 5 + 2 : 1);
    ball_pos[ax] += (C * velocity[ax] * frame_rate); 
    if (!ax)
        pos.x = ball_pos[ax];
    else
        pos.y = ball_pos[ax];
}


int Ball::update(int winw, int winh, float frame_rate, bool paddleCollision) {
    bool x_bound = ball_pos[0] > 0 && ball_pos[0] < (winw - 20);
    bool y_bound = ball_pos[1] > 5 && ball_pos[1] < (winh - 5);
    if (x_bound && y_bound) {
        // Update Ball X & Y pos, and any paddle interaction
        _updatePos(0, frame_rate, 0);
        _updatePos(1, frame_rate, 0);
        paddleBallCollision(paddleCollision, frame_rate);
    } else if (!y_bound) {
        // Update Ball Y Pos (Bounce Off Wall)
        velocity[1] *= -1;
        _updatePos(1, frame_rate, 1);
    } else {
        // Check which back wall is hit, Left = -1, Right = 1
        int bwc = backWallCollision(winw);
        // Reset Position to Center
        ball_pos[0] = (winw - 20) / 2, ball_pos[1] = (winh - 20) / 2;
        pos.x = ball_pos[0], pos.y = ball_pos[1];
        // Randomly reinitialize x & y velocity
        velocity[0] = _randVelocity(2, 8), velocity[1] = _randVelocity(4, 8);
        return bwc;
    }
    return 0;
}
