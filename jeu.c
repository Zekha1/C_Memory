/* Ce programme sert au moment ou le joueur à passé l'interface et se met à jouer*/
#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include "jeu.h"
#include "partie_graphique.h"

#define COTE_CARRE 150
#define ECART 5
#define MARGE 120


/*retourne le numéro de la carte aux coordonnées cliquées*/
void retournerCarte(int numCarte, int* cartes, int x, int y){
  char nomCarte[25];
  sprintf(nomCarte,"./images/image%d.png",cartes[numCarte]);
  ChargerImage(nomCarte,x,y,0,0,COTE_CARRE,COTE_CARRE);
}
  
/*cache la carte si on n'a pas retourné de paires*/
  void cacherCarte(int carte,int** positions){
    int x=positions[carte][0];
    int y=positions[carte][1];
    ChargerImage("./images/dos.png",x,y,10,75,COTE_CARRE,COTE_CARRE);
}

/*retourne 1 si il y a une paire, 0 sinon*/
  int verifPaire(int carte1, int carte2, int* cartes){
    int paire=0;
    if (cartes[carte1]==cartes[carte2]){
      paire=1;
    }
    return paire;
  }

/*joue*/
void jeu( int** positions, int* cartes, int colonnes, int lignes){
    int* carteRetournees = (int*)malloc(sizeof(int));
    int x;
    int y;
    int nbrPaires=(colonnes*lignes)/2;
    int boucle_jeu=1;
    int boucle_victoire;
    int dejaRetournee=0;
    int nbrCartesRetournees=0;
    int numCarte[2]; //  tableau des deux cartes retournées 
    numCarte[0]=-1;
    numCarte[1]=-2;
    int nbrCartes=0;
    int XpositionCarte;
    int YpositionCarte;
    unsigned long temps_ecoule = 0;
    unsigned long temps = Microsecondes();
    int timer;
    int seconde_passee;
    int minutes = 0;
    int secondes = 0;
    int toucheT = 0;
    int temps_reference = 0;
    char afficher_temps[20];
    int temps_cartes_visibles;
    int i;
    int j;
    int k;
    int l;
    
      
    while ((nbrPaires > 0)&&(boucle_jeu==1)){ //boucle while principale

       temps_ecoule = (int) (Microsecondes() - temps); /*timer*/
       if (temps_reference<temps_ecoule){
	temps_reference += 1;
	timer = (int) (temps_ecoule / 1000000);
	if (timer != seconde_passee){
	  seconde_passee = timer;
	  secondes = timer;
	  if (secondes > 59){
	    minutes = secondes / 60;
	    secondes = secondes - (minutes * 60);
	  }
	  ChoisirCouleurDessin(CouleurParNom("white"));
	  RemplirRectangle(1000,25,130,30);
	  ChoisirCouleurDessin(CouleurParNom("black"));
	  snprintf(afficher_temps,20,"Time : %02d : %02d", minutes, secondes);
	  EcrireTexte(1000,50,afficher_temps,1);
	}
      }
       
       if (ToucheEnAttente()){ //mode tricheurs
	if (Touche()== XK_t){
	  toucheT = 1;
	  while (toucheT == 1){
	    /*montrer les cartes*/
	    for (i=0; i<(colonnes*lignes); i++){
	      retournerCarte(i, cartes, positions[i][0], positions[i][1]);
	    }
	      
	    if (ToucheEnAttente()){
	      if (Touche()== XK_t){
		/*cacher les cartes pas encore trouvées*/
		afficherCartes(colonnes, lignes, positions);
		for (i=0;i<nbrCartesRetournees;i++){
		  retournerCarte(carteRetournees[i],cartes,positions[carteRetournees[i]][0], positions[carteRetournees[i]][1]);
		}
		toucheT = 0;
		temps = Microsecondes() - temps_ecoule;
	      }
	    }
	  }
	}
      }
      	
       if(SourisCliquee()){ //jeu 
	SourisPosition();/*récupère l'endroit du clic de la souris*/
	x=_X;
	y=_Y;
	if (x>1430 && x<1550 && y>20 && y<60){
	  boucle_jeu=quitter(boucle_jeu);
	}
	
	else{ 
	  for (i=0;i<colonnes;i++){ /*pour chaque colonne*/
	    for (j=0;j<lignes;j++){ /*et chaque ligne :*/
	      dejaRetournee=0;	
	      XpositionCarte=i*(COTE_CARRE+ECART)+120;
	      YpositionCarte=j*(COTE_CARRE+ECART)+120;
	      if ( (XpositionCarte <= x)&&(x <= (XpositionCarte+150))&&(YpositionCarte <= y)&&(y <= (YpositionCarte+150))){ /*regarde si la position cliquée correspond à une position de carte*/
		for (k=0;k<(colonnes*lignes);k++){ 
		  if ((positions[k][0]==XpositionCarte)&&(positions[k][1]==YpositionCarte)){/*retrouve la carte correspondant aux coordonnées trouvées*/

		    
		    for (l=0;l<nbrCartesRetournees;l++){/*verifie que la carte n'a pas déja été retournée*/
		      if (carteRetournees[l]==k){
			dejaRetournee=1;
		      }
		    }
		    
		    if (dejaRetournee==0){ /*si la carte n'a pas deja été retournée, le programme continue. sinon, rien ne se passe*/
		      numCarte[nbrCartes]=k;
		      if(numCarte[0]!=numCarte[1]){		
			numCarte[nbrCartes]=k;
			retournerCarte(k, cartes, positions[k][0], positions[k][1]);
			nbrCartes+=1;
		      
			if (nbrCartes==2){ /*si les deux cartes ont été retournées :*/
			  if(verifPaire(numCarte[0],numCarte[1],cartes)==1){ //si les deux cartes sont des paires, elles restent retournées
			    nbrPaires-=1; //et le nombre de paires diminuent 
			    carteRetournees[nbrCartesRetournees]=numCarte[0];
			    nbrCartesRetournees+=1;
			    carteRetournees = realloc(carteRetournees,(nbrCartesRetournees+1)*sizeof(int));
			    carteRetournees[nbrCartesRetournees]=numCarte[1];
			    nbrCartesRetournees+=1;
			    carteRetournees = realloc(carteRetournees,(nbrCartesRetournees+1)*sizeof(int));
			  }
			  else{ //sinon, après 2 secondes les cartes se retournent 
			    temps_cartes_visibles = timer + 2;
			    while(temps_cartes_visibles > timer){
			      temps_ecoule = (int) (Microsecondes() - temps);
			      if (temps_reference<temps_ecoule){
				temps_reference += 1;
				timer = (int) (temps_ecoule / 1000000);
				if (timer != seconde_passee){
				  seconde_passee = timer;
				  secondes = timer;
				  if (secondes > 59){
				    minutes = secondes / 60;
				    secondes = secondes - (minutes * 60);
				  }
				  ChoisirCouleurDessin(CouleurParNom("white"));
				  RemplirRectangle(1050,25,100,30);
				  ChoisirCouleurDessin(CouleurParNom("black"));
				  snprintf(afficher_temps,20,"Time : %02d : %02d", minutes, secondes);
				  EcrireTexte(1000,50,afficher_temps,1);
				}
			      }
			    }
			    cacherCarte(numCarte[0],positions);
			    cacherCarte(numCarte[1],positions);
			  }
			  nbrCartes=0;
			  numCarte[0]=-1;
			  numCarte[1]=-2;
			}
		      }	    
		    }
		  }
		}
	      }
	    }
	  }
	}
      }
    }
    if (nbrPaires == 0){
      boucle_victoire = 1;
      ChargerImageFond("./images/fond.jpg");
      ChoisirCouleurDessin(CouleurParNom("white"));
      EcrireTexte(750,200,"BRAVO !!",2);
      snprintf(afficher_temps,20,"Time : %02d : %02d", minutes, secondes);
      EcrireTexte(750,300,afficher_temps,2);
      DessinerRectangle(750,400,250,60);
      EcrireTexte(765,445,"Retour menu",2);
      while( boucle_victoire == 1){
	if(SourisCliquee()){
	  SourisPosition();/*récupère l'endroit du clic de la souris*/
	  x=_X;
	  y=_Y;
	  if (x>750 && x<1000 && y>400 && y<460){
	    boucle_victoire=quitter(boucle_victoire);
	  }
	}
      }
    }
    free(carteRetournees);
}
