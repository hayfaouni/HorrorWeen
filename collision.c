#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "collision.h"


int testCollision(SDL_Rect obj1, SDL_Rect obj2, int * typeCollision)
{
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    leftA = obj1.x;
    rightA = obj1.x + obj1.w;
    topA = obj1.y;
    bottomA = obj1.y + obj1.h;

    leftB = obj2.x;
    rightB = obj2.x + obj2.w;
    topB = obj2.y;
    bottomB = obj2.y + obj2.h;

    if( bottomA <= topB )
    {
        *typeCollision = BOTTOM;return 1;
    }


    if( topA >= bottomB )
    {
        *typeCollision = TOP;return 1;
    }

    if( rightA <= leftB )
    {
        *typeCollision = RIGHT;return 1;
    }

    if( leftA >= rightB )
    {
        *typeCollision = LEFT;return 1;
    }
    return 0;
}

void deplacementAutorise(int typeCollision, SDL_Rect * pos1, SDL_Event event, int vit_x, int vit_y)
{
    switch(typeCollision)
    {
        case BOTTOM :
                        switch(verifEtatToucheClavier())
                        {
                            case SDLK_UP : case SDLK_RIGHT : case SDLK_LEFT : deplacement(pos1, event, vit_x, vit_y);break;
                            default : break;
                        }break;
        case TOP :
                        switch(verifEtatToucheClavier())
                        {
                            case SDLK_DOWN : case SDLK_RIGHT : case SDLK_LEFT : deplacement(pos1, event, vit_x, vit_y);break;
                            default : break;
                        }break;
        case RIGHT :
                        switch(verifEtatToucheClavier())
                        {
                            case SDLK_UP : case SDLK_DOWN : case SDLK_LEFT : deplacement(pos1, event, vit_x, vit_y);break;
                            default : break;
                        }break;
        case LEFT :
                        switch(verifEtatToucheClavier())
                        {
                            case SDLK_UP : case SDLK_RIGHT : case SDLK_DOWN : deplacement(pos1, event, vit_x, vit_y);break;
                            default : break;
                        }break;
        default : break;
    }
}

