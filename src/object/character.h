#ifndef SRC_OBJECT_CHARACTER_H
#define SRC_OBJECT_CHARACTER_H
#include <iostream>
#include <SDL2/SDL.h>
#include "../views/map.h"
#include "chest.h"
#include "object.h"


class player : public object{
    public:
        player();
        //weed is 0; chest is 1; wall is 2.
        int ifItem(map _map, int x, int y);
        SDL_Rect player_walk(SDL_Event event, map* _map);
        bool can_push(map *_map, int _X, int _Y, int dire);
        int _dire;
};


#endif