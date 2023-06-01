#ifndef SRC_OBJECT_OBJECT
#define SRC_OBJECT_OBJECT
#include <SDL2/SDL.h>
class object{
    public :
        void render(SDL_Rect rec, SDL_Renderer * renderer, SDL_Texture * tex );
        void set_coord(int x, int y);
        int _X;
        int _Y;
};

#endif
