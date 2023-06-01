#include "map.h"


void map::map_load(std::string _path){
    std::ifstream file( _path.c_str(), std::ios::in);
    int cnt = 0;
    int x, y;
    file >> x >> y;
    std::cout << x << " " << y << "\n";
    this->_X = x;
    this->_Y = y;
    while (!file.eof()){
        file >> _map[cnt];
        std::cout << _map[cnt] << '\n';
        cnt++;
    }

    for(int i = 1; i <= _X; i++){
        for(int j = 1; j <= _Y; j++){
            
            SDL_Rect rec = {40 * j, 40 * i, 40, 40};
            if(_map[i-1][j-1] == '#'){
                object.set_coord(0, i-1, j-1);
            }
            else if(_map[i-1][j-1] == '.'){
                object.set_coord(1, i-1, j-1);
            }
            else if(_map[i-1][j-1] == 'C'){
                object.set_coord(2, i-1, j-1);
            }
            else if(_map[i-1][j-1] == 'P'){
                object.set_coord(3, i-1, j-1);
            }
            else if(_map[i-1][j-1] == 'E'){
                object.set_coord(4, i-1, j-1);
            }
        }
    }

}

void map::map_edit(int x, int y, char _c){
    std::cout << x << " " << y <<" " << _c << "\n";
    this->_map[y][x] = _c;
}

char map::map_show(int x, int y){
    return this->_map[x][y];
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
    return -1;
}

void map::map_render(SDL_Texture *tex1, SDL_Texture *tex2, SDL_Texture *tex3, SDL_Renderer *renderer){
    //map::map_show();
    for(int i = 1; i <= _X; i++){
        for(int j = 1; j <= _Y; j++){
            
            SDL_Rect rec = {40 * j, 40 * i, 40, 40};
            if(_map[i-1][j-1] == '#'){
                SDL_RenderCopy(renderer, tex1, nullptr, &rec);
                //object.set_coord(0, i-1, j-1);
            }
            else if(_map[i-1][j-1] == '.'){
                SDL_RenderCopy(renderer, tex2, nullptr, &rec);
                //object.set_coord(0, i-1, j-1);
            }
            else if(_map[i-1][j-1] == 'C'){
                SDL_RenderCopy(renderer, tex3, nullptr, &rec);
                //object.set_coord(0, i-1, j-1);
            }
            else if(_map[i-1][j-1] == 'P'){
                SDL_RenderCopy(renderer, tex2, nullptr, &rec);
                //object.set_coord(0, i-1, j-1);
            }
        }
    }
}

