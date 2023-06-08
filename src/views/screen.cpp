#include "screen.h"


app::app(){
    quit = false;
    _X = 80;
    _Y = 80;
    _map_name = "map1";
    game_run = false;
    show_switch = true;
}

app::~app(){
    TTF_CloseFont(ttf);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void app::init(){

    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    window = SDL_CreateWindow("C++ pushbox", 
                                SDL_WINDOWPOS_UNDEFINED, 
                                SDL_WINDOWPOS_UNDEFINED, 
                                500, 600, SDL_WINDOW_SHOWN);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    
    app::ttf_init();
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
                switch_map("map1");
            }
            else if (event.key.keysym.sym == SDLK_2){
                switch_map("map2");
            }
            else if (event.key.keysym.sym == SDLK_3){
                switch_map("map3");
            }
            else if (event.key.keysym.sym == SDLK_4){
                switch_map("map4");
            }
            else if (event.key.keysym.sym == SDLK_5){
                switch_map("map5");
            }
            else if(event.key.keysym.sym == SDLK_SPACE){
                if(!game_run){
                    switch_map("map1");
                    game_run = true;   
                }
            }
            else if(event.key.keysym.sym == SDLK_UP || event.key.keysym.sym == SDLK_DOWN || event.key.keysym.sym == SDLK_RIGHT || event.key.keysym.sym == SDLK_LEFT){
                show_switch = false;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 255);
        SDL_RenderClear(renderer);
        if(game_run){
            app::set_map_render(&map_mp[this->_map_name]);
            SDL_Rect ttf_ract_switch = {30, 350 ,450 ,40};
            if(show_switch){
                SDL_RenderCopy(renderer,ttf_switch ,NULL,&ttf_ract_switch);
            }
            if(_s._score == _dest.size()){
                SDL_Rect ttf_ract = {50, 400 ,400 ,50};
                SDL_RenderCopy(renderer,ttf_break ,NULL,&ttf_ract);
            }
        }
        else{
            SDL_Rect ttf_ract = {50, 350 ,400 ,40};
            SDL_Rect ttf_ract1 = {100, 150 ,300 ,40};
            SDL_RenderCopy(renderer,ttf_welcome,NULL,&ttf_ract);
            SDL_RenderCopy(renderer,ttf_welcome1 ,NULL,&ttf_ract1);
        }
        
        SDL_RenderPresent(renderer);
    }

}

void app::switch_map(std::string _str){
    map_mp = init_map();
    this->_map_name = _str;
    app::set_map_info(&map_mp[this->_map_name]);
    _s._score = 0;
    show_switch = true;
}

void app::ttf_init(){
    ttf = TTF_OpenFont("fonts/ka1.ttf",10);
    surfaceText = TTF_RenderText_Solid(ttf,"PUSH BOX",{0,0,0});
    ttf_welcome1 = SDL_CreateTextureFromSurface(renderer,surfaceText);
    surfaceText = TTF_RenderText_Solid(ttf,"PLEASE PRESS SPACE",{0,0,0});
    ttf_welcome = SDL_CreateTextureFromSurface(renderer,surfaceText);
    surfaceText = TTF_RenderText_Solid(ttf,"Congratulations",{0,0,0});
    ttf_break = SDL_CreateTextureFromSurface(renderer,surfaceText);
    surfaceText = TTF_RenderText_Solid(ttf,"press \"1\"to \"5\" to switch map",{0,0,0});
    ttf_switch = SDL_CreateTextureFromSurface(renderer,surfaceText);
}
