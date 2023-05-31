#ifndef SRC_VIEWS_PICTURE
#define SRC_VIEWS_PICTURE

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <map>

std::map<std::string, picture> mp;

class picture{
    public :
        void pic_set(std::string _PATH);
        void pic_init();
        void pic_get(std::string _NAME);
        std::string file_path;
        SDL_Surface *image;
};


#endif