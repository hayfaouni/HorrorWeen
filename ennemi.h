#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
typedef struct
{
    SDL_Rect position;
    SDL_Surface *p1;
    SDL_Surface *p2;
    SDL_Surface *p3;
    SDL_Surface *p4;
    SDL_Surface *pa;
    SDL_Surface *pb;
    SDL_Surface *pc;
    SDL_Surface *pd;
}ennemis;
void initialiser_ennemi(ennemis *ennemi);
void free_surface_ennemi(ennemis *ennemi);
int decouper_ennemi(int y);
void afficher_ennemi(ennemis ennemi,int y,SDL_Surface *screen,SDL_Rect camera);

#endif // HEADER_H_INCLUDED
