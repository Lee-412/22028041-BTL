#ifndef BASEOBJECT_H_
#define BASEOBJECT_H_

#include"library.h"
#include "Background.h"
class BaseObject
{
    BaseObject();
    SBaseObject();
    SDL_Texture* p_object;
    void Show(SDL_Texture* des);
    void Loadimg(const char* file_path);
    void SetRect(int x, int y)
    {
        rect_.x=x;
        rect_.y=y;
    }
    SDL_Rect Getrect() const {return rect_;}

protected:
    SDL_Rect rect_;

};
#endif // BASEOBJECT_H_
