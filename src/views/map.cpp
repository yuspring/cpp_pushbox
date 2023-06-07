#include "map.h"


void map::map_load(std::string _path){
    std::ifstream file( _path.c_str(), std::ios::in);
    int cnt = 0;
    int x, y;
    file >> x >> y;
    //std::cout << x << " " << y << "\n";
    this->_X = x;
    this->_Y = y;
    while (!file.eof()){
        file >> _map[cnt];
        //std::cout << _map[cnt] << '\n';
        cnt++;
    }

}

void map::map_edit(int x, int y, char _c){
    std::cout << x << " " << y <<" " << _c << "\n";
    this->_map[x][y] = _c;
}

int map::get_mapsize_X(){
    return this->_X;
}

int map::get_mapsize_Y()
{
    return this->_Y;
}

void map::map_show(){
    for(int i = 1; i <= _X; i++){
        for(int j = 1; j <= _Y; j++){
            std::cout << _map[i-1][j-1];
           
        }
        std::cout << '\n';
    }
}

int map::get_mapitem(int x, int y){
    if(_map[x][y] == '#'){
        return 0;
    }
    else if(_map[x][y] == '.'){
        return 1;
    }
    else if(_map[x][y] == 'C'){
        return 2;
    }
    else if(_map[x][y] == 'E'){
        return 3;
    }
    return -1;
}

void map::map_render(SDL_Texture *tex1, SDL_Renderer *renderer, char _c){
    for(int i = 1; i <= _X; i++){
        for(int j = 1; j <= _Y; j++){
            
            SDL_Rect rec = {40 * j, 40 * i, 40, 40};
            if(_map[i-1][j-1] == _c){
                SDL_RenderCopy(renderer, tex1, nullptr, &rec);
            }
        }
    }
}

std::map<std::string, map> init_map(){
    std::map<std::string, map> _mp;
    map _map1, _map2, _map3 , _map4 , _map5, _map6, _map7, _map8;
    _map1.map_load("maps/map.txt");
    _map2.map_load("maps/map1.txt");
    _map3.map_load("maps/map2.txt");
    _map4.map_load("maps/map3.txt");
    _map5.map_load("maps/map4.txt");
    _map6.map_load("maps/map5.txt");
    _map7.map_load("maps/map6.txt");
    _map8.map_load("maps/map7.txt");
    _mp["map1"] = _map1;
    _mp["map2"] = _map2;
    _mp["map3"] = _map3;
    _mp["map4"] = _map4;
    _mp["map5"] = _map5;
    _mp["map6"] = _map6;
    _mp["map7"] = _map7;
    _mp["map8"] = _map8;
    return _mp;
}
