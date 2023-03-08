#ifndef INIT_CLEAN_H_
#define INIT_CLEAN_H_

#include "Background.h"
#include "library.h"



namespace INIT
{
    void waitUntilKeyPressed();
    void initSDL(SDL_Window* &window, SDL_Renderer* &renderer);
    void quitSDL(SDL_Window* window, SDL_Renderer* renderer);
    void logSDLError(std::ostream& os,const std::string &msg, bool fatal = false);

}

#endif // INIT_CLEAN_H_
