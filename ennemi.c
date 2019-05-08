#include <stdio.h>
#include  <stdlib.h>
#include  <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "header.h"
void initialiser_ennemi(ennemis *ennemi)
{
    ennemi->position.x = 1000 ;
    ennemi->position.y = 430 ;
    ennemi->p1 = IMG_Load("p1.png");
    ennemi->p2 = IMG_Load("p2.png");
    ennemi->p3 = IMG_Load("p3.png");
    ennemi->p4 = IMG_Load("p4.png");
    ennemi->pa = IMG_Load("pa.png");
    ennemi->pb = IMG_Load("pb.png");
    ennemi->pc = IMG_Load("pc.png");
    ennemi->pd = IMG_Load("pd.png");
}
void free_surface_ennemi(ennemis *ennemi)
{
    SDL_FreeSurface(ennemi->p1);
    SDL_FreeSurface(ennemi->p2);
    SDL_FreeSurface(ennemi->p3);
    SDL_FreeSurface(ennemi->p4);
    SDL_FreeSurface(ennemi->pc);
    SDL_FreeSurface(ennemi->pd);
    SDL_FreeSurface(ennemi->pa);
    SDL_FreeSurface(ennemi->pb);
}
int decouper_ennemi(int y)
{
    switch(y)
    {
    case 1:
        {
            y=2;
            break;
        }
    case 2 :
        {
            y=3;
            break;
        }
    case 3 :
        {
            y=4;
            break;
        }
    case 4 :
        {
            y=5;
            break;
        }
    case 5:
        {
            y=6;
            break;
        }
    case 6:
        {
            y=7;
            break;
        }
    case 7 :
        {
            y=8;
            break;
        }
    case 8:
        {
            y=1;
            break;
        }
        
    }
       return y; 
}
void afficher_ennemi(ennemis ennemi,int y,SDL_Surface *screen,SDL_Rect camera)
{
    ennemi.position.x-=camera.x;
    switch(y)
    {
    case 1 :
        {
            SDL_BlitSurface(ennemi.p2,NULL,screen,&ennemi.position);
            break;
        }
    case 2 :
        {
            SDL_BlitSurface(ennemi.p3,NULL,screen,&ennemi.position);
            break;
        }
    case 3 :
        {
            SDL_BlitSurface(ennemi.p4,NULL,screen,&ennemi.position);
            break;
        }
    case 4 :
        {
            SDL_BlitSurface(ennemi.pa,NULL,screen,&ennemi.position);
            break;
        }
    case 5 :
        {
            SDL_BlitSurface(ennemi.pb,NULL,screen,&ennemi.position);
            break;
        }
    case 6 :
        {
            SDL_BlitSurface(ennemi.pc,NULL,screen,&ennemi.position);
            break;
        }
    case 7 :
        {
            SDL_BlitSurface(ennemi.pd,NULL,screen,&ennemi.position);
            break;
        }
    case 8 :
        {
            SDL_BlitSurface(ennemi.p1,NULL,screen,&ennemi.position);
            break;
        }
    }
}
