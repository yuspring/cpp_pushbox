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
        std::string _map[50];
        int _X;
        int _Y;
    public :
        int get_mapitem(int x, int y);
        void map_load(std::string _path);
        void map_render(SDL_Texture *tex1, SDL_Texture *tex2, SDL_Renderer *renderer);
        coord_map object;

};



#endif