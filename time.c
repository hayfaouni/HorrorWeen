#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include "time.h"
/**  * @brief  To show time .  * @param tempsInit  police  color* @param url  the url of the image   * @return  SDL_Surface  */ 

SDL_Surface *AffTemps(Uint32 tempsInit,TTF_Font *police,SDL_Color color)
{
    char ch[20];
    int miin,seec;
    seec=((SDL_GetTicks()-tempsInit)/1000)%60;
    miin=((SDL_GetTicks()-tempsInit)/1000)/60;
    if(miin<10 && seec<10)
        sprintf(ch,"0%d:0%d",miin,seec);
    else if(miin>=10 && seec<10)
        sprintf(ch,"%d:0%d",miin,seec);
    else if(miin>10 && seec>10)
        sprintf(ch,"%d:%d",miin,seec);
    else if(miin<10 && seec>=10)
    sprintf(ch,"0%d:%d",miin,seec);
        SDL_Surface *MS;
    MS=TTF_RenderText_Blended(police,ch,color);
    return MS;
}
