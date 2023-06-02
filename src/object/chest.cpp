#include "chest.h"

void chest::move(int dire, map* _map){
    if(dire == 0){
        this->movement(0);
        _map->map_edit(this->_x+1,this->_y,'.');
        _map->map_edit(this->_x, this->_y, 'C');
    }
    else if(dire == 1){
        this->movement(1);
        _map->map_edit(this->_x-1,this->_y,'.');
        _map->map_edit(this->_x, this->_y, 'C');
    }
    else if(dire == 2){
        this->movement(2);
        _map->map_edit(this->_x,this->_y+1,'.');
        _map->map_edit(this->_x, this->_y, 'C');

    }
    else if(dire == 3){
        this->movement(3);
        _map->map_edit(this->_x,this->_y-1,'.');
        _map->map_edit(this->_x, this->_y, 'C');

    }


}

bool chest::is_pushed(int x, int y){
    if(_x == x && _y == y) return true;
    return false;
}
