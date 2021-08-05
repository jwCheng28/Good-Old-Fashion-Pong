#ifndef _PLAYER_SCORE_H
#define _PLAYER_SCORE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <vector>

class Score {
    private:
        int twidth;
        int theight;
        int winWidth;
        TTF_Font* font;
        std::vector<int> scores;
        std::vector<SDL_Surface*> surfaces;
        std::vector<SDL_Texture*> textures;
        std::vector<SDL_Rect> text;
        void _destroy(int);
        void _setDisplayPos(int, std::vector<SDL_Surface*>);
        void _draw(int, SDL_Renderer*, bool);
    public:
        Score(int, SDL_Renderer*);
        ~Score();
        void increaseScore(int);
        int getScore(int);
        void draw(SDL_Renderer*, bool);
};

#endif
