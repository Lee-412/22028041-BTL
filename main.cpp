#include "library.h"
#include "Background.h"
#include "init_clean.h"

SDL_Texture* SDLF::loadimage(const char*  file_path)
{
    SDL_Texture* load_image = NULL;
    load_image= IMG_LoadTexture(renderer, file_path);
    if(load_image==NULL)
    {
        std::cout<<"error"<<std::endl;
    }
    return load_image;
}
void SDLF::render(SDL_Texture* texture)
{
    SDL_Rect src;
    src.x=0;
    src.y=0;
    src.w=256;
    src.h=256;

    SDL_Rect dst;
    dst.x=0;
    dst.y=0;
    dst.w=1200;
    dst.h=600;
    SDL_RenderCopy(renderer,texture, &src, &dst);
}


void renderchar(SDL_Texture* texture)
{
    SDL_Rect src;
    src.x=0;
    src.y=0;
    src.w=256;
    src.h=256;

    SDL_Rect dst;
    dst.x=0;
    dst.y=0;
    dst.w=64;
    dst.h=91;
    SDL_RenderCopy(renderer,texture, &src, &dst);
}

int main(int argc, char** argv)
{
    window = SDL_CreateWindow( WINDOW_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );

    INIT::initSDL(window, renderer);
    SDL_RenderClear(renderer);

    image =SDLF::loadimage("123.png");
    character=SDLF::loadimage("TANK1.png");
    SDLF::render(image);
    renderchar(character);

    SDL_RenderPresent(renderer);

    INIT::waitUntilKeyPressed();
    INIT::quitSDL(window, renderer);
    return 0;
}
