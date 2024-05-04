#ifndef JEU_H
#define JEU_H

#include <stdlib.h>
#include <stdio.h>
#include <graph.h>

#define COTE_CARRE 150
#define ECART 5
#define MARGE 120

void retournerCarte(int numCarte, int* cartes, int x, int y);
void cacherCarte(int carte, int** positions);
int verifPaire(int carte1, int carte2, int* cartes);
void jeu(int** positions, int* cartes, int colonnes, int lignes);


#endif
