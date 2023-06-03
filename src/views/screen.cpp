#include "screen.h"


app::app(){
    quit = false;
    _X = 80;
    _Y = 80;
}

app::~app(){
    _mp.clear();
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
    
    //app::set_map();
    first_map.map_load("maps/map.txt");
    // P to .
    
    //std::cout << _coord_map.get_player_coord(first_map).x << " " << _coord_map.get_player_coord(first_map).y << '\n';
    _player.set_coord(_coord_map.get_player_coord(first_map).x, _coord_map.get_player_coord(first_map).y);
    first_map.map_edit(_player._x, _player._y, '.');
    //std::cout << _coord_map.get_player_coord(first_map).x << " " << _coord_map.get_player_coord(first_map).y << '\n';
    //set chest coord
    _chest = _coord_map.init_chest(first_map);
    //std::cout << _chest.size();
    //set destintaion coord
    _dest = _coord_map.init_dest(first_map);

    _mp = init_picture(renderer);

}


void app::run(){

    while(!quit){
        SDL_PollEvent(&event);

        if(event.type == SDL_QUIT){
            quit = true;
            break;
        }

        SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 255);
        SDL_RenderClear(renderer);
        
        

        for(int i = 0; i < _chest.size(); i++){
            if(_chest[i].is_pushed(_player._x, _player._y)){
                _chest[i].move(_player._dire, &first_map);
            }
        }
        first_map.map_render(_mp["gress"].tex(), renderer, '.');
        first_map.map_render(_mp["wall"].tex(), renderer, '#');
        for(int i = 0; i < _dest.size(); i++){
            _dest[i].render(_dest[i]._rect,renderer, _mp["gray"].tex() );     
        }
        
        first_map.map_render(_mp["chest"].tex(), renderer, 'C');
        
        _player.render(_player.player_walk(event, &first_map),renderer, _mp["player"].tex() );
        
        
        SDL_RenderPresent(renderer);
    }

}


void app::set_coord(){
    /*
    _player.set_coord(first_map.object.get_char_coord().x, first_map.object.get_char_coord().y);
    _chest.set_coord(first_map.object.get_chest_coord().x, first_map.object.get_chest_coord().y);
    _dest.set_coord(first_map.object.get_dest_coord().x, first_map.object.get_dest_coord().y);
    */
}

void app::set_map(){
    
    //first_map.map_edit(first_map.object.get_char_coord().y, first_map.object.get_char_coord().x, '.');
}
