#ifndef SRC_VIEWS_SCREEN_H
#define SRC_VIEWS_SCREEN_H

#include <iostream>
#include <SDL2/SDL.h>
#include <vector>
#include <SDL2/SDL_image.h>
#include "picture.h"
#include "map.h"
#include "../object/character.h"
#include "../object/chest.h"
#include "../object/destination.h"
#include "../util/coord.h"

class app{

    private:
        bool quit;
        SDL_Event event;
        SDL_Window *window;
        SDL_Renderer *renderer;   
        std::map<std::string, picture> _mp;
        map first_map;
        player _player;
        coord_map _coord_map;
        std::vector<chest> _chest;    
        std::vector<dest> _dest;

    public:
        app();
        ~app();

        void init();
        void run();
        void set_coord();
        void set_map();
        int _X , _Y;




};


#endif