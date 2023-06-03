#ifndef SRC_OBJECT_OBJECT
#define SRC_OBJECT_OBJECT
#include <SDL2/SDL.h>

class object{
    public :
        void render(SDL_Rect rec, SDL_Renderer * renderer, SDL_Texture * tex );
        void set_coord(int x, int y);
        //Up = 0; Down = 1; Left = 2; Right = 3
        void movement(int direction);
        SDL_Rect _rect;
        void set_rect(int x , int y);
        int _X;
        int _Y;
        int _x;
        int _y;

};

#endif
