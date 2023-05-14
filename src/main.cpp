#include <SDL2/SDL.h>
#include <cstdio>
#include <iostream>

#define SCREEN_NAME "SDL Tutorial"
#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 600

int main( int argc, char* args[] ){

    SDL_Window* window = NULL;

    SDL_Surface* screenSurface = NULL;
    SDL_Surface* imageSurface = NULL;
    SDL_Surface* imageUp = NULL;
    SDL_Surface* imageDown = NULL;
    SDL_Surface* imageRight = NULL;
    SDL_Surface* imageLeft = NULL;
    SDL_Surface* currentImage = NULL;
    SDL_Surface* green = NULL;

    

    SDL_Init(SDL_INIT_VIDEO);
    

    window = SDL_CreateWindow(SCREEN_NAME, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    screenSurface = SDL_GetWindowSurface(window);
    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF ));
    
    imageUp = SDL_LoadBMP("imgs/Key_Up.bmp");
    imageDown = SDL_LoadBMP("imgs/Key_Down.bmp");
    imageRight = SDL_LoadBMP("imgs/Key_Right.bmp");
    imageLeft = SDL_LoadBMP("imgs/Key_Left.bmp");
    green = SDL_LoadBMP("imgs/green.bmp");
    currentImage = imageDown;
    

    bool isRunning = true;
    SDL_Event ev;
                
    while(isRunning){
        while(SDL_PollEvent(&ev) != 0){
            if(ev.type == SDL_QUIT){
                isRunning = false;          
            }

            /*imageSurface = SDL_LoadBMP("test.bmp");
            if(imageSurface == NULL){
                std::cout << "Image loading Error:" << SDL_GetError() << std::endl;
            }
            else{
                SDL_BlitSurface(imageSurface, NULL, screenSurface, NULL);
                SDL_UpdateWindowSurface(window);
            }*/

            else if(ev.type == SDL_KEYDOWN){
                if(ev.key.keysym.sym == SDLK_UP){
                    currentImage = imageUp;
                }
                else if(ev.key.keysym.sym == SDLK_DOWN){
                    currentImage = imageDown;
                }
                else if(ev.key.keysym.sym == SDLK_RIGHT){
                    currentImage = imageRight;
                }
                else if(ev.key.keysym.sym == SDLK_LEFT){
                    currentImage = imageLeft;
                }
            }
        }
        
        for(int i = 1; i <= 8; i++){
            SDL_Rect rec;
            rec.x = 50 * i;
            rec.y = 100;
            SDL_BlitSurface(green, NULL, screenSurface, &rec);
        }
        
        SDL_UpdateWindowSurface(window);
    }
    
        
    
    SDL_FreeSurface(imageSurface);
    SDL_FreeSurface(imageUp);
    SDL_FreeSurface(imageDown);
    SDL_FreeSurface(imageRight);
    SDL_FreeSurface(imageLeft);
    
    imageSurface = nullptr;
    imageUp = nullptr;
    imageDown = nullptr;
    imageRight = nullptr;
    imageLeft = nullptr;
    currentImage = nullptr;

    
    SDL_DestroyWindow(window);

    window = nullptr;
    screenSurface = nullptr;

    SDL_Quit();

    return 0;
}