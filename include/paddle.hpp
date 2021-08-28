#ifndef _PADDLE_H
#define _PADDLE_H

#include <SDL2/SDL.h>
#include <vector>

class Paddle {
    private:
        SDL_Rect pos;
        int player;
        float pad_pos;
        int direction;
        void _padEve(const Uint8* keys, int upCode, int downCode);
    public:
        Paddle(int user, int x, int y, SDL_Renderer* renderer);
        ~Paddle() = default;
        void paddleEvent(const std::vector<float>& ballAttr);
        void update(int winh, float frame_rate);
        void draw(SDL_Renderer* renderer);
        bool paddleHit(const std::vector<float>& ballAttr);
        void weakAImovement(const std::vector<float>& ballAttr);
};

#endif
