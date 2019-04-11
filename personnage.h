#ifndef PERSONNAGE_H_INCLUDED
#define PERSONNAGE_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>


typedef struct personnage
{
	int sc;
	SDL_Surface *up[4],*down[4],*left[4],*right[4];
	SDL_Surface* stop;
	SDL_Rect position;
	int niveau;

}personnage;

void blitSpriteSurSurface(SDL_Surface * surfaceBlit, char * fileImage, SDL_Rect position, SDL_Rect * clip);

void blitImageSurSurface(SDL_Surface * surfaceBlit, char * fileImage, SDL_Rect position);

void backgroundColorSurface(SDL_Surface * surface, Uint8 rouge, Uint8 vert, Uint8 bleu);

void animerSprite(SDL_Rect * clip, SDL_Surface * surfaceBlit, char * fichierSprite, SDL_Rect position, int nbLigne, int nbColonne, int tempsAnimation);

void attendreTemps(int millisecondes);

SDL_Rect * decoupeSprite(char * fileSprite, int nbCaseLigne, int nbCaseCol);

#endif
