#ifndef MAINOBJECT_H_
#define MAINOBJECT_H_

#include "Background.h"
#include "library.h"
#include "BaseObject.h"

#define WIDTH_MAIN_OBJECT 64;
#define HEIGHT_MAIN_OBJECT 91

class MainObject :: public BaseObject
{
public:
    MainObject();
    ~Mainobject();

    void HandleIput (SDL_Event e);
    void Handlemove();

protected:
    int x_val;
    int y_val;
};


#endif // MAINOBJECT_H_
