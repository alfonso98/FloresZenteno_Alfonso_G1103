#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int welcome(){//funcion con mensaje de bienvenida y seleccion del tiempo de juego.
	int dur;
	printf("********************BIENVENIDOS A********************\n");
	printf("*******************Landlord's Game*******************\n");
	printf("\n      $$$$$ $$$$$ $$$$$ $$$$$ $     $$$$$ $   $");
	printf("\n      $   $ $     $   $   $   $     $   $ $$  $");
	printf("\n      $$$$$ $     $$$$$   $   $     $$$$$ $ $ $");
	printf("\n      $   $ $     $   $   $   $     $   $ $  $$");
	printf("\n      $   $ $$$$$ $   $   $   $$$$$ $   $ $   $");
	printf("\n________________________       ________________________");
	printf("\n________________________EDITION________________________");
	getch();
	printf("\n\nSelecciona una duración:\n\t1-15 min.\n\t2-30 min\n\t3-45 min\n\t-");
	scanf("%d",&dur);
	switch(dur){
		case 1: return 15; break;
		case 2: return 30; break;
		case 3: return 45; break;
		default: printf("\nOpción inválida, se inica a 15 min."); return 15; break;
	}
	getch();
	system("cls");
	fflush(stdin);
}

int goodbye(int pl){
	system("cls");
	printf("\n********************Fin del Juego*******************");
	printf("\n\nEstadísticas:");
	register int y, w;
	for(y=1;y<=pl; y++){
		printf("\n\nJugador: %s",nombres[y]);
		printf("\n\tDinero Final: %d",jugadores[y][0]);
		printf("\n\tPropiedades: ");
		for(w=0;w<=31;w++){//Buscador de propiedades
				if(casillas[w][3]==pl){
					printf("\n\t\t-%s",nomcas[w]);
				}
			}
	}
	printf("\n\n*****************Gracias por Jugar*****************\n");
	printf("*******************Landlord's Game*******************\n");
	printf("\n      $$$$$ $$$$$ $$$$$ $$$$$ $     $$$$$ $   $");
	printf("\n      $   $ $     $   $   $   $     $   $ $$  $");
	printf("\n      $$$$$ $     $$$$$   $   $     $$$$$ $ $ $");
	printf("\n      $   $ $     $   $   $   $     $   $ $  $$");
	printf("\n      $   $ $$$$$ $   $   $   $$$$$ $   $ $   $");
	printf("\n________________________       ________________________");
	printf("\n________________________EDITION________________________");
	fflush(stdin);
	return 0;
}
