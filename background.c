#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "background.h"

void blitBackground (SDL_Surface * surfaceBlit, char * fileImage, SDL_Rect position)
{
	SDL_Surface *image=NULL;
	image = IMG_Load(fileImage);
	SDL_BlitSurface(image,NULL,surfaceBlit,&position);
	SDL_FreeSurface(image);
}