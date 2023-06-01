#include "map.h"


void map::map_load(std::string _path){
    std::ifstream file( _path.c_str(), std::ios::in);
    int cnt = 0;
    int x, y;
    file >> x >> y;
    std::cout << x << " " << y << "\n";
    this->_X = x;
    this->_Y = y;
    while (!file.eof())
    {
        file >> _map[cnt];
        std::cout << _map[cnt] << '\n';
        cnt++;
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
    return -1;
}

void map::map_render(SDL_Texture *tex1, SDL_Texture *tex2, SDL_Renderer *renderer){
    for(int i = 1; i <= _X; i++){
        for(int j = 1; j <= _Y; j++){
            
            SDL_Rect rec = {40 * j, 40 * i, 40, 40};
            if(_map[i-1][j-1] == '#'){
                SDL_RenderCopy(renderer, tex1, nullptr, &rec);
            }
            else if(_map[i-1][j-1] == '.'){
                SDL_RenderCopy(renderer, tex2, nullptr, &rec);
            }
        }
    }
}

