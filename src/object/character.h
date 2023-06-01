#ifndef SRC_OBJECT_CHARACTER_H
#define SRC_OBJECT_CHARACTER_H
#include "../views/map.h"
#include "chest.h"
#include "object.h"
#include <SDL2/SDL.h>
#include <iostream>

#define UP_X (_X - 40) / 40
#define UP_Y (_Y - 40 - 10) / 40
#define DOWN_X (_X) / 40 - 1
#define DOWN_Y (_Y) / 40 
#define RIGHT_X (_X) / 40
#define RIGHT_Y (_Y - 10) / 40
#define LEFT_X (_X - 40 - 10) / 40
#define LEFT_Y (_Y - 40) / 40

class player : public object{
    public:
        player();
        //weed is 0; chest is 1; wall is 2.
        int ifItem(map _map, int x, int y);
        SDL_Rect player_walk(SDL_Event event, map _map, chest _chest);
        void player_push(map _map, int x, int y, int dire, chest _chest);
};


#endif