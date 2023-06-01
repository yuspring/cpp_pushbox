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
