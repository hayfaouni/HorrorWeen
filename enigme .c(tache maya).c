#include<stdio.h> 
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h> 
#include <SDL/SDL_ttf.h>
#include <string.h>
#include <time.h>
#include "enigme.h"

void affichage(enigme *E,int val)
{
int reponse=-1;
srand ( time(NULL) );
int random =1;
random= rand() %3+1;
//declaration
	SDL_Surface *yes;
	SDL_Surface *no;
	SDL_Surface *back;

SDL_Surface *ecran = NULL, *imageDeFond = NULL;

	SDL_Init(SDL_INIT_VIDEO);	
	TTF_Init();
	TTF_Font *fonttexte;
	fonttexte=TTF_OpenFont("o.ttf",30);
	SDL_Color couleurtexte = {0,0 ,0 },couleur= {255,255 ,255 };
	SDL_Surface *screen;
	SDL_Surface *question;
	SDL_Surface *re3;
	SDL_Surface *re4;
	SDL_Rect posquestion;

	SDL_Rect posrep3;
	SDL_Rect posrep4;
	SDL_Rect rzlt;
SDL_Rect positionFond;
	
	//screen=SDL_SetVideoMode(800,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);
  SDL_Init(SDL_INIT_VIDEO);

   
  
    screen= SDL_SetVideoMode(650,365,0,SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Chargement d'images en SDL", NULL);

    imageDeFond = IMG_Load("background.png");
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);

//init
yes=IMG_Load("a.jpg");
no=IMG_Load("b.jpg");
back=IMG_Load("3.png");

	posquestion.x=255;
	posquestion.y=100;
	posrep3.x=100;
	posrep3.y=250;
	posrep3.h=100;
	posrep3.w=100;
	posrep4.x=355;
	posrep4.y=250;
	posrep4.h=100;
	posrep4.w=100;

	rzlt.x=0;
	rzlt.y=0;
	rzlt.h=705;
	rzlt.w=1300;
	positionFond.x =0;
    positionFond.y = 0;

    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
    
SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));


 re3=TTF_RenderText_Shaded(fonttexte,"Yes",couleurtexte,couleur);
 re4=TTF_RenderText_Shaded(fonttexte,"No",couleurtexte,couleur);
//SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));

				/* Blit du texte */
//affichage
	SDL_BlitSurface(re3, NULL,screen,&posrep3);
	SDL_BlitSurface(re4, NULL,screen,&posrep4);

//resolution

int continuer = 1;
SDL_Event event;
while (continuer)
{

SDL_PollEvent(&event);
switch(event.type)
{
case SDL_QUIT:
continuer = 0;
break ; 
case SDL_MOUSEBUTTONDOWN:
if( event.button.button == SDL_BUTTON_LEFT )
{
if(100<event.button.x&&event.button.x<200)
{if(250<event.button.y&&event.button.y<350)
{
reponse=1;
}
}
if(355<event.button.x&&event.button.x<455)
{if(250<event.button.y&&event.button.y<350)
{
reponse=0;
}
}
}
break;}
//generation&affichage
if(random==1){
question=TTF_RenderText_Shaded(fonttexte,"did you see wizards?",couleurtexte,couleur);}
else if(random==2){
question=TTF_RenderText_Shaded(fonttexte,"did you see some bats?",couleurtexte,couleur);}
else if(random==3){
question=TTF_RenderText_Shaded(fonttexte,"Is there spiders web?",couleurtexte,couleur);}
	SDL_BlitSurface(question, NULL,screen,&posquestion); 
if(random==1){

if(reponse==0){
	SDL_BlitSurface(yes, NULL,screen,&rzlt);
}
if(reponse==1){
	SDL_BlitSurface(no, NULL,screen,&rzlt);
}
}
if(random==2){

if(reponse==0){
	SDL_BlitSurface(no, NULL,screen,&rzlt);
}
if(reponse==1){
	SDL_BlitSurface(yes, NULL,screen,&rzlt);
}
}
if(random==3){

if(reponse==0){
	SDL_BlitSurface(no, NULL,screen,&rzlt);
}
if(reponse==1){
	SDL_BlitSurface(yes, NULL,screen,&rzlt);
}
}
SDL_Flip(screen);
}

TTF_CloseFont(fonttexte);
	TTF_Quit();
SDL_FreeSurface(question);
SDL_FreeSurface(re3);
SDL_FreeSurface(re4);
SDL_Quit();

}
//////////////////////////////////////////////////////////////////////////////////////////////////////////


