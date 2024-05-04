#ifndef PARTIE_GRAPHIQUE
#define PARTIE_GRAPHIQUE

#include <stdio.h>
#include <stdlib.h>
#include <graph.h>

#define COTE_CARRE 150
#define ECART 5
#define MARGE 120

int quitter(int boucle_jeu);
void afficherCartes(int colonnes, int lignes, int** positions);
void mode_demo(int** positions, int* cartes);
void mode_facile(int** positions, int* cartes);
void mode_moyen(int** positions, int* cartes);
void mode_difficile(int** positions, int* cartes);
void partieGraphique(int* cartes, int** positions);

#endif
