
#ifndef OBJECTS_H_
#define OBJECTS_H_

typedef struct 
{
SDL_Surface *image ; 
SDL_Rect position ; 

} Objet ; 

void initialiserObj( Objet *obj , char name[] , int x , int y ) ; 
void affichageObj ( Objet obj , SDL_Surface *screen,SDL_Rect camera) ;
void freesurfaceobject(Objet *obj);

#endif /* OBJECTS_H_ */


