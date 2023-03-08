#include "BaseObject.h"
#include "MainObject.h"
#include "library.h"
#include "Background.h"

MainObject::MainObject()
{
    rect_x=0;
    rect_y=0;
    rect_w=WIDTH_MAIN_OBJECT;
    rect_h=HEIGHT_MAIN_OBJECT;
    x_val=0;
    y_val=0;
}

MainObject::~Mainobject()
{
    ;
}

void MainObject::HandleInput(SDL_Event e)
{
}

void MainObject::Handlemove()
{
}
