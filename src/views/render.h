#ifndef SRC_VIEWS_RENDER
#define SRC_VIEWS_RENDER

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *renderer);
void renderTexture(SDL_Texture *tex, SDL_Renderer *renderer, int x, int y, int w, int h);

#endif