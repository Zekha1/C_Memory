#ifndef CARTE_H
#define CARTE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COTE_CARRE 150
#define ECART 5
#define MARGE 120


void remplirCartes(int* cartes);
void randomRemplir(int** positions, int colonnes, int lignes, int nbrCartes);

#endif 
