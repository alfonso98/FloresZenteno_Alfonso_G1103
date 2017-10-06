/*
2) 
Debes realizar un programa que te pida dos números al inicio, realice las cuatro operaciones 
aritméticas básicas y escriba en terminal si el resultado de cada una de las operaciones 
es mayor (o menor) que 100.
*/
#include <stdio.h>
#include <locale.h>

void comp(float x);

int main(){
	setlocale(LC_ALL,"");
	float num1, num2;
	
	printf("\t******Operaciones Básicas******");
	printf("\n\nDame un numero entero o decimal: ");
	scanf("%f",&num1);
	printf("\nDame otro numero entero o decimal: ");
	scanf("%f",&num2);
	
	printf("\n\tOperaciones básicas:");
	printf("\n\n>Suma: %0.2f + %0.2f = %0.2f ", num1,num2, num1+num2); 
	comp(num1+num2);
	printf("\n\n>Resta: %0.2f - %0.2f = %0.2f ", num1,num2,num1-num2);
	comp(num1-num2);
	printf("\n\n>Multiplicación: %0.2f x %0.2f = %0.2f ", num1,num2,num1*num2);
	comp(num1*num2);
	printf("\n\nDivisión: %0.2f / %0.2f = %0.2f ", num1,num2,num1/num2);
	comp(num1/num2);
	
}

void comp(float x){
	if(x>100){
		printf("El resultado es mayor que 100.");
	}else{
		if(x<100){
			printf("El resultado es menor que 100.");
		}else{
			printf("El resultado es igual a 100");
		}
	}
	return 0;
}
