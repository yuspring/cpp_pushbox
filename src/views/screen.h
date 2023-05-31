#ifndef SRC_VIEWS_SCREEN_H
#define SRC_VIEWS_SCREEN_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class app{

    private:
        bool quit;
        SDL_Event event;
        SDL_Window *window;
        SDL_Renderer *renderer;
        SDL_Texture *green, *gray;


    public:
        app();
        ~app();

        void render();
        void create_map();
        void init();
        void run();



};


#endif