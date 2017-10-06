/*
Tarea_01: Para el archivo de números primos debes implementar para que el programa funcione en 
el dominio [1,10], [1,15] y [1,50]; después para todos los números pares e impares.

Con este programa se puede probar i un número cualquiera es primo o no. 
*/
#include <stdio.h>

int main()
{
int i,n, x=0;
            
printf("Introduzca un n%cmero cualquiera: ", 163);
    	
	scanf("%d",&i);
	
	/*El ciclo parte del numero a evaluar, termina en el 1 y desciende uno a uno y 
	se prueba si el numero a evaluar es divisible ente cualquier otro menor que él hasta
	llegar al 1.
	En caso de encontrar un número divisible entre el número a evaluar (módulo=0)
	se suma 1 a la variable n.
	
	*/
	for(x=i ;x>=1 ;x=x-1){
		if (i%x==0){
			n = n + 1;
		}
	}

	//Los números primos sólo tendran 2 casos en los que su módulo sea 0.
    if (n==2) {
       printf("\nEs primo.");
    }
    else
    {
       printf("\nNo es primo.");
    }
    
    return 0;
}
