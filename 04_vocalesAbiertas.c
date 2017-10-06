/* 4)

Escriba un codigo que tome una letra (mayuscula o minuscula) y le indique si 
es una vocal, el tal caso que escriba en pantalla si 
es vocal abierta o cerrada. Implemente 
una switch con cinco casos y un if-else para 
escribir en pantalla el tipo de vocal. */

#include <stdio.h>
int main(){
	char vocal;
	printf("Dame un caracter cualquiera: ");
	scanf("%c",&vocal);
	
	switch(vocal){
		case 'a': printf("\nEs una vocal "); break;
		case 'e': printf("\nEs una vocal "); break;
		case 'i': printf("\nEs una vocal "); break;
		case 'o': printf("\nEs una vocal "); break;
		case 'u': printf("\nEs una vocal "); break;
		default: printf("\nNo es una vocal"); break;
	}
	
	if(vocal=='i'||vocal=='u'){
		printf("de tipo cerrada.");	
	}else{
		if(vocal=='a'||vocal=='e'||vocal=='o'){
			printf("de tipo abierta.");			
		}else{
			printf(".");
		}
	}
//Se usa primero un switch para determinar si se trata de una vocal o no.
//Después se compara la vocal para decir si es de tipo abierta o cerrada.
/*
	En mi opinion de podria solucionar sólo con un switch de la siguiente forma:
		
	switch(vocal){
		case 'a': printf("\nEs una vocal de tipo abierta."); break;
		case 'e': printf("\nEs una vocal de tipo abierta."); break;
		case 'i': printf("\nEs una vocal de tipo cerrada."); break;
		case 'o': printf("\nEs una vocal de tipo abierta."); break;
		case 'u': printf("\nEs una vocal de tipo cerrada."); break;
		default: printf("\nNo es una vocal."); break;
	}	
		
*/
	return 0;
}
