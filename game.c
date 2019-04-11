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
#include "background.h"


void jouer (SDL_Surface *ecran)
{
	SDL_Event event;
	int continuer=1;
	int i=0;
	int collision;
	char fichierSprite[] = "PERSO.png";
	char fichierBackground[]="background.png";

    SDL_Rect position = {0,0};
    SDL_Rect positionBG = {0,0};
    SDL_Rect positionImg2={320,240};
    
   
    SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,255,255,255));
	

 	SDL_Flip(ecran);

	while(continuer)
	{
		SDL_PollEvent(&event);

		if(testCollision(position,positionImg2, &collision)==0)
        {
            deplacement(&position,&positionBG, event, 30, 30,ecran);
        }
        else
        {
            deplacementAutorise(collision, &position, event, 30, 30,ecran,&positionBG);
        }


		
		
        continuer = attendreAvantDeQuitter(event.type);
       // backgroundColorSurface(ecran, 0, 0, 0);
        blitBackground(ecran,&fichierBackground,positionBG);
        blitImageSurSurface(ecran, "objet.png", positionImg2);
        /*animerSprite(tabSpritePerso, ecran, fichierSprite, position, nbLigne, nbColonne, tempsAnimation);
        SDL_Flip(ecran);*/


																																																																																																																																																																																																																																																																																																																																																																																																																																																					
	}
	   SDL_Quit();

}