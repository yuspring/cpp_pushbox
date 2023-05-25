#include <SDL2/SDL.h>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <string>

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
    SDL_Surface* gray = NULL;
    

    SDL_Init(SDL_INIT_VIDEO);
    
    
    

    window = SDL_CreateWindow(SCREEN_NAME, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    screenSurface = SDL_GetWindowSurface(window);
    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF ));
    
    imageUp = SDL_LoadBMP("imgs/Key_Up.bmp");
    imageDown = SDL_LoadBMP("imgs/Key_Down.bmp");
    imageRight = SDL_LoadBMP("imgs/Key_Right.bmp");
    imageLeft = SDL_LoadBMP("imgs/Key_Left.bmp");
    green = SDL_LoadBMP("imgs/green.bmp");
    gray = SDL_LoadBMP("imgs/gray.bmp");
    currentImage = imageDown;
    

    bool isRunning = true;
    SDL_Event ev;

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

    SDL_Rect player;
    player.x = 0;
    player.y = 0;

     for(int i = 1; i <= x; i++){
        for(int j = 1; j <= y; j++){
            SDL_Rect rec;
            rec.x = 40 * j;
            rec.y = 40 * i;
            if(s[i-1][j-1] == '#'){
                SDL_BlitSurface(gray, NULL, screenSurface, &rec);
            }
            else if(s[i-1][j-1] == '.'){
                SDL_BlitSurface(green, NULL, screenSurface, &rec);
            }
        }
    }

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
            
            
            
            if(ev.type == SDL_KEYDOWN){
                if(ev.key.keysym.sym == SDLK_UP){
                    currentImage = imageUp;
                    SDL_BlitSurface(currentImage, NULL, screenSurface, &player);
                    player.y -= 40;
                    SDL_BlitSurface(currentImage, NULL, screenSurface, &player);
                }
                else if(ev.key.keysym.sym == SDLK_DOWN){
                    currentImage = imageDown;
                    SDL_BlitSurface(NULL, NULL, screenSurface, &player);
                    player.y += 40;
                    SDL_BlitSurface(currentImage, NULL, screenSurface, &player);
                }
                else if(ev.key.keysym.sym == SDLK_RIGHT){
                    currentImage = imageRight;
                    SDL_BlitSurface(NULL, NULL, screenSurface, &player);
                    player.x -= 40;
                    SDL_BlitSurface(currentImage, NULL, screenSurface, &player);
                }
                else if(ev.key.keysym.sym == SDLK_LEFT){
                    currentImage = imageLeft;
                    SDL_BlitSurface(NULL, NULL, screenSurface, &player);
                    player.x += 40;
                    SDL_BlitSurface(currentImage, NULL, screenSurface, &player);
                }
            }
        }
        /*
        if(SDL_flip(screenSurface) == -1){

        }
        */
        SDL_UpdateWindowSurface(window);
    }
    
        
    
    SDL_FreeSurface(imageSurface);
    SDL_FreeSurface(imageUp);
    SDL_FreeSurface(imageDown);
    SDL_FreeSurface(imageRight);
    SDL_FreeSurface(imageLeft);
    SDL_FreeSurface(gray);

    
    imageSurface = nullptr;
    imageUp = nullptr;
    imageDown = nullptr;
    imageRight = nullptr;
    imageLeft = nullptr;
    currentImage = nullptr;
    gray = nullptr;

    
    SDL_DestroyWindow(window);

    window = nullptr;
    screenSurface = nullptr;

    SDL_Quit();

    return 0;
}