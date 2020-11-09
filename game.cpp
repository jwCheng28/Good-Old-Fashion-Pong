#include <iostream>
#include "game.hpp"
#include "ball.hpp"

Game::Game(char* title, int win_width, int win_height){
    WIDTH = win_width;
    HEIGHT = win_height;
    if (!SDL_Init(SDL_INIT_VIDEO)) {
         window = SDL_CreateWindow(
                 title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
                 WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
        renderer = SDL_CreateRenderer(window, -1, 0);
        ball = new Ball((WIDTH - 20)/2, (HEIGHT - 20)/2);
        running = true;
    } else {
        std::cout << "SDL Initialization Failed" << std::endl;
    }
}

Game::~Game(){
    delete ball;
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

void Game::eventHandler(){
    SDL_PollEvent(&event);
    if (event.type == SDL_QUIT)
        running = false;
}

void Game::render(){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawLine(renderer, WIDTH/2, 0, WIDTH/2, HEIGHT);
    ball -> draw(renderer);
    SDL_RenderPresent(renderer);
}

void Game::update(){
    ball -> update();
}

bool Game::ended(){
    return !running;
}
