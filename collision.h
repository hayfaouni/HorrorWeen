#ifndef COLLISION_H_INCLUDED
#define COLLISION_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>

#define BOTTOM 1
#define TOP 2
#define LEFT 3
#define RIGHT 4
#define RIEN 0


int testCollision(SDL_Rect obj1, SDL_Rect obj2, int * typeCollision);
void deplacementAutorise(int typeCollision, SDL_Rect * pos1, SDL_Event event, int vit_x, int vit_y,SDL_Surface *ecran,SDL_Rect * posCam);
int verifEtatToucheClavier();

#endif // COLLISION_H


