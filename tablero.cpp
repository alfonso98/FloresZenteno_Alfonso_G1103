#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "fortunas.cpp"


//arreglo que contiene los valores de compra y renta de cada casilla en el tablero.
int casillas[32][4]={{1,0,0,7},{2,600,20,0},{3,600,40,0},{4,0,0,81},{5,2000,250,0},{6,1000,60,0},{7,0,0,9},
{8,1200,80,0},{9,0,0,101},{10,1400,100,0},{11,1500,4,0},{12,1600,120,0},{13,2000,250,0},{14,1800,140,0},{15,2000,160,0},
{16,0,0,9},{17,0,0,102},{18,2200,180,0},{19,0,0,9},{20,2400,200,0},{21,2000,250,0},{22,2600,220,0},{23,2800,240,0},{24,1500,4,0},
{25,0,0,11},{26,0,0,9},{27,3000,260,0},{28,3200,280,0},{29,2000,250,0},{30,3500,450,0},{31,0,0,82},{32,4000,500,0}};

//arreglo con los nombres de casillas
char nomcas[32][50]={"Salida","Radio Izquierdista","Pedagogía","Impuesto","Corredor de la comida","Puesto de Souvenirs",
"Fortuna","Derecho","Edificio de Jurídico","Edifico de Posgrados","Servicio: COESI","SUAyED","Café 8","Auditorio Javier Barros Sierra",
"Centro de Enseñanza de Idiomas","Fortuna","Canchas","Sor Juana","Fortuna","Biblioteca","La cafeta","Diseño","Ingeniería",
"Servicio: CEDETEC","VETE A JURÍDICO","Fortuna","Unidad de Investigación Multidisciplinaria","Actuaria","El CUAIS",
"Matemáticas Aplicadas y Computación","Impuesto","Alma Mater"};

int especiales(int,int,int);

int board(int x, int d){//x es el número de jugadores, d es el número de turnos que habrá
	register int k,u,v;
	int dados, pos, resp, owner;
	for(k=1;k<=d;k++){
		for(u=1;u<=x;u++){//ciclo de acciones por jugador
			system("cls");
			fflush(stdin);
			printf("Turno %d",k);
			printf("\nJugador: %s",nombres[u]);//u es la variable con el número de jugador en turno
			printf("\nDinero: $%d",jugadores[u][0]);
			printf("\nPropiedades: \n\t");
			for(v=0;v<=31;v++){//Buscador de propiedades
				if(casillas[v][3]==u){
					printf("-%s \n\t",nomcas[v]);
				}
			}
			if(jugadores[u][2]==1){//evalua si el jugador esta en la carcel o
				printf("\n\n%s está en la carcel!!",nombres[u]);
				jugadores[u][2]=0;
				continue;//probar si se va al siguiente jugador
			}
			printf("\nIngrese el valor de los dados: ");
			scanf("%d",&dados);
			pos=jugadores[u][1];//posición del jugador
			pos+=dados;//posición más el valor de los dados
			if(pos>31){// saber si ha llegado al final del tablero
			pos-=32;//le quitamos el valor de una vuelta para que se reinicie en el tablero.
			if(pos!=0){ printf("\nHas dado una vuelta completa, ganas $2000 !!");//si se encuentra en otra diferente de salida recibe 2000
			jugadores[u][0]+=2000;}
			jugadores[u][1]=pos;
			}
			else{
			jugadores[u][1]=pos;
			}
			printf("\nHa caido en %s", nomcas[pos]);
			if(casillas[pos][3]== 0){//comprobar si la casilla en la que se encuentra el jugador tiene dueño
				printf("\nEsta propiedad no tiene dueño, deseas comprarla por $%d \n1-si 2-no? ",casillas[pos][1]);
				scanf("%d",&resp);
				switch(resp){//Estructura para realizar compra de propiedad
					case 1: casillas[pos][3]=u; jugadores[u][0]-=casillas[pos][1];
						printf("\n\nHas comprado %s !!",nomcas[pos]); break;
					case 2: printf("\n\nContinuemos jugando."); break;
					default: printf("\n\nUps, opción inválida, sigamos jugando."); break;
				}
			}else{//Acciones a realizar si la casilla tiene dueño o es especial.
			
				if(casillas[pos][3]==u){//opción de que la propiedad sea del mismo jugador
					printf("\nEsta propiedad es tuya.");
					break;
				}
				if(pos==4||pos==12||pos==20||pos==28||pos==10||pos==23){
					especiales(u,pos,dados);//casos especiales de cafeterias y servicios
					fflush(stdin);
					getch();
					break;
				}
				switch(casillas[pos][3]){//propiedades de tipo especial
					case 7: printf("\n\nHas dado una vuelta completa, ganas $2000 !!"); jugadores[u][0]+=2000; break;//cae en salida
					case 81: printf("\n\nPago de reinscripción, pierdes $2000."); jugadores[u][0]-=2000; break;//cae en impuestos 1	
					case 82: printf("\n\nPago de mensualidad del gym, pierdes $1000."); jugadores[u][0]-=1000; break;//cae en impuestos 2
					case 9: fortune(dados,x,u); break;//ingreso de función con fortunas
					case 101: printf("\n\nEstas sólo de visita."); break;
					case 102: printf("\n\nParada libre."); break;
					case 11: printf("\n\nTe regresas al edificio de jurídico y pierdes un turno."); jugadores[u][1]=8; jugadores[u][2]=1; jugadores[u][0]-=150; break;//cae en carcel
					default: owner=casillas[pos][3]; printf("\n\nLa propiedad le pertenece a %s, pierdes $%d de renta",nombres[owner],casillas[pos][2]);
					 jugadores[owner][0]+=casillas[pos][2]; jugadores[u][0]-=casillas[pos][2]; break;//la propiedad tiene dueño y se hace el pago de renta
				}
			}
			getch();
		}
	}
	return 0;
}


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


/*
int movimiento(int a,int b){//a-valor de dados, b-es el número de jugador
	int pos;
	pos=jugadores[u][1];//posición del jugador
	pos+=dados;
	if(pos>31){//sumamos el valor de su posición em el tablero mas elvalor de los dados para saber si ha llegado al finnal del tablero
	pos-=32;//le quitamos el valor de una vuelta para que se reinicie en el tablero.
	jugadores[u][1]=pos;
	}
	else{
		jugadores[u][1]=pos;
	}
	printf("\nHa caido en %s", nomcas[pos]);
	return pos;
}*/
