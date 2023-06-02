#ifndef SRC_VIEWS_PICTURE
#define SRC_VIEWS_PICTURE

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <map>


class picture{
    private:
        std::string name;
        SDL_Texture *texture;
    public :
        picture() = default;
        picture(std::string _name, std::string _path, SDL_Renderer * render);
        SDL_Texture * tex();
        
};

std::map<std::string, picture> init_picture(SDL_Renderer * render);


#endif