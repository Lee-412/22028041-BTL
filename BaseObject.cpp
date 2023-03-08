#include "BaseObject.h"
#include "library.h"
#include "Background.h"

BaseObject::BaseObject()
{
    rect_.x=0;
    rect_.y=0;
    p_object =NULL;
}
BaseObject::SBaseObject()
{
    if(p_object!=NULL)
    {
        delete p_object;
        p_object=NULL;
    }
}

bool BaseObject::Loadimg(const char* file_path)
{
    p_object=SDLF::loadimage(file_path);
    if(p_object==NULL)
    {
        return false;
    }
    else return false;
}

void BaseObject::Show(SDL_Texture* des)
{
    if(p_object!=NULL)
    {
        SDLF::render(p_object);
    }
}
