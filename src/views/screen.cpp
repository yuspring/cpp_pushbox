#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include "screen.h"

app::app(){
    quit = false;
}

app::~app(){
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(image);
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

    renderer = SDL_CreateRenderer(window, -1, 0);
    image = SDL_LoadBMP("imgs/green.bmp");

    if (image == nullptr) {
        std::cerr << "SDL_LoadBMP failed\n";
    }
    texture = SDL_CreateTextureFromSurface(renderer, image);

}

void app::load_picture(){
}

void app::render(){
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

void app::run(){

    while(!quit){
        SDL_PollEvent(&event);

        switch (event.type) {
            case SDL_QUIT: {
                quit = true;
                break;
            }
        }
        SDL_Rect rect = {5, 5, 300, 200};
        SDL_RenderCopy(renderer, texture, nullptr, &rect);
        SDL_RenderPresent(renderer);
    }

}