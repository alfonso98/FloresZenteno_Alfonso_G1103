#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

//Programa de creaci�n de jugadores, acepta m�nimo 2 y m�ximo 5

char nombres[6][15];//arreglo con nombres de jugadores

int jugadores[6][3]={{0,0,0},{15000,0,0},{15000,0,0},{15000,0,0},{15000,0,0},{15000,0,0}};//arreglo con num. de jugador, dinero y posici�n en el tablero

//arreglo que contiene los valores de compra y renta de cada casilla en el tablero.

int primero(){
	setlocale(LC_ALL,"");
	//Primero ingresamos 2 jugadores que es el m�nimo
	system("cls");
	fflush(stdin);
	int i, opc, num=2;//var-num me da el n�mero de jugadores minimo
	printf("-Dame el nombre del jugador 1:\n\t");
	gets(nombres[1]);
	system("cls");
	printf("-Dame el nombre del jugador 2:\n\t");
	gets(nombres[2]);
	
	//Ahora preguntamos si habr� m�s jugadores para a�adir hasta 5
	system("cls");
	printf("\n�Desea ingresar m�s jugadores? 1-SI 2-NO  ");
	fflush(stdin);
	scanf("%d",&opc);
	//Este ciclo se ocupa de guardar los dem�s nombres hasta que se cumpla
	i=3;
	while(opc==1 && i<=5){
		fflush(stdin);
		system("cls");
		printf("-Dame el nombre del jugador %d:\n\t",i);
		gets(nombres[i]);
		num+=1;
		i+=1;
		if(num<5){
		printf("\n�Desea ingresar m�s jugadores? 1-SI 2-NO  ");
		scanf("%d",&opc);
		}
	}
	return num;//regresa el n�mero de jugadores total
	// %s requerido para impresion de strings
	/*i=0;
	system("cls");
	for(i=0;i<=num;i++){
	printf("\n\nJugador %d: %s",i+1,nombres[i]);
	}*/

}
