#ifndef _PADDLE_H
#define _PADDLE_H

#include <SDL2/SDL.h>
#include <vector>

class Paddle{
    private:
        SDL_Rect pos;
        int player;
        float pad_pos;
        int direction;
        void _padEve(const Uint8*, int, int);
    public:
        Paddle(int, int, int, SDL_Renderer*);
        ~Paddle() = default;
        void paddleEvent(std::vector<float>);
        void update(int, float);
        void draw(SDL_Renderer*);
        bool paddleHit(std::vector<float>);
        void weakAImovement(std::vector<float>);
};

#endif
