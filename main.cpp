#include "library.h"
#include "Background.h"
#include "init_clean.h"
#include "MainObject.h"
#include "BaseObject.h"
MainObject charac_object;
int x; int y;
void SDLF::renderchar(SDL_Texture* texture, int x, int y)
{
    SDL_Rect src;
    src.x=0;
    src.y=0;
    src.w=256;
    src.h=256;

    SDL_Rect dst;
    dst.x=x;
    dst.y=y;
    dst.w=64;
    dst.h=91;
    SDL_RenderCopy(renderer,texture, &src, &dst);
    SDL_RenderPresent(renderer);
    SDLF::render(c_background);
}

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
void waitUntilKeyPressed()
{
      SDL_Event e;
    while (true)
    {
        if ( SDL_PollEvent(&e) != 0 && (e.type == SDL_QUIT ) )
               return;
        else
        {
            charac_object.HandleInput(e);
            charac_object.Show(c_character,x,y);
            charac_object.Handlemove(x,y);
        }
    SDL_Delay(8);
    }
}

int main(int argc, char** argv)
{
    window = SDL_CreateWindow( WINDOW_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );

    INIT::initSDL(window, renderer);
    SDL_RenderClear(renderer);

    c_background =SDLF::loadimage("123.png");
    c_character=SDLF::loadimage("TANK1.png");
    SDLF::render(c_background);

    charac_object.SetRect(0,0);
    bool ret = charac_object.Loadimg("TANK1.png");
    if (!ret)
    {
        return 0;
    }
    charac_object.Show(c_character,x,y);

    SDL_RenderPresent(renderer);
    waitUntilKeyPressed();

    INIT::quitSDL(window, renderer);

    return 0;
}
