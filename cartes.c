#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cartes.h"

#define COTE_CARRE 150
#define ECART 5
#define MARGE 120

/*associe chaque carte à un numéro de tableau*/
void remplirCartes(int* cartes){
  int i;
  int j;
  for (i=0, j=0 ;i<25;i++, j+=2){
    cartes[j]=i;
    cartes[j+1]=i;
  }
}

/*associe des cartes aléatoires aux positions données*/
void randomRemplir(int** positions, int colonnes, int lignes, int nbrCartes){
  srand(time(NULL));
  int i;
  int j;
  int k;
  int* cartesUtilisees=(int*)malloc(sizeof(int));
  int taille=0;
  int sortie;
  int valeur;
  int egalite;
  for (i=0; i<colonnes ; i++){
    for (j=0; j<lignes; j++){
      sortie=0;
      while (sortie==0){
	egalite=0;
	valeur = rand() % nbrCartes;
	for (k=0;k<taille;k++){
	  if (cartesUtilisees[k] == valeur) {
	    egalite = 1;
	  }
	}
	if (egalite==0){
	  positions [valeur][0]=i*(COTE_CARRE+ECART)+MARGE;
	  positions [valeur][1]=j*(COTE_CARRE+ECART)+MARGE;
	  sortie=1;
	  cartesUtilisees[taille]=valeur;
	  taille+=1;
	  cartesUtilisees=realloc(cartesUtilisees,(taille+1)*sizeof(int));
	}
      }
    }
  }
  free(cartesUtilisees);
}
