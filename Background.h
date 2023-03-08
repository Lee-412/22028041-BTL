#ifndef BACKGROUND_H_
#define BACKGROUND_H_
#include "library.h"
#include "init_clean.h"


static SDL_Texture* image= NULL;
static SDL_Texture* character= NULL;

namespace SDLF
{
    void render(SDL_Texture* texture);
    SDL_Texture* loadimage(const char*  file_path);
}
#endif


