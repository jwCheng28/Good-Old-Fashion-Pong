#include "paddle.hpp"

Paddle::Paddle(int user, int x, int y, SDL_Renderer* renderer) {
    player = user;
    pos.x = x, pos.y = y;
    pos.w = 30, pos.h = 150;
    pad_pos = pos.y;
    direction = 0;
    draw(renderer);
}

void Paddle::_padEve(const Uint8* keys, int upCode, int downCode) {
    if (keys[upCode])
        direction = 1;
    else if (keys[downCode])
        direction = -1;
    else
        direction = 0; 
}

void Paddle::paddleEvent(const std::vector<float>& ballAttr) {
    const Uint8* keys = SDL_GetKeyboardState(nullptr);
    if (player == 1)
        _padEve(keys, SDL_SCANCODE_W, SDL_SCANCODE_S);
    else if (player == 2)
        _padEve(keys, SDL_SCANCODE_UP, SDL_SCANCODE_DOWN);
    else if (player == 3)
        weakAImovement(ballAttr);
}

void Paddle::update(int winh, float frame_rate) {
    if (direction > 0 && pad_pos > 10)
        pad_pos -= (20.0 * frame_rate);
    else if (direction < 0 && (pad_pos + pos.h) < (winh - 10))
        pad_pos += (20.0 * frame_rate);
    pos.y = pad_pos;
}

void Paddle::draw(SDL_Renderer* renderer) {
    SDL_RenderFillRect(renderer, &pos);
}

// ballAttr = [x, y, w, h]
bool Paddle::paddleHit(const std::vector<float>& ballAttr) {
    bool xbound;
    bool ybound = ballAttr[1] <= pos.y + pos.h && ballAttr[1] + ballAttr[3] >= pos.y;
    if (player == 1)
        xbound = ballAttr[0] <= pos.x + pos.w;
    else
        xbound = ballAttr[0] + ballAttr[2] >= pos.x;
    return ybound && xbound;
}

void Paddle::weakAImovement(const std::vector<float>& ballAttr) {
    float ballCenter = ballAttr[1] + (ballAttr[3] / 2);
    float padCenter = pad_pos + (pos.h / 2);
    if (padCenter > ballCenter)
        direction = 1;
    else if (padCenter < ballCenter)
        direction = -1;
    else
        direction = 0;
}
