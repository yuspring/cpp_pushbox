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
            if(player::ifItem(_map, x, y) == 0 || player::ifItem(_map, x, y) == 2){
                break;
            }
            else{
                _chest.movement(dire);
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

SDL_Rect player::player_walk(SDL_Event event, map _map, chest _chest){

    SDL_Rect rec = { _X , _Y, 40 ,40};
    
        switch (event.type) {
            case SDL_KEYUP: {
                if(event.key.keysym.sym == SDLK_UP){
                    switch(player::ifItem(_map, UP_X, UP_Y)){
                        case 0:{
                            break;
                        }

                        case 1:{
                            player::movement(0);
                            break;
                        }
                        /*
                        case 2:{
                            player::player_push(_map, UP_X, UP_Y , _chest);
                        }
                        */
                    }
                    //_Y -= 10;                  
                }
                else if(event.key.keysym.sym == SDLK_DOWN){
                    switch(player::ifItem(_map, DOWN_X, DOWN_Y)){
                        case 0:{
                            break;
                        }

                        case 1:{
                            player::movement(1);
                            break;
                        }
                    }
                    //_Y += 10;
                }
                else if(event.key.keysym.sym == SDLK_RIGHT){
                    switch(player::ifItem(_map, RIGHT_X , RIGHT_Y)){
                        case 0:{
                            break;
                        }

                        case 1:{
                            player::movement(3);
                            break;
                        }
                    }
                    //_X += 10;
                }
                else if(event.key.keysym.sym == SDLK_LEFT){
                    switch(player::ifItem(_map, LEFT_X, LEFT_Y)){
                        case 0:{
                            break;
                        }

                        case 1:{
                            player::movement(2);
                            break;
                        }
                    }
                    //_X -= 10;      
                }
            }
        }
        
        return rec;
}


