#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include "partie_graphique.h"
#include "cartes.h"

int main (void){ //petite fonction qui se contente de définir les principales variable et d'appeler les fonctions principale
  int i;
  int cartes[50];//cartes va servir à associer chaque carte à un numéro
  int** positions = (int**) malloc(50*sizeof(int*));// position associe chaque numéro à des coordonnées 
  for (i=0;i<50;i++){
    positions[i] = (int*) malloc(2*sizeof(int));
  }
  remplirCartes(cartes); 
  partieGraphique(cartes,positions);
  free(positions);
  return EXIT_SUCCESS; 
}
