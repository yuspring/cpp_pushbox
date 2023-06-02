#include "chest.h"

void chest::move(int dire, map* _map, chest * chest, int _X, int _Y){
    if(dire == 0){
        chest->movement(0);
        _map->map_edit(_X,_Y+1,'.');
        _map->map_edit(_X, _Y, 'C');
    }
    else if(dire == 1){
        chest->movement(1);
        _map->map_edit(_X,_Y+1,'.');
        _map->map_edit(_X,_Y+2, 'C');
    }
    else if(dire == 2){
        chest->movement(2);
        _map->map_edit(_X,_Y+1,'.');
        _map->map_edit(_X-1,_Y+1, 'C');

    }
    else if(dire == 3){
        chest->movement(3);
        _map->map_edit(_X,_Y+1,'.');
        _map->map_edit(_X+1, _Y+1, 'C');

    }


}