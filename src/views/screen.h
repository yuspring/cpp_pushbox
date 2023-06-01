#ifndef SRC_VIEWS_SCREEN_H
#define SRC_VIEWS_SCREEN_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "picture.h"
#include "map.h"

class app{

    private:
        bool quit;
        SDL_Event event;
        SDL_Window *window;
        SDL_Renderer *renderer;   
        std::map<std::string, picture> _mp;
        map first_map;
            

    public:
        app();
        ~app();

        void init();
        void run();
        int _X , _Y;




};


#endif