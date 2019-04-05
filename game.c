#include <stdlib.h>
#include <stdio.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h" 
#include "personnage.h"
#include "initialiser.h"
#include "collision.h"
#include "deplacement.h"
#include "game.h"



void jouer (SDL_Surface *ecran)
{
	SDL_Event event;
	int continuer=1;
	int i=0;

	char fichierSprite[] = "PERSO.png";
    int nbLigne=1;
    int nbColonne=3;

    int tempsAnimation = 70;
    SDL_Rect position = {0,0};
    SDL_Rect * tabSpritePerso = NULL;
    SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,255,255,255));
	tabSpritePerso = decoupeSprite(fichierSprite, nbLigne, nbColonne);
	while(continuer)
	{

		SDL_PollEvent(&event);
		deplacement(&position, event, 10, 10);
        continuer = attendreAvantDeQuitter(event.type);
        backgroundColorSurface(ecran, 0, 0, 0);

        animerSprite(tabSpritePerso, ecran, fichierSprite, position, nbLigne, nbColonne, tempsAnimation);
        SDL_Flip(ecran);
																																																																																																																																																																																																																																																																																																																																																																																																																																																					
	}

}