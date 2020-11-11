#include "paddle.hpp"

Paddle::Paddle(int user, int x, int y){
    player = user;
    pos.x = x, pos.y = y;
    pos.w = 30, pos.h = 150;
    pad_pos = pos.y;
    direction = 0;
}

void Paddle::_padEve(const Uint8* keys, int upCode, int downCode){
    if (keys[upCode])
        direction = 1;
    else if (keys[downCode])
        direction = -1;
    else
        direction = 0; 
}

void Paddle::paddleEvent(){
    const Uint8* keys = SDL_GetKeyboardState(nullptr);
    if (player == 1)
        _padEve(keys, SDL_SCANCODE_W, SDL_SCANCODE_S);
    else
        _padEve(keys, SDL_SCANCODE_UP, SDL_SCANCODE_DOWN);
}

void Paddle::update(int winh, float fr){
    if (direction > 0 && pad_pos > 10) {
        pad_pos -= (2.0 * fr);
        pos.y = pad_pos;
    } else if (direction < 0 && (pad_pos + pos.h) < (winh - 10)) {
        pad_pos += (2.0 * fr);
        pos.y = pad_pos;
    }
}

void Paddle::draw(SDL_Renderer* renderer){
    SDL_RenderFillRect(renderer, &pos);
}