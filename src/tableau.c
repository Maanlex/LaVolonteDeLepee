#include <stdio.h>
#include <tableau.h>
#include <stdlib.h>

zone_t * creation_zone(){
  srand(time(NULL));
  zone_t * z = malloc(sizeof(zone_t));
  int i = rand() % 4;
  switch(i){
    case 0 : z->element="s"; z->c="s";break;//affichage a remplir
    case 1 : z->element="p"; z->c="p"; break;
    case 2 : z->element="l"; z->c="l"; break;
    case 3 : z->element="v"; z->c="v"; break;
  }
  return(z);
}

carte_t * creation_carte(){
  int i, j;
  carte_t * c = malloc(sizeof(carte_t));
  zone_t * z;
  for(i=0;i<M;i++){
    for(j=0;j<M;j++){
      z = creation_zone();
      switch (z->element){
        case "s" : c->nb_sol++; break;
        case "p" : c->nb_pic++; break;
        case "l" : c->nb_lave++; break;
        case "v" : c->nb_vide++; break;
      }
      c->carte[i][j] = z;
    }
  }
  return(c);
}

void creation_jeu(){
  int i;
  for(i=0;i<N;i++){
    jeu[i] = creation_carte();
  }
}

int recherche_ordre(int n, int l){
  int i;
  for(i=0;i<=l;i++){
    if(ordre[i]==n){
      return 1;
    }
  }
  return 0;
}

void ordre_aleatoire(){
  srand(time(NULL));
  int r, i;
  for(i=0;i<N;i++){
    r = rand() % N;
    if(!recherche_ordre(r, i)){
      ordre[i] = r;
    }
    else{
      i--;
    }
  }
}
