#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "gestion.h"

void afficherscore(SDL_Surface *ecran,int score)
{

   SDL_Surface *texte = NULL;
    SDL_Rect position;
    SDL_Event event;
    TTF_Font *police = NULL;
    SDL_Color couleurNoire = {0, 0, 0};
    int continuer = 1;
   char txt[100];

    TTF_Init();

  police = TTF_OpenFont("o.ttf", 65);
    sprintf(txt, "score : %d ", score);

    texte = TTF_RenderText_Blended(police, txt, couleurNoire);

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
        }

       

        position.x = 300;
        position.y = 0;
        SDL_BlitSurface(texte, NULL, ecran, &position); 
        SDL_Flip(ecran);
    }

    TTF_CloseFont(police);
    TTF_Quit();

    SDL_FreeSurface(texte);
    SDL_Quit();

    //return EXIT_SUCCESS;
}

void initialiservie(vie *vie)
{
vie->nb=3;
vie->position.x = 0 ;
vie->position.y = 0 ;
vie->fond1 = IMG_Load("v1.png");
vie->fond2 = IMG_Load("v2.png");
vie->fond3 = IMG_Load("v3.png");
vie->fond4 = IMG_Load("v4.png");
vie->fond5 = IMG_Load("GameOver.png");
}
void freesurfacevie(vie *vie)
{
SDL_FreeSurface(vie->fond1);
SDL_FreeSurface(vie->fond2);
SDL_FreeSurface(vie->fond3);
SDL_FreeSurface(vie->fond4);
SDL_FreeSurface(vie->fond5);
}
 

void affichervie(vie *vie,perso perso,SDL_Surface *ecran)
{
SDL_Surface *image=NULL;
image= IMG_Load("menu.png");
vie->position.x=perso.position.x-30;
vie->position.y=perso.position.y-40;
if(vie->nb==3)
{
SDL_BlitSurface(vie->fond1,NULL, ecran,&vie->position);

}
if(vie->nb==2)
{
SDL_BlitSurface(vie->fond2,NULL, ecran,&vie->position);
}
if(vie->nb==1)
{
SDL_BlitSurface(vie->fond3,NULL, ecran,&vie->position);
}
if(vie->nb==0)
{
SDL_BlitSurface(vie->fond4,NULL, ecran,&vie->position);
SDL_BlitSurface(vie->fond5,NULL, ecran,&vie->position2);
vie->nb=3;
SDL_Flip(ecran);
SDL_Delay(2000);
 SDL_BlitSurface(image,NULL, ecran,0);
SDL_Flip(ecran);    
   	       // updateMenu(ecran); 

}
