#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include "partie_graphique.h"
#include "jeu.h"
#include "cartes.h"

#define COTE_CARRE 150
#define ECART 5
#define MARGE 120

int quitter(int boucle_jeu){ //retourne à l'écran d'accueil
  boucle_jeu = 0;
  ChargerImageFond("./images/fond.jpg");
  ChoisirCouleurDessin(CouleurParNom("white"));
  EcrireTexte(300,200,"JEU DES PAIRES",2);
  EcrireTexte(300,215,"-------------------------",2);
  EcrireTexte(300,350,"- Niveau demo",2);
  EcrireTexte(300,450,"- Niveau facile",2);
  EcrireTexte(300,550,"- Niveau moyen",2);
  EcrireTexte(300,650,"- Niveau difficile",2);
  DessinerRectangle(1470,20,120,40);
  EcrireTexte(1470,50,"Quitter le jeu",1);
  return boucle_jeu;
}

void afficherCartes(int colonnes, int lignes, int** positions){ // affiche toutes les cartes de dos selon le niveau de difficulté
  int i;
  int j;
  for(i=MARGE; i<(colonnes*(COTE_CARRE+ECART)+MARGE); i+=COTE_CARRE+ECART){
    for(j=MARGE ; j<(lignes*(COTE_CARRE+ECART)+MARGE) ; j+=COTE_CARRE+ECART){
      ChargerImage("./images/dos.png",i,j,10,75,COTE_CARRE,COTE_CARRE);
    }
  }
}

void mode_demo(int** positions, int* cartes){
  /*lancer le jeu en mode démo*/
  int colonnes=2;
  int lignes=2;
  ChargerImageFond("./images/fond.jpg");
  DessinerRectangle(1430,20,160,40);
  EcrireTexte(1435,50,"Revenir au menu",1);
  EcrireTexte(50,75,"Niveau demo",2);
  afficherCartes(colonnes,lignes,positions);
  randomRemplir(positions,colonnes,lignes,colonnes*lignes);
  jeu(positions,cartes,colonnes,lignes);
    
}

void mode_facile(int** positions, int* cartes){
  /*lancer le jeu en mode facile*/
  int colonnes=4;
  int lignes=3;
  ChargerImageFond("./images/fond.jpg");
  DessinerRectangle(1430,20,160,40);
  EcrireTexte(1435,50,"Revenir au menu",1);
  EcrireTexte(50,75,"Niveau facile",2);
  afficherCartes(colonnes,lignes,positions);
  randomRemplir(positions,colonnes,lignes,colonnes*lignes);
  jeu(positions,cartes,colonnes,lignes);
}

void mode_moyen(int** positions, int* cartes){
  /*lancer le jeu en mode moyen*/
  int colonnes=6;
  int lignes=5;
  ChargerImageFond("./images/fond.jpg");
  DessinerRectangle(1430,20,160,40);
  EcrireTexte(1435,50,"Revenir au menu",1);
  EcrireTexte(50,75,"Niveau moyen",2);
  afficherCartes(colonnes,lignes,positions);
  randomRemplir(positions,colonnes,lignes,colonnes*lignes);
  jeu(positions,cartes,colonnes,lignes);
}

void mode_difficile(int** positions, int* cartes){
  /*lancer le jeu en mode difficile*/
  int colonnes=10;
  int lignes=5;
  ChargerImageFond("./images/fond.jpg");
  DessinerRectangle(1430,20,160,40);
  EcrireTexte(1435,50,"Revenir au menu",1);
  EcrireTexte(50,75,"Niveau difficile",2);
  afficherCartes(colonnes,lignes,positions);
  randomRemplir(positions,colonnes,lignes,colonnes*lignes);
  jeu(positions,cartes,colonnes,lignes);
  }



void partieGraphique(int* cartes, int** positions){ /*fonction affichage du menu*/
    int x;
    int y;
    int boucle_menu = 1 ;
    InitialiserGraphique();
    CreerFenetre(10,10,1920,1080);
    
    ChargerImageFond("./images/fond.jpg");
    ChoisirCouleurDessin(CouleurParNom("white"));
    EcrireTexte(300,200,"JEU DES PAIRES",2);
    EcrireTexte(300,215,"-------------------------",2);
    EcrireTexte(300,350,"- Niveau demo",2);
    EcrireTexte(300,450,"- Niveau facile",2);
    EcrireTexte(300,550,"- Niveau moyen",2);
    EcrireTexte(300,650,"- Niveau difficile",2);
    DessinerRectangle(1470,20,120,40);
    EcrireTexte(1470,50,"Quitter le jeu",1);
    
    while (boucle_menu == 1){
      if(SourisCliquee()){
	SourisPosition();/*récupère l'endroit où passe la souris*/
	 x=_X;
	 y=_Y;
	if (x>1470 && x<1590 && y>20 && y<60){
	boucle_menu = 0;
	}
	if (x>300 && x<600){
	  if (y>300 && y<350){
	    /*lancer le jeu en mode démo*/
	    mode_demo(positions,cartes);
	  }
	  if (y>400 && y<450){
	    /*lancer le jeu en mode facile*/
	    mode_facile(positions,cartes);
	  }
	  if (y>500 && y<550){
	    /*lancer le jeu en mode moyen*/
	    mode_moyen(positions,cartes);
	  }
	  if (y>600 && y<650){
	    /*lancer le jeu en mode difficile*/
	    mode_difficile(positions,cartes);
	  }
	}
      }
    }
    FermerGraphique();
}

