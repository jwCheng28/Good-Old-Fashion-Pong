#include <stdio.h>
#include <string>
#include "score.hpp"

Score::Score(int winw, SDL_Renderer* renderer) {
    winWidth = winw;
    font = TTF_OpenFont("assets/Grand9KPixel.ttf", 35);
    scores = {0, 0};
    surfaces = {nullptr, nullptr};
    textures = {nullptr, nullptr};
    SDL_Rect r1, r2;
    text = {r1, r2};
    text[0].x = winw/2 - 200, text[0].y = 30;
    text[1].y = 30;
    draw(renderer, 1);
}

Score::~Score() {
    _destroy(0);
    _destroy(1);
    TTF_CloseFont(font);
}

void Score::increaseScore(int user) {
    user == 1 ? scores[0]++ : scores[1]++;
}

int Score::getScore(int user) {
    return user == 1 ? scores[0] : scores[1];
}

void Score::_destroy(int user) {
    SDL_FreeSurface(surfaces[user]);
    SDL_DestroyTexture(textures[user]);
}

void Score::_setDisplayPos(int user, std::vector<SDL_Surface*>& surfaces) {
    twidth = surfaces[user]->w;
    theight = surfaces[user]->h;
    text[user].w = twidth;
    text[user].h = theight;
    if (user == 1)
        text[user].x = winWidth/2 + (200 - twidth);
}

void Score::_draw(int user, SDL_Renderer* renderer, bool initial) {
    if (!initial)
        _destroy(user);

    std::string score = std::to_string(scores[user]);
    surfaces[user] = TTF_RenderText_Solid(font, score.c_str(), {255, 255, 255, 255});
    textures[user] = SDL_CreateTextureFromSurface(renderer, surfaces[user]); 
    _setDisplayPos(user, surfaces);
    
    // SDL_QueryTexture(textures[user], nullptr, nullptr, &twidth, &theight); 
    SDL_RenderCopy(renderer, textures[user], nullptr, &text[user]);
}

void Score::draw(SDL_Renderer* renderer, bool initial) {
    _draw(0, renderer, initial);
    _draw(1, renderer, initial);
}

void Score::winner(int user, SDL_Renderer* renderer) {
    char msg[32];
    sprintf(msg, "Player %d Wins!!", user);
    SDL_Surface* winScreenSurface = TTF_RenderText_Solid(font, msg, {255, 255, 255, 255});
    SDL_Texture* winScreenTexture = SDL_CreateTextureFromSurface(renderer, winScreenSurface); 
    SDL_Rect winScreenRect = {
        .x = winWidth/2 - 250, .y = 300,
        .w = 500, .h = 100
    };

    SDL_RenderCopy(renderer, winScreenTexture, nullptr, &winScreenRect);
}
