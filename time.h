#ifndef GESTION_H_
#define GESTION_H_

/**  * @struct vie  
* @brief struct for gestion de vie et affichage */ 
typedef struct vie
{
	int nb;
	SDL_Rect position; /*!< Rectangle*/
	SDL_Rect position2; /*!< Rectangle*/
	SDL_Surface *fond1;/*!< Surface. */ 
	SDL_Surface *fond2;/*!< Surface. */ 
	SDL_Surface *fond3;/*!< Surface. */ 
	SDL_Surface *fond4;/*!< Surface. */ 
	SDL_Surface *fond5;/*!< Surface. */ 
}vie;


void initialiservie(vie *vie);
void freesurfacevie(vie *vie);
void affichervie(vie *vie,perso perso,SDL_Surface *ecran);

#endif /* GESTION_H_ */
