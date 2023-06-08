#include "picture.h"

std::map<std::string, picture> __mp;



picture::picture(std::string _name, std::string _path, SDL_Renderer *render){
    this->name = _name;
    this->texture = IMG_LoadTexture(render, _path.c_str());
}


SDL_Texture * picture::tex(){
    return this->texture;
}

std::map<std::string, picture> init_picture(SDL_Renderer * render){
    std::map<std::string, picture> mp;
    picture gress("green", "imgs/gress.png", render);
    picture wall("gray", "imgs/wall.png", render);
    picture player("player", "imgs/man.png", render);
    picture chest("chest", "imgs/box.png", render);
    picture gray("gray", "imgs/gray.bmp", render);

    mp["gress"] = gress;
    mp["wall"] = wall;
    mp["player"] = player;
    mp["chest"] = chest;
    mp["gray"] = gray;
    
    return mp;
}
