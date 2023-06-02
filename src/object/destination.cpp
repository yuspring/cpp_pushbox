#include "destination.h"

bool dest::chest_up(map _map){
    if(_map.get_mapitem(this->_X, this->_Y) == 2){
        return true;
    } 
    return false;
}