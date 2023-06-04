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
#include "../util/score.h"

class app{

    private:
        bool quit;
        SDL_Event event;
        SDL_Window *window;
        SDL_Renderer *renderer;   
        std::map<std::string, picture> pic_mp;
        std::map<std::string, map> map_mp;
        map first_map;
        player _player;
        coord_map _coord_map;
        std::vector<chest> _chest;    
        std::vector<dest> _dest;
        score _s;

    public:
        app();
        ~app();

        void init();
        void set_map_info(map *_map);
        void set_map_render(map *_map);
        void run();
        int _X , _Y;




};


#endif