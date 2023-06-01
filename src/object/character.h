#ifndef SRC_OBJECT_CHARACTER_H
#define SRC_OBJECT_CHARACTER_H
#include "../views/map.h"
#include "chest.h"
#include "object.h"
#include <SDL2/SDL.h>
#include <iostream>

#define UP_X(x) (x - 40) / 40
#define UP_Y(y) (y - 40 - 10) / 40
#define DOWN_X(x) x / 40 - 1
#define DOWN_Y(y) y / 40 
#define RIGHT_X(x) x / 40
#define RIGHT_Y(y) (y - 10) / 40
#define LEFT_X(x) (x - 40 - 10) / 40
#define LEFT_Y(y) (y - 40) / 40

class player : public object{
    public:
        player();
        //weed is 0; chest is 1; wall is 2.
        int ifItem(map _map, int x, int y);
        SDL_Rect player_walk(SDL_Event event, map* _map, chest* _chest);
        void player_push(map _map, int x, int y, int dire, chest _chest);
};


#endif