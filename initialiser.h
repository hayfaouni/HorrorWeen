#ifndef INITIALISER_H_INCLUDED
#define INITIALISER_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

SDL_Surface * initEcran(char * titre, char * icone, int largeur, int hauteur);
int attendreAvantDeQuitter(Uint8 typeEvenement);

#endif