#ifndef SRC_VIEWS_MAP
#define SRC_VIEWS_MAP

#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "../util/coord.h"


class map{

    private:
        
        int _X;
        int _Y;
    public :
        std::string _map[50];
        int get_mapitem(int x, int y);
        void map_load(std::string _path);
        void map_render(SDL_Texture *tex1, SDL_Texture *tex2,SDL_Texture *tex3, SDL_Renderer *renderer);
        coord_map object;
        void map_edit(int x, int y, char _c);
        char map_show(int x, int y);
        void map_show();

};



#endif