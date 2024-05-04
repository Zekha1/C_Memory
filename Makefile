Memory.exe : main.o partie_graphique.o jeu.o cartes.o
	gcc -o Memory.exe main.o partie_graphique.o jeu.o cartes.o -lgraph

main.o : main.c cartes.h partie_graphique.h
	gcc -c main.c -lgraph

partie_graphique.o : partie_graphique.c partie_graphique.h jeu.h cartes.h
	gcc -c partie_graphique.c -lgraph

jeu.o : jeu.c jeu.h partie_graphique.h
	gcc -c jeu.c -lgraph

cartes.o : cartes.c cartes.h
	gcc -c cartes.c -lgraph
