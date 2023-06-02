#include "coord.h"



coord coord_map::get_char_coord()
{
    return this->_arr[3];
}

coord coord_map::get_chest_coord()
{
    return this->_arr[2];
}

coord coord_map::get_dest_coord()
{
    return this->_arr[4];
}
void coord_map::set_coord(int k, int x, int y){
    this->_arr[k] = {x, y};
}

char map::map_show(int x, int y){
    return this->_map[x][y];
}

std::vector<dest> coord_map::init_dest(map _map){
    std::vector<dest> _dest;

    for(int i = 1; i <= _map.get_mapsize_X(); i++){
        for(int j = 1; j <= _map.get_mapsize_Y(); j++){
            dest _d;
            if(_map._map[i-1][j-1] == 'E'){
                _d.set_coord(i-1,j-1);
                _d.set_rect(_d._X, _d._Y);
                _dest.push_back(_d);
            }
            
        }
    }
    return _dest;
}

std::vector<chest> coord_map::init_chest(map _map){
    std::vector<chest> _chest;

    for(int i = 1; i <= _map.get_mapsize_X(); i++){
        for(int j = 1; j <= _map.get_mapsize_Y(); j++){
            chest _c;
            if(_map._map[i-1][j-1] == 'C'){
                _c.set_coord(i-1,j-1);
                _c.set_rect(_c._X, _c._Y);
                _chest.push_back(_c);
            }
            
        }
    }
    return _chest;
}

coord coord_map::get_player_coord(map _map){
    coord res;
    res.x = 0;
    res.y = 0;
    int cnt = 0;
    for(int i = 1; i <= _map.get_mapsize_X(); i++){
        for(int j = 1; j <= _map.get_mapsize_Y(); j++){
            if(_map._map[i-1][j-1] == 'P'){
                res.x = i-1;
                res.y = j-1;  
            }
        }
    }
    return res;
}
