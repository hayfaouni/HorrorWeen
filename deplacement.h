#ifndef DEPLACEMENT_H_INCLUDED
#define DEPLACEMENT_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>

void deplacement(SDL_Rect * pos, SDL_Event event, int vitesse_x, int vitesse_y);

#endif //DEPLACEMENT_H