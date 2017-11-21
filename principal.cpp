
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "jugadores.cpp"
#include "tablero.cpp"
#include "mensajes.cpp"

//Programa principal llamador
int main(){
	setlocale(LC_ALL,"");
	int duracion;
	duracion=welcome();
	int players;
	players= primero();
	board(players,duracion);
	goodbye(players);
	getch();
	return 0;
}


	//Comprobación del funcionamiento del tablero.
	/*register int i,j;	
	printf("Propiedad\t casilla\t compra\t renta\t dueño");
	for(i=0;i<=31;i++){
		printf("\n%d-%s\t",i,nom_cas[i]);
		for(j=0;j<=3;j++){
			printf("%d\t",casillas[i][j]);}}*/
