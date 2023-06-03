#ifndef SRC_OBJECT_CHEST_H
#define SRC_OBJECT_CHEST_H

#include <SDL2/SDL.h>
#include "object.h"
#include "../views/map.h"

class chest: public object{
    
    public:
        void move(int dire, map* _map);
        bool is_pushed(int x, int y);
        

};

#endif