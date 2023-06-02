#include "character.h"


player::player(){
    _X = 80;
    _Y = 80;
    _x = 1;
    _y = 1;
    _dire = 1;
}

int player::ifItem(map _map, int x, int y)
{
    //std::cout << x << ' ' << y << " " << _map.get_mapitem(x, y) << '\n';
    return _map.get_mapitem(x, y);
}
/*
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
                            if(player::can_push(_map, UP_X(_X), UP_Y(_Y), 0) ){
                                player::movement(0);
                                _chest->move(0, _map, _chest,UP_X(_X), UP_Y(_Y) );
                            }  
                            break;
                        }
                        case 3:{
                            player::movement(0);
                            break;
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
                            if(player::can_push(_map, UP_X(_X), UP_Y(_Y), 1) ){
                                player::movement(1);
                                _chest->move(1, _map, _chest,UP_X(_X), UP_Y(_Y) );
                            }  
                            break;
                        }
                        case 3:{
                            player::movement(1);
                            break;
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
                            if(player::can_push(_map, UP_X(_X), UP_Y(_Y), 3) ){
                                player::movement(3);
                                _chest->move(3, _map, _chest,UP_X(_X), UP_Y(_Y) );
                            }  
                            break;
                        }
                        case 3:{
                            player::movement(3);
                            break;
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
                            if(player::can_push(_map, UP_X(_X), UP_Y(_Y), 2) ){
                                player::movement(2);
                                _chest->move(2, _map, _chest,UP_X(_X), UP_Y(_Y) );
                            }  
                            break;
                        }
                        case 3:{
                            player::movement(2);
                            break;
                        } 
                    }
    
                }
            }
        }
        
        return rec;
}
*/
SDL_Rect player::player_walk(SDL_Event event, map* _map){

    SDL_Rect rec = { _X , _Y, 40 ,40};
        
        switch (event.type) {
            case SDL_KEYUP: {
                if(event.key.keysym.sym == SDLK_UP){
                    
                    switch(player::ifItem(*_map, _x-1, _y)){
                        case 0:{
                            break;
                        }
                        case 1:{
                            player::movement(0);
                            _dire = 0;
                            break;
                        }
                        
                        case 2:{
                            _dire = 0;
                            
                            if(player::can_push(_map, _x, _y, 0) ){
                                player::movement(0);
                            }  
                            
                            break;
                        }
                        case 3:{
                            player::movement(0);
                            _dire = 0;
                            break;
                        } 
                        std::cout << this->_x << " "<< this->_y << '\n';

                    }                 
                }
                else if(event.key.keysym.sym == SDLK_DOWN){
                    
                    switch(player::ifItem(*_map,  _x+1, _y)){
                        case 0:{
                            break;
                        }

                        case 1:{
                            player::movement(1);
                            _dire = 1;
                            break;
                        }
                        case 2:{
                            _dire = 1;
                            
                            if(player::can_push(_map, _x, _y, 1) ){
                                player::movement(1);
                            }  
                            
                            break;
                        }
                        case 3:{
                            player::movement(1);
                            _dire = 1;
                            break;
                        } 
                    }
                    //std::cout << DOWN_X(_X) << " " <<  DOWN_Y(_Y);

                }
                else if(event.key.keysym.sym == SDLK_RIGHT){
                    
                    switch(player::ifItem(*_map,  _x, _y+1)){
                        case 0:{
                            break;
                        }

                        case 1:{
                            player::movement(3);
                            _dire = 3;
                            break;
                        }
                        case 2:{
                            _dire = 3;
                            
                            if(player::can_push(_map, _x, _y, 3) ){
                                player::movement(3);
                            }  
                            
                            break;
                        }
                        case 3:{
                            player::movement(3);
                            _dire = 3;
                            break;
                        } 
                    }
                    //std::cout << DOWN_X(_X) << " " <<  DOWN_Y(_Y);
                }
                else if(event.key.keysym.sym == SDLK_LEFT){
                    
                    switch(player::ifItem(*_map,  _x, _y-1)){
                        case 0:{
                            break;
                        }

                        case 1:{
                            player::movement(2);
                            _dire = 2;
                            break;
                        }
                        case 2:{
                            _dire = 2;
                            
                            if(player::can_push(_map, _x, _y, 2) ){
                                player::movement(2);
                            }  
                            
                            break;
                        }
                        case 3:{
                            player::movement(2);
                            _dire = 2;
                            break;
                        } 
                    }
    
                }
            }
            std::cout << this->_x << " " << this->_y << '\n';
        }
        
        return rec;
}


bool player::can_push(map *_map, int _X, int _Y, int dire){
    if(dire == 0){
        return( player::ifItem(*_map, _X-2, _Y) != 0 && player::ifItem(*_map, _X-2, _Y) != 2);
    }
    else if(dire == 1){
        return( player::ifItem(*_map, _X+2, _Y) != 0 && player::ifItem(*_map, _X+2, _Y) != 2);
    }
    else if(dire == 2){
        return( player::ifItem(*_map, _X, _Y-2) != 0 && player::ifItem(*_map, _X, _Y-2) != 2);
    }
    else if(dire == 3){
        return( player::ifItem(*_map, _X, _Y+2) != 0 && player::ifItem(*_map, _X, _Y+2) != 2);
    }
    return 0;
}

