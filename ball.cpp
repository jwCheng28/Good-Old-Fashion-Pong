#include <cstdlib>
#include <ctime>
#include "ball.hpp"

Ball::Ball(int x, int y){
    pos.x, pos.y = x, y;
    pos.w, pos.h = 20, 20;
    ball_pos = pos.x;
    srand(time(0));
    rand() % 2 ? velocity = 2 : velocity = -2;
}

Ball::~Ball(){
}

void Ball::draw(SDL_Renderer* renderer){
    SDL_RenderFillRect(renderer, &pos);
}

void Ball::update(){
    ball_pos += (velocity * 1/60);
    pos.x = ball_pos; 
}
