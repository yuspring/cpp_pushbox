#ifndef SRC_VIEWS_SCREEN_H
#define SRC_VIEWS_SCREEN_H

#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
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
        player _player;
        coord_map _coord_map;
        std::vector<chest> _chest;    
        std::vector<dest> _dest;
        score _s;
        std::string _map_name;
        TTF_Font* ttf;
        SDL_Surface* surfaceText;
        SDL_Texture* ttf_welcome;
        SDL_Texture* ttf_welcome1;
        SDL_Texture* ttf_switch;
        SDL_Texture* ttf_break;
        bool game_run;
        bool show_switch;

    public:
        app();
        ~app();

        void init();
        void set_map_info(map *_map);
        void set_map_render(map *_map);
        void run();
        void switch_map(std::string _str);
        void ttf_init();
        int _X , _Y;
        




};


#endif