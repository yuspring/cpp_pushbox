#include "screen.h"


app::app(){
    quit = false;
    _X = 80;
    _Y = 80;
    _map_name = "map1";
}

app::~app(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void app::init(){

    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("My SDL Empty window", 
                                SDL_WINDOWPOS_UNDEFINED, 
                                SDL_WINDOWPOS_UNDEFINED, 
                                900, 900, SDL_WINDOW_SHOWN);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    

    map_mp = init_map();
    app::set_map_info(&map_mp[this->_map_name]);
    pic_mp = init_picture(renderer);

}

void app::set_map_info(map *_map){
    _player.set_coord(_coord_map.get_player_coord(*_map).x, _coord_map.get_player_coord(*_map).y);
    _map->map_edit(_player._x, _player._y, '.');


    _chest = _coord_map.init_chest(*_map);
    _dest = _coord_map.init_dest(*_map);
}
void app::set_map_render(map* _map){

    for(int i = 0; i < _chest.size(); i++){
            if(_chest[i].is_pushed(_player._x, _player._y)){
                _chest[i].move(_player._dire, _map);
            }
        }

    _map->map_render(pic_mp["gress"].tex(), renderer, '.');
    _map->map_render(pic_mp["wall"].tex(), renderer, '#');
    for(int i = 0; i < _dest.size(); i++){
        _dest[i].render(_dest[i]._rect,renderer, pic_mp["gray"].tex() );     
    }
    
    _map->map_render(pic_mp["chest"].tex(), renderer, 'C');
    
    _player.render(_player.player_walk(event, _map),renderer, pic_mp["player"].tex() );
    
    _s.detect_dest(*_map,_dest);
}

void app::run(){

    while(!quit){
        SDL_PollEvent(&event);

        if(event.type == SDL_QUIT){
            quit = true;
            break;
        }

        if(event.type == SDL_KEYDOWN){
            if (event.key.keysym.sym == SDLK_1){
                map_mp = init_map();
                this->_map_name = "map1";
                app::set_map_info(&map_mp[this->_map_name]);
            }
            else if (event.key.keysym.sym == SDLK_2){
                map_mp = init_map();
                this->_map_name = "map2";
                app::set_map_info(&map_mp[this->_map_name]);
            }
        }
        SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 255);
        SDL_RenderClear(renderer);
        app::set_map_render(&map_mp[this->_map_name]);
        SDL_RenderPresent(renderer);
    }

}

