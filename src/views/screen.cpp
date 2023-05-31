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
                                800, 800, SDL_WINDOW_SHOWN);
    screenSurface = SDL_GetWindowSurface(window);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    
    app::render();
    //app::create_map();

}


void app::render(){
    //green = loadTexture("imgs/green.bmp", renderer);
    SDL_Surface *image = IMG_Load("imgs/gray.bmp");
    SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, image);
    //green = loadTexture("imgs/gray.bmp", renderer);
    if(green == NULL){
            std::cout << "YES";
    }
    gray = loadTexture("imgs/gray.bmp", renderer);
}

void app::create_map(){
    std::string s[10];
    std::ifstream file("maps/map.txt", std::ios::in);
    int cnt = 0;
    int x, y;
    file >> x >> y;
    while(!file.eof()){
        file >> s[cnt];
        std::cout << s[cnt] << '\n';
        cnt++;
    }
    std::cout << x << " " << y << '\n';

    for(int i = 1; i <= x; i++){
        for(int j = 1; j <= y; j++){
            SDL_Rect rec;
            rec.x = 50 * j;
            rec.y = 50 * i;
            rec.w = 40;
            rec.h = 40;
            if(s[i-1][j-1] == '#'){
                SDL_RenderCopy(renderer, gray, NULL, &rec);
            }
            else if(s[i-1][j-1] == '.'){
                SDL_RenderCopy(renderer, green, NULL, &rec);
            }
        }
    }
    SDL_RenderPresent(renderer);
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
        SDL_Rect rec;
        rec.x = 50;
        rec.y = 50;
        rec.w = 40;
        rec.h = 40;
        //SDL_RenderCopy(renderer, gray, NULL, &rec);
        renderTexture(green, renderer, 50, 50 ,40 ,40);
        
        SDL_RenderPresent(renderer);
    }

}