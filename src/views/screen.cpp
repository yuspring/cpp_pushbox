#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include "screen.h"
#include "render.h"

app::app(){
    quit = false;
}

app::~app(){
    SDL_DestroyTexture(green);
    SDL_DestroyTexture(gray);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void app::init(){

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "Unable to initialize SDL lib";
    }
    window = SDL_CreateWindow("My SDL Empty window", 
                                SDL_WINDOWPOS_UNDEFINED, 
                                SDL_WINDOWPOS_UNDEFINED, 
                                640, 480, SDL_WINDOW_SHOWN);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    
    app::render();
    

}


void app::render(){
    green = loadTexture("imgs/green.bmp", renderer);
    gray = loadTexture("imgs/gray.bmp", renderer);
}

void app::create_map(){

    std::string s[10];
    std::ifstream file("./maps/map.txt", std::ios::in);
    int cnt = 0;
    int x, y;
    file >> x >> y;
    while(!file.eof()){
        file >> s[cnt];
        std::cout << s[cnt] << '\n';
        cnt++;
    }
    std::cout << x << " " << y << '\n';

}

void app::screen(){
}

void app::run(){

    while(!quit){
        SDL_PollEvent(&event);

        switch (event.type) {
            case SDL_QUIT: {
                quit = true;
                break;
            }
            case SDL_KEYDOWN: {
                if(event.key.keysym.sym == SDLK_UP){
                    
                }
                else if(event.key.keysym.sym == SDLK_DOWN){
                    
                }
                else if(event.key.keysym.sym == SDLK_RIGHT){
                    
                }
                else if(event.key.keysym.sym == SDLK_LEFT){
                    
                }
            }
        }
        renderTexture(green, renderer, 30, 30, 50, 50);
        renderTexture(gray, renderer, 35, 35, 50, 50);
        SDL_RenderPresent(renderer);
    }

}