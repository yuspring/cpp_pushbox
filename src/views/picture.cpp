#include "picture.h"

std::map<std::string, picture> __mp;

picture::picture(std::string _name, std::string _path, SDL_Renderer * render){
    this->name = _name;
    this->tex = IMG_LoadTexture(render, _path.c_str());
}


SDL_Texture * picture::get_tex(){
    return this->tex;
}

std::map<std::string, picture> init_picture(SDL_Renderer * render){
    std::map<std::string, picture> mp;
    picture gress("green", "imgs/gress.png", render);
    picture wall("gray", "imgs/wall.png", render);
    picture player("test", "imgs/man.png", render);
    
    mp["gress"] = gress;
    mp["wall"] = wall;
    mp["player"] = player;
    return mp;
}
