#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>


int fortune(int dice, int x, int u){//pedir valor dados y núm jugadores.
	int n, m;//variable de número aleatorio
	srand(time(NULL));
	n=rand()%10;
	//n+=dice;
	switch(n){
		case 0: jugadores[u][0]-=100; printf("\n\nVite te reprueba, paga el extra de cálculo, pierdes $100."); break;
		case 1: jugadores[u][0]+=2000; jugadores[u][1]=0; printf("\n\nAdelante hasta 'SALIDA'! cobra $2000."); break;
		case 2: jugadores[u][0]-=150; jugadores[u][1]=8; jugadores[u][2]=1;
		printf("\n\nTe cachan copiando en el examen final. Vete a Jurídico sin pasar por la SALIDA.\nPierdes $150."); break;
		case 3: printf("\n\nTe han elegido para sacar copias. Recibe $10 de los demás jugadores."); 
				for(m=1;m<=x;m++){
					jugadores[m][0]-=10;
				}
				jugadores[u][0]+=(10*x); break;
		case 4: jugadores[u][0]-=200; printf("\n\nTrámite de constancia de estudios, pierdes $200."); break;
		case 5: jugadores[u][0]+=300; printf("\n\nEncuntras cabello en tu comida de la cafetería, recibes $300 para no decirle a nadie."); break;
		case 6: jugadores[u][0]+=700; printf("\n\nRecibes beca de Manutención, cobra $700."); break;
		case 7: jugadores[u][0]-=250; printf("\n\nPierdes un libro de la Biblioteca, paga $250."); break;
		case 8: jugadores[u][0]-=50; printf("\n\nSacas copias del Haaser, paga $50."); break;
		case 9: jugadores[u][0]-=300; printf("\n\nPago del curso de Inglés, pierdes $300."); break;
		case 10: jugadores[u][0]+=200; printf("\n\nGracias por no dejar la carrera, recibe $200."); break;
	}
	getch();
	return 0;
}
/*
int especiales(int user, int position,int dice){//me mandan el número de jugador en turno,su posición y el valor e dados
	int type, cafe[4][2]={{4,0},{12,0},{20,0},{28,0}};
	int cont=0, i;
	//verificar los dueños de las cafeterias
	cafe[0][1]=casillas[4][3];
	cafe[1][1]=casillas[12][3];
	cafe[2][1]=casillas[20][3];
	cafe[3][1]=casillas[28][3];
	switch(position){
		case 4: 
			for(i=0;i<=3;i++){
				if(cafe[i][1]==casillas[position][3])
					cont+=1;
			}
			jugadores[user][0]-=250*cont;
			type=casillas[4][3];
			jugadores[type][0]+=250*cont;
			printf("\n\nLa propiedad le pertenece a %s, pierdes $%d de renta porque posee %d cafeterias",nombres[type],casillas[position][2]*cont,cont);
		break;
		
		case 12: 
			for(i=0;i<=3;i++){
				if(cafe[i][1]==casillas[position][3])
					cont+=1;
			}
			jugadores[user][0]-=250*cont;
			type=casillas[12][3];
			jugadores[type][0]+=250*cont;
			printf("\n\nLa propiedad le pertenece a %s, pierdes $%d de renta porque posee %d cafeterias",nombres[type],casillas[position][2]*cont,cont);
		break;
		
		case 20: 
			for(i=0;i<=3;i++){
				if(cafe[i][1]==casillas[position][3])
					cont+=1;
			}
			jugadores[user][0]-=250*cont;
			type=casillas[20][3];
			jugadores[type][0]+=250*cont;
			printf("\n\nLa propiedad le pertenece a %s, pierdes $%d de renta porque posee %d cafeterias",nombres[type],casillas[position][2]*cont,cont);
		break;
	
		case 28: 
			for(i=0;i<=3;i++){
				if(cafe[i][1]==casillas[position][3])
					cont+=1;
			}
			jugadores[user][0]-=250*cont;
			type=casillas[28][3];
			jugadores[type][0]+=250*cont;
			printf("\n\nLa propiedad le pertenece a %s, pierdes $%d de renta porque posee %d cafeterias",nombres[type],casillas[position][2]*cont,cont);			
		break;
		
		case 10:
			if(casillas[position][3]==casillas[23][3]){
				jugadores[user][0]-=10*dice;
				type=casillas[10][3];
				jugadores[type][0]+=10*dice;
				printf("\n\nLa propiedad le pertenece a %s, pierdes $%d de renta porque posee ambos servicios.",nombres[type],dice*10);
			}else{
				jugadores[user][0]-=4*dice;
				type=casillas[10][3];
				jugadores[type][0]+=4*dice;
				printf("\n\nLa propiedad le pertenece a %s, pierdes $%d de renta.",nombres[type],dice*4);
			}
		break;
		
		case 23:
			if(casillas[position][3]==casillas[10][3]){
				jugadores[user][0]-=10*dice;
				type=casillas[23][3];
				jugadores[type][0]+=10*dice;
				printf("\n\nLa propiedad le pertenece a %s, pierdes $%d de renta porque posee ambos servicios.",nombres[type],dice*10);
			}else{
				jugadores[user][0]-=4*dice;
				type=casillas[23][3];
				jugadores[type][0]+=4*dice;
				printf("\n\nLa propiedad le pertenece a %s, pierdes $%d de renta.",nombres[type],dice*4);
			}
		break;
	}
	
	return 0;
}

*/

