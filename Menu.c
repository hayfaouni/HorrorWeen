#include <stdlib.h>
#include <stdio.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h" 

 typedef struct input

{

    char key[SDLK_LAST];
    int mousex,mousey;
    char mousebuttons[8];
        char quit;

} Input;

void UpdateEvents(Input* in)

{

  SDL_Event event;

  while(SDL_PollEvent(&event))

  {

          switch (event.type)

          {

            case SDL_KEYDOWN:

                in->key[event.key.keysym.sym]=1;

                break;

            case SDL_KEYUP:

                in->key[event.key.keysym.sym]=0;

                break;
            case SDL_MOUSEMOTION:

                in->mousex=event.motion.x;

                in->mousey=event.motion.y;

                break;

            case SDL_MOUSEBUTTONDOWN:

                in->mousebuttons[event.button.button]=1;

                break;

            case SDL_MOUSEBUTTONUP:

                in->mousebuttons[event.button.button]=0;

                break;

           }

  }
}


int main(int argc, char *argv[])
{
  //declaration  des images
  SDL_Surface *ecran=NULL,*background=NULL,*play=NULL,*play_on=NULL,*setting=NULL,*settings_on=NULL,*story=NULL,*story_on=NULL,*credits=NULL,*credits_on=NULL,*quit=NULL,*quit_on=NULL;
  //declaration des positions
  SDL_Rect  positionBG,positionPlay,positionPlay_on,positionSettings,positionSettings_on,positionStory,positionStory_on,positionCredits,positionCredits_on,positionQuit,positionQuit_on;
  //declaration Evenement
  SDL_Event event;
  //declaration Music et song 
  Mix_Music *music;

  Input in;
  int verif;

  // declaration couleur blanche
  SDL_Color couleurBlanc = {255, 255, 255};

  //initialisation des positions 
  positionBG.x = 0;
  positionBG.y = 0;

  positionPlay.x = 750;
  positionPlay.y = 350;
  positionPlay_on.x = 750;
  positionPlay_on.y = 350;

  positionSettings.x = 750;
  positionSettings.y = 510;
  positionSettings_on.x = 750;
  positionSettings_on.y = 510;

  positionCredits.x = 750;
  positionCredits.y = 670;
  positionCredits_on.x = 750;
  positionCredits_on.y = 670;

  positionQuit.x = 750;
  positionQuit.y = 830;
  positionQuit_on.x = 750;
  positionQuit_on.y = 830;

  SDL_Init(SDL_INIT_VIDEO);

  ecran = SDL_SetVideoMode(1920,1080, 32, SDL_HWSURFACE);

  background=IMG_Load("Menu.png");
  play=IMG_Load("play.png");
  play=IMG_Load("play_on.png");
  setting=IMG_Load("Settings.png");
  setting=IMG_Load("Settings_on.png");
  credits=IMG_Load("credits.png");
  credits=IMG_Load("credits_on.png");
  quit=IMG_Load("Quit.png");
  quit=IMG_Load("Quit_on.png");

  SDL_Flip(ecran);

      if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)

   {

      printf("%s", Mix_GetError());

   }

  
  music = Mix_LoadMUS("Chilling - Adventures.mp3");
  Mix_PlayMusic(music, -1);

  SDL_BlitSurface(background,NULL,ecran,&positionBG);
  SDL_BlitSurface(play,NULL,ecran,&positionPlay);
  SDL_BlitSurface(setting,NULL,ecran,&positionSettings);
  SDL_BlitSurface(credits,NULL,ecran,&positionCredits);
  SDL_BlitSurface(quit,NULL,ecran,&positionQuit);
  SDL_Flip(ecran);


  memset(&in,0,sizeof(in));
  //Game loop
  while(in.key[SDLK_ESCAPE]!=1)
  {
    UpdateEvents(&in);
    // boutton play  
      if((in.mousex>750)&&(in.mousex<750+positionPlay.w)&&(in.mousey>350)&&(in.mousey<350+positionPlay.h))
      {
        SDL_BlitSurface(play_on,NULL,ecran,&positionPlay_on);
        SDL_BlitSurface(play,NULL,ecran,&positionPlay);
        SDL_Flip(ecran);


      if(in.mousebuttons[SDL_BUTTON_LEFT])
        {
          //click on play
          verif=1;
        }
      }
   // boutton settings   
      if((in.mousex>750)&&(in.mousex<750+positionSettings.w)&&(in.mousey>510)&&(in.mousey<510+positionSettings.h))
      {
        SDL_BlitSurface(settings_on,NULL,ecran,&positionSettings_on);
        SDL_BlitSurface(setting,NULL,ecran,&positionSettings);
        SDL_Flip(ecran); 

        if(in.mousebuttons[SDL_BUTTON_LEFT])
        {
          //click on settings
          verif=1;
        }
      }
    // Boutton credits 
      if((in.mousex>750)&&(in.mousex<750+positionCredits.w)&&(in.mousey>670)&&(in.mousey<670+positionCredits.h))
      {
        SDL_BlitSurface(credits_on,NULL,ecran,&positionCredits_on);
        SDL_BlitSurface(credits,NULL,ecran,&positionCredits);
        SDL_Flip(ecran); 

        if(in.mousebuttons[SDL_BUTTON_LEFT])
        {
          //click on settings
          verif=1;
        }

    //boutton quit  
      if((in.mousex>750)&&(in.mousex<750+positionQuit.w)&&(in.mousey>830)&&(in.mousey<830+positionQuit.h)) 
      {
        SDL_BlitSurface(quit_on,NULL,ecran,&positionQuit_on);
        SDL_BlitSurface(quit,NULL,ecran,&positionQuit);
        SDL_Flip(ecran);

        if(in.mousebuttons[SDL_BUTTON_LEFT])
          {
            in.key[SDLK_ESCAPE]=1;
            break;
          }
      }
    
  SDL_BlitSurface(background,NULL,ecran,&positionBG);
  SDL_BlitSurface(play,NULL,ecran,&positionPlay);
  SDL_BlitSurface(setting,NULL,ecran,&positionSettings);
  SDL_BlitSurface(credits,NULL,ecran,&positionCredits);
  SDL_BlitSurface(quit,NULL,ecran,&positionQuit);
  SDL_Flip(ecran);

  }
 } 

  SDL_FreeSurface(play);
  SDL_FreeSurface(credits);
  SDL_FreeSurface(setting);
  SDL_FreeSurface(quit);
  SDL_FreeSurface(play_on);
  SDL_FreeSurface(credits_on);
  SDL_FreeSurface(settings_on);
  SDL_FreeSurface(quit_on);
  
  Mix_FreeMusic(music); 
    Mix_CloseAudio(); 

    SDL_Quit();

  return EXIT_SUCCESS;
}