#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "sauvegarde.h"

void savee(ennemis ennemi,perso perso,vie vie,SDL_Rect camera)
{
FILE *f;
f=fopen("save.bin","wb");
saves saves;
saves.ennemi=ennemi;
saves.camera=camera;
saves.perso=perso;
saves.vie=vie;
fwrite(&saves,sizeof(saves),1,f);
fclose(f);
}
void load(ennemis *ennemi,perso *perso ,vie *vie,SDL_Rect *camera,int *continuer,int *save)
{
FILE *f;
f=fopen("save.bin","rb");
saves saves;
fread(&saves,sizeof(saves),1,f);
fclose(f);
*ennemi=saves.ennemi;
*camera=saves.camera;
*perso=saves.perso;
vie->nb=saves.vie.nb;
}

