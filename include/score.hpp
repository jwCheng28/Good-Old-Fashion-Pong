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
        void _destroy(int user);
        void _setDisplayPos(int user, std::vector<SDL_Surface*>& surfaces);
        void _draw(int user, SDL_Renderer* renderer, bool initial);
    public:
        Score(int winw, SDL_Renderer* renderer);
        ~Score();
        void increaseScore(int user);
        int getScore(int user);
        void draw(SDL_Renderer* renderer, bool initial);
};

#endif
