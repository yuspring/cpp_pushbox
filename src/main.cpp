#include <SDL2/SDL.h>
#include <cstdio>
#include <iostream>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main( int argc, char* args[] ){

    SDL_Window* window = NULL;

    SDL_Surface* screenSurface = NULL;

    SDL_Surface* imageSurface = NULL;

    

    SDL_Init( SDL_INIT_VIDEO );
    
    //Create window
    window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );

    //Get window surface
    screenSurface = SDL_GetWindowSurface( window );

    //Fill the surface white
    SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );
            
    //Update the surface
    SDL_UpdateWindowSurface( window );

    //Hack to get window to stay up
    //SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }

    bool isRunning = true;
    SDL_Event ev;
                
    while(isRunning){
        while(SDL_PollEvent(&ev) != 0){
            if(ev.type == SDL_QUIT){
                isRunning = false;          
            }
            
            imageSurface = SDL_LoadBMP("test.bmp");
            if(imageSurface == NULL){
                std::cout << "Image loading Error:" << SDL_GetError() << std::endl;
            }
            else{
                SDL_BlitSurface(imageSurface, NULL, screenSurface, NULL);
                SDL_UpdateWindowSurface(window);
            }
            
        }
        SDL_UpdateWindowSurface(window);
    }
        
    
    SDL_FreeSurface(imageSurface);
    imageSurface = nullptr;

    //Destroy window
    SDL_DestroyWindow( window );

    window = nullptr;
    screenSurface = nullptr;

    //Quit SDL subsystems
    SDL_Quit();

    return 0;
}