#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
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


void jouer (SDL_Surface *ecran);

#endif