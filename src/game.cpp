#include <iostream>
#include <string>
#include <memory>
#include <ctime>
#include "game.hpp"

Game::Game(std::string title, int win_width, int win_height, bool AI) {
    WIDTH = win_width, HEIGHT = win_height;
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        TTF_Init();
        window = SDL_CreateWindow(
                 title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
                 WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
        renderer = SDL_CreateRenderer(window, -1, 0);
        
        ball = std::make_unique<Ball>((WIDTH - 20)/2, (HEIGHT - 20)/2, renderer);
        paddle1 = std::make_unique<Paddle>(1, 40, (HEIGHT - 150)/2, renderer);
        paddle2 = std::make_unique<Paddle>(AI ? 3 : 2, WIDTH - 70, (HEIGHT - 150)/2, renderer);
        scores = std::make_unique<Score>(WIDTH, renderer);
        
        running = true;
    } else {
        std::cout << "SDL Initialization Failed" << std::endl;
    }
}

Game::~Game() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    TTF_Quit();
}

void Game::eventHandler() {
    SDL_PollEvent(&event);
    if (event.type == SDL_QUIT)
        running = false;
    paddle1->paddleEvent({});
    paddle2->paddleEvent(ball->getBallAttr());
}

void Game::render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
    
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawLine(renderer, WIDTH/2, 0, WIDTH/2, HEIGHT);
    ball->draw(renderer);
    paddle1->draw(renderer);
    paddle2->draw(renderer);
    scores->draw(renderer, 0);
    
    SDL_RenderPresent(renderer);
}

void Game::update(float frame_rate) {
    std::vector<float> ballAttr = ball->getBallAttr();
    bool padOneCollision = paddle1->paddleHit(ballAttr);
    bool padTwoCollision = paddle2->paddleHit(ballAttr);
    int goalCollision = 0;
    if ((clock() - time)/CLOCKS_PER_SEC >= 1)
        goalCollision = ball->update(WIDTH, HEIGHT, frame_rate, padOneCollision || padTwoCollision);

    if (goalCollision < 0) {
        scores->increaseScore(2);
        time = clock();
    } else if (goalCollision > 0) {
        scores->increaseScore(1);
        time = clock();
    }

    if (scores->getScore(1) >= 11) {
        std::cout << "Player 1 Wins\n";
        running = false;
    } else if (scores->getScore(2) >= 11) {
        std::cout << "Player 2 Wins\n";
        running = false;
    }
    
    paddle1->update(HEIGHT, frame_rate);
    paddle2->update(HEIGHT, frame_rate);
}

bool Game::ended() {
    return !running;
}
