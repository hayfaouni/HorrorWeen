#include <stdlib.h>
#include <stdio.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include "deplacement.h"


void deplacement(SDL_Rect * pos, SDL_Event event, int vitesse_x, int vitesse_y)
{
    if(event.type == SDL_KEYDOWN)
    {
        switch(event.key.keysym.sym)
        {
            case SDLK_UP: pos->y -= vitesse_y / 2; break;
            case SDLK_DOWN: pos->y += vitesse_y / 2; break;
            case SDLK_LEFT: pos->x -= vitesse_x / 2; break;
            case SDLK_RIGHT: pos->x += vitesse_x / 2; break;
            default: break;
        }
    }
}