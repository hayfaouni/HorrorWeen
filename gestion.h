#ifndef GESTION_H_
#define GESTION_H_


typedef struct vie
{
	int nb;
	SDL_Rect position;
	SDL_Rect position2;
	SDL_Surface *fond1;
	SDL_Surface *fond2;
	SDL_Surface *fond3;
	SDL_Surface *fond4;
	SDL_Surface *fond5;
}vie;

void afficherscore(SDL_Surface *ecran,int score);
void initialiservie(vie *vie);
void freesurfacevie(vie *vie);
void affichervie(vie *vie,perso perso,SDL_Surface *ecran);

#endif /* GESTION_H_ */
