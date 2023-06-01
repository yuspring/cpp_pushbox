#include <iostream>

#include "screen.h"


app::app(){
    quit = false;
    _X = 80;
    _Y = 80;
}

app::~app(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void app::init(){

    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("My SDL Empty window", 
                                SDL_WINDOWPOS_UNDEFINED, 
                                SDL_WINDOWPOS_UNDEFINED, 
                                900, 900, SDL_WINDOW_SHOWN);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    
    first_map.map_load("maps/map.txt");
    _mp = init_picture(renderer);

}


void app::run(){

    while(!quit){
        SDL_PollEvent(&event);
        
        SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 255);
        SDL_RenderClear(renderer);
        first_map.map_render(_mp["wall"].get_tex(), _mp["gress"].get_tex(), renderer);

        SDL_Rect rec = { _X , _Y, 40 ,40};
        switch (event.type) {
            case SDL_QUIT: {
                quit = true;
                break;
            }
            case SDL_KEYDOWN: {
                if(event.key.keysym.sym == SDLK_UP){
                    _Y -= 40;                  
                }
                else if(event.key.keysym.sym == SDLK_DOWN){
                    _Y += 40;
                }
                else if(event.key.keysym.sym == SDLK_RIGHT){
                    _X += 40;
                }
                else if(event.key.keysym.sym == SDLK_LEFT){
                    _X -= 40;      
                }
            }
        }

        SDL_RenderCopy(renderer, _mp["player"].get_tex(), nullptr, &rec);
        

        SDL_RenderPresent( renderer );
        
    }

}

