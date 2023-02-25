#include<iostream>
#include"SDL.h"
#include<string>
#include<SDL_image.h>
using namespace std;

SDL_Window* window;
SDL_Renderer* renderer;
const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 600;
const char* WINDOW_TITLE = "Tank_Ranarok";
void waitUntilKeyPressed();
void initSDL(SDL_Window* &window, SDL_Renderer* &renderer);
void quitSDL(SDL_Window* window, SDL_Renderer* renderer);
void logSDLError(std::ostream& os,
                 const std::string &msg, bool fatal = false);

void logSDLError(std::ostream& os,
                 const std::string &msg, bool fatal)
{
    os << msg << " Error: " << SDL_GetError() << std::endl;
    if (fatal) {
        SDL_Quit();
        exit(1);
    }
}

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer)
{

    if (SDL_Init(SDL_INIT_EVERYTHING)==0)
        cout<< "Working!!" << endl;

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) logSDLError(std::cout, "CreateRenderer", true);

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
}

void quitSDL(SDL_Window* window, SDL_Renderer* renderer)
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true) {
        if ( SDL_WaitEvent(&e) != 0 &&
             (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
            return;
        SDL_Delay(10);
    }
}

SDL_Texture* loadimage(const char*  file_path)
{
    SDL_Texture* load_image = NULL;
    load_image= IMG_LoadTexture(renderer, file_path);
    if(load_image==NULL)
    {
        cout<<"error"<<endl;
       // optimize_image=IMG_LoadTexture(renderer,file_path);
      //  SDL_RenderClear(renderer);
    }
    return load_image;
}

void render(SDL_Texture* texture)
{
    SDL_Rect src;
    src.x=0;
    src.y=0;
    src.w=256;
    src.h=256;

    SDL_Rect dst;
    dst.x=0;
    dst.y=0;
    dst.w=600;
    dst.h=600;
    SDL_RenderCopy(renderer,texture, &src, &dst);
}

int main(int argc, char** argv)
{
   // SDL_Texture* screen=NULL;
    SDL_Texture* image= NULL;

    window = SDL_CreateWindow( WINDOW_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT , SDL_WINDOW_SHOWN );
    image =loadimage("123.png");
    initSDL(window, renderer);

    SDL_RenderPresent(renderer);
    SDL_RenderClear(renderer);
     render(image);
    waitUntilKeyPressed();
    quitSDL(window, renderer);
    return 0;
}
