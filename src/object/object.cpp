#include "object.h"


void object::render(SDL_Rect rec, SDL_Renderer *renderer, SDL_Texture *tex){
    //SDL_Rect rec = rec;
    SDL_RenderCopy(renderer, tex, nullptr, &rec);
}

void object::set_coord(int x, int y)
{
        _X = y * 40 + 40;
        _Y = x * 40 + 40;
}