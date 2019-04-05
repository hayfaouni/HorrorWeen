#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "personnage.h"

void blitSpriteSurSurface(SDL_Surface * surfaceBlit, char * fileImage, SDL_Rect position, SDL_Rect * clip)
{
    SDL_Surface* loadedImage = NULL;
    loadedImage = IMG_Load(fileImage);
    SDL_BlitSurface(loadedImage, clip, surfaceBlit, &position);
    SDL_FreeSurface(loadedImage);
}

void blitImageSurSurface(SDL_Surface * surfaceBlit, char * fileImage, SDL_Rect position)
{
    SDL_Surface* loadedImage = NULL;
    loadedImage = IMG_Load(fileImage);
    SDL_BlitSurface(loadedImage, NULL, surfaceBlit, &position);
    SDL_FreeSurface(loadedImage);
}

void backgroundColorSurface(SDL_Surface * surface, Uint8 rouge, Uint8 vert, Uint8 bleu)
{
    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, rouge, vert, bleu));
}

SDL_Rect * decoupeSprite(char * fileSprite, int nbCaseLigne, int nbCaseCol)
{
    SDL_Surface * feuilleDeSprite = NULL;
    SDL_Rect * tabSprite;
    SDL_Rect coupe;
    int i,j;
    int nbCase=0;

    tabSprite = malloc((nbCaseCol*nbCaseLigne)*sizeof(SDL_Rect));
    feuilleDeSprite = IMG_Load(fileSprite);
    coupe.h = feuilleDeSprite->h/nbCaseLigne;
    coupe.w =feuilleDeSprite->w/nbCaseCol;

    for(i=0; i < nbCaseLigne; i++)
    {
        coupe.y = coupe.h*i;
        for(j=0;j<nbCaseCol; j++)
        {
            coupe.x = coupe.w*j;
            tabSprite[nbCase] = coupe;
            nbCase++;
        }
    }
    SDL_FreeSurface(feuilleDeSprite);
    return tabSprite;
}

void attendreTemps(int millisecondes)
{
    int startTicks = SDL_GetTicks();

    while((SDL_GetTicks() - startTicks) < millisecondes)
    {
        SDL_Delay(1);
    }
}



void animerSprite(SDL_Rect * clip, SDL_Surface * surfaceBlit, char * fichierSprite, SDL_Rect position, int nbLigne, int nbColonne, int tempsAnimation)
{
    static int i = 0;
    blitSpriteSurSurface(surfaceBlit, fichierSprite, position, &clip[i]);
    i++;
    if(i==(nbLigne*nbColonne))
        i=0;
    attendreTemps(tempsAnimation);
}
