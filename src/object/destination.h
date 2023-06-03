#ifndef SRC_OBJECT_DESTINATION_H
#define SRC_OBJECT_DESTINATION_H
#include <SDL2/SDL.h>
#include "object.h"
#include "../views/map.h"

class dest: public object{
    
    public :
    dest();
    bool chest_up(map _map);
    bool up_chest;
    void chest(bool _c);
    


};

#endif