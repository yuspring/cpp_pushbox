#ifndef SRC_OBJECT_CHARACTER_H
#define SRC_OBJECT_CHARACTER_H
#include "../views/map.h"
#include <SDL2/SDL.h>
class player{
    public:

        //weed is 0; chest is 1; wall is 2.
        int ifItem(map _map, int x, int y);
        SDL_Rect player_walk(SDL_Event event, map _map);
        void player_push();
        void render();
        void movement(int direction);//Up = 0; Down = 1; Left = 2; Right = 3

    private:
        int _X= 280;
        int _Y= 280;
};


#endif