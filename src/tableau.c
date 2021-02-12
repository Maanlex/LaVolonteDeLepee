#include <stdio.h>
#include "tableau.h"
#include <stdlib.h>
#include <time.h>

zone_t * creation_zone(int i){
  zone_t * z = malloc(sizeof(zone_t));
  switch(i){
    case 0 : z->element='s'; z->c='s';break;//affichage a remplir
    case 1 : z->element='p'; z->c='p'; break;
    case 2 : z->element='l'; z->c='l'; break;
    case 3 : z->element='v'; z->c='v'; break;
  }
  return(z);
}

carte_t * creation_carte(int n){
  srand(time(NULL));
  int i, j, k;
  int compt;
  carte_t * c = malloc(sizeof(carte_t));
  c->nb_sol = 0;
  c->nb_pic = 0;
  c->nb_lave = 0;
  c->nb_vide = 0;
  zone_t * z;
  switch(n){
    case 0: //ligne droite
      for(i=0;i<M;i++){
        for(j=0;j<M;j++){
         if(i<(M/2-1)||i>(M/2+1)){//avant (M/2)-2 et après (M/2)+2 ce n'est que du sol
         z = creation_zone(0);
         c->nb_sol++;
         }
         else{
          if((i==M/2)||((i==M/2-1))){//zone où le joueur n'a que du vide (déplacements)
            z = creation_zone(4);
            c->nb_vide++;
          }
          else{//pièges
            if(i%3==0){
              z = creation_zone(0);
              c->nb_sol++;
            }
            else{
              k = rand()%3;
              z = creation_zone(k);
              switch(k){
                case 0: c->nb_sol++;
                case 1: c->nb_pic++;
                case 2: c->nb_lave++;
              }
            }

          }
        }
        c->carte[i][j] = z;
        }
      }
    break;
    case 1: //monté a corriger
      compt = 0;
      for(i=0;i<M;i++){
        for(j=0;j<M;j++){
         if((i==j&&i==compt)||j==i+1||i==j+1){//zone où le joueur n'a que du vide (déplacements)
          z = creation_zone(4);
          c->nb_vide++;
         }
         else{//ce n'est que du sol en dehors de la diagonale
          z = creation_zone(0);
          c->nb_sol++;
        }
        c->carte[i][j] = z;
        }
        compt++;
      }
    break;
    case 2: //descente a corriger
    compt = M-1;
      for(i=0;i<M;i++){
        for(j=0;j<M;j++){
         if((i==j&&i==compt)||j==i+1||i==j-1){//zone où le joueur n'a que du vide (déplacements)
          z = creation_zone(4);
          c->nb_vide++;
         }
         else{//ce n'est que du sol en dehors de la diagonale
          z = creation_zone(0);
          c->nb_sol++;
        }
        c->carte[i][j] = z;
        }
        compt--;
      }
    break;
    case 3: //boss
    break;//case a rajouter avec l'apparence de la carte
  }
  return(c);
}

int creation_jeu(){
  int i;
  for(i=0;i<N;i++){//nb aleatoire choix carte
    jeu[i] = creation_carte(i);
  }
  return 1;
}

int destruction_jeu(){
  int i, j, k;
  for(k=0;k<N;k++){
    for(i=0;i<M;i++){
     for(j=0;j<M;j++){
       free(jeu[k]->carte[i][j]);
     }
    }
    free(jeu[k]);
    jeu[k] = NULL;
  }
  return 1;
}
