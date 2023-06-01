#include "object.h"


void object::render(SDL_Rect rec, SDL_Renderer *renderer, SDL_Texture *tex){
    //SDL_Rect rec = rec;
    SDL_RenderCopy(renderer, tex, nullptr, &rec);
}

void object::set_coord(int x, int y){
        _X = y * 40 + 40;
        _Y = x * 40 + 40;
        set_rect(_X, _Y);
}

void object::movement(int direction){
    switch(direction){
        case 0:{
            _Y -= 10;
            _Y -= 10;
            _Y -= 10;
            _Y -= 10;
            break;
        }

        case 1:{
            _Y += 10;
            _Y += 10;
            _Y += 10;
            _Y += 10;
            break;
        }

        case 2:{
            _X -= 10;
            _X -= 10;
            _X -= 10;
            _X -= 10;
            break;
        }

        case 3:{
            _X += 10;
            _X += 10;
            _X += 10;
            _X += 10;
            break;
        }
    }
}

void object::set_rect(int x, int y){
    this->_rect.x = _X;
    this->_rect.y = _Y;
    this->_rect.h = 40;
    this->_rect.w = 40;
}
