//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <iostream>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main( int argc, char* args[] ){

    SDL_Window* window = NULL;
    SDL_Surface* screenSurface = NULL;

    SDL_Init( SDL_INIT_VIDEO );
    window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    
    bool isRunning = true;

    SDL_Event e;

    while(isRunning){

        while(SDL_PollEvent(&e) != 0){
            if(e.type == SDL_QUIT){
                isRunning = false;
            }

            if(e.type == SDL_KEYDOWN){

                if(e.key.keysym.sym == SDLK_1){
                    std::cout << 1 << '\n';
                }
                else if(e.key.keysym.sym == SDLK_2){
                    std::cout << 2 << '\n';
                }
                else if (e.key.keysym.sym == SDLK_3){
                    std::cout << 3 << '\n';
                }

            }
        }
        SDL_UpdateWindowSurface( window );
    }

    

    SDL_DestroyWindow( window );

    //Quit SDL subsystems
    SDL_Quit();

    return 0;
}