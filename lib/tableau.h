#ifndef _TABLEAU_H_
#define _TABLEAU_H_

#define N 4 //la taille du jeu (N cartes)
#define M 4 //chaque carte est divisé en M partie

//VARIABLES
typedef struct zone_s{
  int element;//type de cette partie(sol,lave,pic,...)
  //affichage
}zone_t;

zone_t carte[M][M];//une carte
void jeu[M];//le jeu
int ordre[M];//indique comment les cartes sont conectées

//FONCTIONS
zone_t creation_zone(void);//création d'une zone
void creation_carte(jeu[M]);//création du jeu
void ordre_aleatoire(ordre[M]);//cartes mises aléatoirement
#endif
