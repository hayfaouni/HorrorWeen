#include <stdio.h>
#include  <stdlib.h>
#include  <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "objects.h"

void initialiserObj( Objet *obj , char name[] , int x , int y ) 
{

	       obj->image =  IMG_Load(name); 
	      if  ( obj->image  ==  NULL )  { 
         printf ( "Can not load image of tux: %s \n " , SDL_GetError ());  
         exit ( 1 ); 
     } 
     else 
     {
 
     obj->position.x = x; 
     obj->position.y = y;
     obj->position.h = obj->image->h ;
     obj->position.w = obj->image->w ; 
}

}
void affichageObj ( Objet obj , SDL_Surface *screen,SDL_Rect camera) 
{
obj.position.x-=camera.x;
SDL_BlitSurface(obj.image, NULL, screen, &(obj.position));

}
void freesurfaceobject(Objet *obj){
SDL_FreeSurface(obj->image);
} 
