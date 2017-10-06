/*En este archivo encontrarán algunas tareas que se deben realizar en clase.

*****************************************************************************
1)
Una empresa que fabrica vehículos desea calcular las 
necesidades de combustible (cantidad de combustible necesario 
para llenar los depósitos de todos sus vehículos) para lo cual 
nos han facilitado este esquema de cálculo (ver abajo). Se desea crear un 
programa para que puedan realizar el cálculo de forma automatizada.

 1.  Inicio

2.  [Definición de vehículos]
3.  Motos = 32
4.  Todoterrenos = 11
5.  Autos tipo sedán = 21
6.  Autos deportivos = 4
7.  [Fin de definición de vehículos]

8.  [Definición de capacidad de depósitos]
9.   Capacitadad de las motos = 40 l.
10.  Capacidad de los todoterreno = 65 l.
11.  Capacidad de los tipo sedan = 39 l.
12.  Capacidad de los deportivos = 45 l.
13.  [Fin de definición de capacidad de depósitos]

...
...
n.   Fin


Debes terminar Tu tarea consiste en obtener la necesidad de combustible total.
Recuerda usar las herramientas compartidas en clase. Interactua con la terminal.
*/
#include <stdio.h>
#include <locale.h>
int main(){
	setlocale(LC_ALL,"");
	
	int resp, m, td, as, dp;
	
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	printf("\n\tPrograma de cálculo de combustible.");
	
	do{
		printf("\n\nDeme la cantidad de los vehículos con los que cuenta.");
		printf("\n>Motos: ");
		scanf("%d",&m);
		printf("\n>Todoterrenos: ");
		scanf("%d",&td);
		printf("\n>Autos Sedán: ");
		scanf("%d",&as);
		printf("\n>Deportivos: ");
		scanf("%d",&dp);
		
		printf("\n\n+++ +++ +++ +++ +++ +++ +++ +++ +++ +++ +++");
		printf("\n\t\t-RESULTADOS-");
		printf("\n>Combustible necesario para motos: %f", m*40.1);
		printf("\n>Combustible necesario para todoterrenos: %d", td*65);
		printf("\n>Combustible necesario para autos sedán: %d", as*39);
		printf("\n>Combustible necesario para deportivas: %d", dp*45);
		printf("\n\n\n>Total de combustible necesario: %f", m*40.1 + td*65 + as*39 + dp*45);
		
		printf("\nDesea calcular valores? 1-sí  2-no : ");
		scanf("%d",&resp);
	}
	while(resp==1);
	return 0;
}
