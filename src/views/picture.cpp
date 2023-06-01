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
    picture green("green", "imgs/green.bmp", render);
    picture gray("gray", "imgs/gray.bmp", render);
    picture test("test", "imgs/test.bmp", render);
    
    mp["green"] = green;
    mp["gray"] = gray;
    mp["test"] = test;
    return mp;
}
