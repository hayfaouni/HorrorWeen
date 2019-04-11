#include <stdlib.h>
#include <stdio.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include "initialiser.h"

//****fonction creation d'une fenetre avec une icone 
SDL_Surface * initEcran(char * titre, char * icone, int largeur, int hauteur)
{
    SDL_Surface *ecran = NULL;
    SDL_Init(SDL_INIT_VIDEO);

    SDL_WM_SetIcon(IMG_Load(icone), NULL);
    ecran = SDL_SetVideoMode(largeur, hauteur, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    if (ecran == NULL)
    {
        fprintf(stderr, "Impossible de charger le mode vidéo : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    SDL_WM_SetCaption(titre, NULL);

    return ecran;
}

int attendreAvantDeQuitter(Uint8 typeEvenement)
{
    int continuer = 1 ;
    switch(typeEvenement)
    {
        case SDL_QUIT:
            continuer = 0;break;
        case SDLK_ESCAPE:
            continuer = 0;break;   
        default : break;
    }
    return continuer;
}