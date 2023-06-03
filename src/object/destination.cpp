#include "destination.h"

dest::dest(){
    up_chest = false;
}

bool dest::chest_up(map _map)
{
    if(_map.get_mapitem(this->_x, this->_y) == 2){
        //up_chest = true;
        return true;
    } 
    else{
        //up_chest = false;
    }
    return false;
}

void dest::chest(bool _c){
    if(_c) this->up_chest = true;
    else this->up_chest = false;
}