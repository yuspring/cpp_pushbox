#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include "screen.h"




app::app(){
    quit = false;
    _X = 40;
    _Y = 40;
}

app::~app(){
    //SDL_DestroyTexture(green);
    //SDL_DestroyTexture(gray);
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

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    
    _mp = init_picture(renderer);

}

void app::loading_texture(){
    green = IMG_LoadTexture(renderer, "imgs/green.bmp");
    gray = IMG_LoadTexture(renderer, "imgs/gray.bmp");
    test = IMG_LoadTexture(renderer, "imgs/test.bmp");

}

void app::create_map(){

    std::string s[10];
    std::ifstream file("maps/map.txt", std::ios::in);
    int cnt = 0;
    int x, y;
    file >> x >> y;
    while(!file.eof()){
        file >> s[cnt];
        cnt++;
    }
    //std::cout << x << " " << y << '\n';

    for(int i = 1; i <= x; i++){
        for(int j = 1; j <= y; j++){
            
            SDL_Rect rec = {40 * j, 40 * i, 40, 40};
            if(s[i-1][j-1] == '#'){
                SDL_RenderCopy(renderer, _mp["gray"].get_tex(), nullptr, &rec);
            }
            else if(s[i-1][j-1] == '.'){
                SDL_RenderCopy(renderer, _mp["green"].get_tex(), nullptr, &rec);
            }
        }
    }

}

void app::run(){

    while(!quit){
        SDL_PollEvent(&event);
        

        
        
        SDL_SetRenderDrawColor(renderer, 0, 0, 200, 255);
        ;
        SDL_RenderClear(renderer);
        app::create_map();
        SDL_Rect rec = { _X , _Y, 40 ,40};
        switch (event.type) {
            case SDL_QUIT: {
                quit = true;
                break;
            }
            case SDL_KEYDOWN: {
                if(event.key.keysym.sym == SDLK_UP){
                    _Y -= 10;                  
                }
                else if(event.key.keysym.sym == SDLK_DOWN){
                    _Y += 10;
                }
                else if(event.key.keysym.sym == SDLK_RIGHT){
                    _X += 10;
                }
                else if(event.key.keysym.sym == SDLK_LEFT){
                    _X -= 10;      
                }
            }
        }

        SDL_RenderCopy(renderer, _mp["test"].get_tex(), nullptr, &rec);
        

        SDL_RenderPresent( renderer );
        
    }

}

