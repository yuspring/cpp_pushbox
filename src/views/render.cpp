#include "render.h"
#include <SDL2/SDL_image.h>

SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *renderer){
    SDL_Surface *image = IMG_Load(file.c_str());
    SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, image);
    return texture;
}

void renderTexture(SDL_Texture *tex, SDL_Renderer *renderer, int x, int y, int w, int h){
  SDL_Rect dst;
  dst.x = x;
  dst.y = y;
  dst.w = w;
  dst.h = h;
  SDL_RenderCopy(renderer, tex, NULL, &dst);
}
