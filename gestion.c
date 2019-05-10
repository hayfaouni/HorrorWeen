#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "gestion.h"
/**  * @brief  To initialize vie .  * @param vie the life  * @param url  the url of the image   * @return Nothing  */ 
void initialiservie(vie *vie)
{
vie->nb=3;
vie->position.x = 0 ;
vie->position.y = 0 ;
vie->position2.x = 0 ;
vie->position2.y = 0 ;
vie->fond1 = IMG_Load("v1.png");
vie->fond2 = IMG_Load("v2.png");
vie->fond3 = IMG_Load("v3.png");
vie->fond4 = IMG_Load("v4.png");
vie->fond5 = IMG_Load("GameOver.png");
}
/**  * @brief  To free life surface .  * @param vie the life  * @param url  the url of the image   * @return Nothing  */ 
void freesurfacevie(vie *vie)
{
SDL_FreeSurface(vie->fond1);
SDL_FreeSurface(vie->fond2);
SDL_FreeSurface(vie->fond3);
SDL_FreeSurface(vie->fond4);
SDL_FreeSurface(vie->fond5);
}
 /**  * @brief  To show life   surface .  * @param vie the life  * @param url  the url of the image   * @return Nothing  */ 

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
