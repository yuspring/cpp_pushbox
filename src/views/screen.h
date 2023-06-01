#ifndef SRC_VIEWS_SCREEN_H
#define SRC_VIEWS_SCREEN_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "picture.h"

class app{

    private:
        bool quit;
        SDL_Event event;
        SDL_Window *window;
        SDL_Surface *image;
        SDL_Texture *green, *gray, *test;
        std::map<std::string, picture> _mp;
        SDL_Texture *texture;
        SDL_Renderer *renderer;       

    public:
        app();
        ~app();
        void loading_texture();
        void create_map();

        void init();
        void run();
        int _X , _Y;




};


#endif