#include "character.h"


player::player(){
    _X = 80;
    _Y = 80;
}

int player::ifItem(map _map, int x, int y)
{
    std::cout << x << ' ' << y << " " << _map.get_mapitem(x, y) << '\n';
    return _map.get_mapitem(y, x);
}

void player::player_push(map _map, int x, int y, int dire, chest _chest){
    switch(dire){
        case 0:{
            if(player::ifItem(_map, x, y-2) == 0){
                break;
            }
            else{
                //std::cout <<  _chest._X << " " << _chest._Y << '\n';
                //std::cout <<  _chest._rect.x << " " << _chest._rect.y << '\n';
                _chest.movement(dire);
                //_chest.set_coord(_chest._X/40 ,_chest._Y/40);
                //std::cout <<  _chest._X << " " << _chest._Y << '\n';
                //std::cout <<  _chest._rect.x << " " << _chest._rect.y << '\n';
                /*
                for(int i = x-1; i <= x+1; i++){
                    for(int j = y - 1; j <= y+1; j++){
                        std::cout << _map.map_show(i,j);
                    }
                    std::cout << '\n';
                }
                */
               //_map.map_show();
               _map.map_edit(x, y-1, 'C');
               _map.map_edit(x,y,'.');
               //_map.map_show();
                /*
                for(int i = x-1; i <= x+1; i++){
                    for(int j = y - 1; j <= y+1; j++){
                        std::cout << _map.map_show(i,j);
                    }
                    std::cout << '\n';
                }
                */
                player::movement(dire);
            }
        }
        case 1:{

        }
        case 2:{

        }
        case 3:{

        }

    }
    
}

SDL_Rect player::player_walk(SDL_Event event, map* _map, chest* _chest){

    SDL_Rect rec = { _X , _Y, 40 ,40};
    
        switch (event.type) {
            case SDL_KEYUP: {
                if(event.key.keysym.sym == SDLK_UP){
                    switch(player::ifItem(*_map, UP_X(_X), UP_Y(_Y))){
                        case 0:{
                            break;
                        }

                        case 1:{
                            player::movement(0);
                            break;
                        }
                        
                        case 2:{
                            _chest->movement(0);
                            player::movement(0);
                            _map->map_edit(UP_X(_X),UP_Y(_Y)+1,'.');
                            _map->map_edit(UP_X(_X), UP_Y(_Y), 'C');
                        }
                        
                    }                 
                }
                else if(event.key.keysym.sym == SDLK_DOWN){
                    switch(player::ifItem(*_map, DOWN_X(_X), DOWN_Y(_Y))){
                        case 0:{
                            break;
                        }

                        case 1:{
                            player::movement(1);
                            break;
                        }
                        case 2:{
                            _chest->movement(1);
                            player::movement(1);
                            _map->map_edit(UP_X(_X),UP_Y(_Y)+1,'.');
                            _map->map_edit(UP_X(_X), UP_Y(_Y)+2, 'C');
                        }
                    }

                }
                else if(event.key.keysym.sym == SDLK_RIGHT){
                    switch(player::ifItem(*_map, RIGHT_X(_X) , RIGHT_Y(_Y))){
                        case 0:{
                            break;
                        }

                        case 1:{
                            player::movement(3);
                            break;
                        }
                        case 2:{
                            _chest->movement(3);
                            player::movement(3);
                            _map->map_edit(UP_X(_X),UP_Y(_Y)+1,'.');
                            _map->map_edit(UP_X(_X)+1, UP_Y(_Y)+1, 'C');
                        }
                    }
                }
                else if(event.key.keysym.sym == SDLK_LEFT){
                    switch(player::ifItem(*_map, LEFT_X(_X), LEFT_Y(_Y))){
                        case 0:{
                            break;
                        }

                        case 1:{
                            player::movement(2);
                            break;
                        }
                        case 2:{
                            _chest->movement(2);
                            player::movement(2);
                            _map->map_edit(UP_X(_X),UP_Y(_Y)+1,'.');
                            _map->map_edit(UP_X(_X)-1, UP_Y(_Y)+1, 'C');
                        }
                    }
    
                }
            }
        }
        
        return rec;
}


