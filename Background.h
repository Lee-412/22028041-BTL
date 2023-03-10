#ifndef BACKGROUND_H_
#define BACKGROUND_H_

#include "library.h"
#include "init_clean.h"
#include "BaseObject.h"


static SDL_Texture* c_background= NULL;
static SDL_Texture* c_character= NULL;
static SDL_Texture* c_screen= NULL;

namespace SDLF
{
    void render(SDL_Texture* texture);
    SDL_Texture* loadimage(const char*  file_path);
    void renderchar(SDL_Texture* texture, int x, int y);
}
#endif


