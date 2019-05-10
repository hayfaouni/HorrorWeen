#ifndef SAUVEGARDE_H_
#define SAUVEGARDE_H_

typedef struct saves
{
perso perso;
SDL_Rect camera;
ennemis ennemi;
vie vie;
}saves;

void savee(ennemis ennemi,perso perso,vie vie,SDL_Rect camera);
void load(ennemis *ennemi,perso *perso ,vie *vie,SDL_Rect *camera,int *continuer,int *save);

#endif /* SAUVEGARDE_H_ */
