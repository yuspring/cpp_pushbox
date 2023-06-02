#include "screen.h"


app::app(){
    quit = false;
    _X = 80;
    _Y = 80;
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
    
    
    app::set_map();
    app::set_coord();
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
        //first_map.map_render(_mp["wall"].tex(), _mp["gress"].tex(),_mp["chest"].tex(), renderer);
        first_map.map_render(_mp["gress"].tex(), renderer, '.');
        first_map.map_render(_mp["wall"].tex(), renderer, '#');
        _dest.render(_dest._rect,renderer, _mp["gray"].tex() );
        first_map.map_render(_mp["chest"].tex(), renderer, 'C');
        _player.render(_player.player_walk(event, &first_map, &_chest),renderer, _mp["player"].tex() );
        SDL_RenderPresent(renderer);
    }

}

void app::set_coord(){
    _player.set_coord(first_map.object.get_char_coord().x, first_map.object.get_char_coord().y);
    _chest.set_coord(first_map.object.get_chest_coord().x, first_map.object.get_chest_coord().y);
    _dest.set_coord(first_map.object.get_dest_coord().x, first_map.object.get_dest_coord().y);
}

void app::set_map(){
    first_map.map_load("maps/map1.txt");
    first_map.map_edit(first_map.object.get_char_coord().y, first_map.object.get_char_coord().x, '.');
}
