#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include "screen.h"

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
                                900, 900, SDL_WINDOW_SHOWN);

    renderer = SDL_CreateRenderer(window, -1, 0);
    
    app::render();
    app::create_map();

}

void app::render(){
    //texture = SDL_CreateTextureFromSurface(renderer, image);
    green = IMG_LoadTexture(renderer, "imgs/green.bmp");
    gray = IMG_LoadTexture(renderer, "imgs/gray.bmp");
    SDL_Rect rect = {100, 100, 40, 40};
    SDL_RenderCopy(renderer, green, nullptr, &rect);
    SDL_RenderPresent(renderer);
}

void app::create_map(){

    std::string s[10];
    std::ifstream file("maps/map.txt", std::ios::in);
    int cnt = 0;
    int x, y;
    file >> x >> y;
    while(!file.eof()){
        file >> s[cnt];
        //std::cout << s[cnt] << '\n';
        cnt++;
    }
    //std::cout << x << " " << y << '\n';
    
    for(int i = 1; i <= x; i++){
        for(int j = 1; j <= y; j++){
            
            SDL_Rect rec = {40 * j, 40 * i, 40, 40};
            if(s[i-1][j-1] == '#'){
                SDL_RenderCopy(renderer, gray, nullptr, &rec);
            }
            else if(s[i-1][j-1] == '.'){
                SDL_RenderCopy(renderer, green, nullptr, &rec);
            }
        }
    }

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
        SDL_RenderClear( renderer );
        app::create_map();
        SDL_RenderPresent( renderer );
        
    }

}