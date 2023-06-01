#include "character.h"
#include <iostream>



int player::ifItem(map _map, int x, int y)
{
    std::cout << x << ' ' << y << " " << _map.get_mapitem(x, y) << '\n';
    return _map.get_mapitem(y, x);
}

void player::player_push(){

}

SDL_Rect player::player_walk(SDL_Event event, map _map){

    SDL_Rect rec = { _X , _Y, 40 ,40};
    
        switch (event.type) {
            case SDL_KEYUP: {
                if(event.key.keysym.sym == SDLK_UP){
                    switch(player::ifItem(_map, (_X - 40) / 40, (_Y - 40 - 10) / 40)){
                        case 0:{
                            break;
                        }

                        case 1:{
                            player::movement(0);
                            break;
                        }
                    }
                    //_Y -= 10;                  
                }
                else if(event.key.keysym.sym == SDLK_DOWN){
                    switch(player::ifItem(_map, (_X) / 40 - 1, (_Y) / 40 )){
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
                    switch(player::ifItem(_map, (_X) / 40 , (_Y - 10) / 40)){
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
                    switch(player::ifItem(_map, (_X - 40 - 10) / 40, (_Y - 40) / 40)){
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

void player::render(){

}

void player::movement(int direction){
    switch(direction){
        case 0:{
            _Y -= 10;
            _Y -= 10;
            _Y -= 10;
            _Y -= 10;
            break;
        }

        case 1:{
            _Y += 10;
            _Y += 10;
            _Y += 10;
            _Y += 10;
            break;
        }

        case 2:{
            _X -= 10;
            _X -= 10;
            _X -= 10;
            _X -= 10;
            break;
        }

        case 3:{
            _X += 10;
            _X += 10;
            _X += 10;
            _X += 10;
            break;
        }
    }
}