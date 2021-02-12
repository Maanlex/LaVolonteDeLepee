#ifndef _TABLEAU_H_
#define _TABLEAU_H_

#define N 4 //la taille du jeu (N cartes)
#define M 4 //chaque carte est divisé en M^2 partie

//VARIABLES
typedef struct zone_s{
  char element;//type de cette partie('s'ol, 'l'ave, 'p'ic, 'v'ide)
  char c;//affichage
}zone_t;

typedef struct carte_s{
  zone_t * carte[M][M];//une carte
  int nb_sol;//nombre de sol
  int nb_pic;//nombre de pic
  int nb_lave;//nombre de lave
  int nb_vide;//nombre de vide
}carte_t;

carte_t * jeu[N];//le jeu
int ordre[N];//indique comment les cartes sont conectées

//FONCTIONS
zone_t * creation_zone(void);//création d'une zone
carte_t * creation_carte(void);//création d'une carte
void creation_jeu(void);//création du jeu
int recherche_ordre(int, int);//recherche si r est déja dans ordre jusqu'à l
void ordre_aleatoire(void);//cartes mises aléatoirement

#endif
