#ifndef SRC_VIEWS_SCREEN_H
#define SRC_VIEWS_SCREEN_H

#include<SDL2/SDL.h>

class app{

    private:
        bool quit;
        SDL_Event event;
        SDL_Window *window;
        SDL_Renderer *renderer;
        SDL_Surface *image;
        SDL_Texture *texture;


    public:
        app();
        ~app();

        void load_picture();
        void render();
        void screen();
        
        void init();
        
        void create_map();
        void run();



};


#endif