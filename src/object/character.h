#ifndef SRC_OBJECT_CHARACTER_H
#define SRC_OBJECT_CHARACTER_H
#include "../views/map.h"
#include "object.h"
#include <SDL2/SDL.h>
#include <iostream>
class player : public object{
    public:
        player();
        //weed is 0; chest is 1; wall is 2.
        int ifItem(map _map, int x, int y);
        SDL_Rect player_walk(SDL_Event event, map _map);
        void player_push();
        void movement(int direction);//Up = 0; Down = 1; Left = 2; Right = 3
};


#endif