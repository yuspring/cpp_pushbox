#ifndef SRC_VIEWS_SCREEN_H
#define SRC_VIEWS_SCREEN_H

#include<SDL2/SDL.h>
#include<string>


class app{

    private:
        bool quit;
        SDL_Event event;
        SDL_Window *window;
        SDL_Surface *image;
        SDL_Texture *texture;
        SDL_Renderer *renderer;       

    public:
        app();
        ~app();

        void load_picture();
        void render();
        void screen();
        
        void init();
        
        void clear() const;
        void create_map();
        void pollEvents();
        void run();
        



};


#endif