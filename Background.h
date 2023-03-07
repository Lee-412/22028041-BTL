#ifndef BACKGROUND_H_
#define BACKGROUND_H_
#include "library.h"
#include "init_clean.h"


static const int SCREEN_WIDTH = 1200;
static const int SCREEN_HEIGHT = 600;
static const char* WINDOW_TITLE = "Tank_Ranarok";

static SDL_Window* window;
static SDL_Renderer* renderer;
static SDL_Texture* image= NULL;
static SDL_Texture* character= NULL;

namespace SDLF
{
   // void render(SDL_Texture* texture);
    //SDL_Texture* loadimage(const char*  file_path);
}


#endif


