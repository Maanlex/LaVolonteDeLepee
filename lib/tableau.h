#ifndef _TABLEAU_H_
#define _TABLEAU_H_

#define N 4 //la taille du jeu (N cartes)
#define M 5 //chaque carte est divisé en M^2 partie

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

//FONCTIONS
zone_t * creation_zone(int);//création d'une zone
carte_t * creation_carte(int);//création d'une carte
int creation_jeu(void);//création du jeu
int destruction_jeu(void);

#endif
