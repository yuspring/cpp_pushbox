#ifndef SRC_OBJECT_DESTINATION_H
#define SRC_OBJECT_DESTINATION_H
#include <SDL2/SDL.h>
#include "object.h"
#include "../views/map.h"

class dest: public object{
    
    public :
    bool chest_up(map _map);


};

#endif