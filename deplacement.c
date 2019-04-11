#include <stdlib.h>
#include <stdio.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include "deplacement.h"
#include "personnage.h"


void deplacement(SDL_Rect * pos, SDL_Rect * posCam, SDL_Event event, int vitesse_x, int vitesse_y,SDL_Surface *ecran)
{

    char fichierSpriteL[] = "left.png";
    char fichierSpriteR[] = "right.png";
    int nbLigne=1;
    int nbColonne=6;
    int tempsAnimation = 70;

    SDL_Rect * tabSpritePersoL = NULL;
    SDL_Rect * tabSpritePersoR = NULL;

    tabSpritePersoL = decoupeSprite(fichierSpriteL, nbLigne, nbColonne);
    tabSpritePersoR = decoupeSprite(fichierSpriteR, nbLigne, nbColonne);

    if(event.type == SDL_KEYDOWN)
    {
        switch(event.key.keysym.sym)
        {
            case SDLK_UP: pos->y -= vitesse_y / 2; 
                            //blitSpriteSurSurface(ecran, fichierSpriteL,*pos,&tabSpritePersoL[0]);
                            break;
            case SDLK_DOWN: pos->y += vitesse_y / 2;
                            //blitSpriteSurSurface(ecran, fichierSpriteL,*pos,&tabSpritePersoL[0]);
                             break;
            case SDLK_LEFT: pos->x -= vitesse_x / 2;
                           // blitSpriteSurSurface(ecran, fichierSpriteL,*pos,&tabSpritePersoL[0]);
                            if (pos->x >= 300)
                            {
                                posCam->x+=vitesse_x / 2;
                            }
                            animerSprite(tabSpritePersoL, ecran, fichierSpriteL,*pos, nbLigne, nbColonne, tempsAnimation);
                            SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,255,255,255));
                            SDL_Flip(ecran);
                             break;
            case SDLK_RIGHT: pos->x += vitesse_x / 2;
                           // blitSpriteSurSurface(ecran, fichierSpriteR,*pos,&tabSpritePersoR[0]);
                            animerSprite(tabSpritePersoR, ecran, fichierSpriteR,*pos, nbLigne, nbColonne, tempsAnimation);
                            SDL_Flip(ecran);
                            break;
            default: break;
        }
    }
}