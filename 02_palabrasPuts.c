// 2)

// Descarga el siguiente archivo y observa su salida. Descrubre qu� sucede
// si cambias los n�meros que se encuentran entre los par�ntesis.

#include <stdio.h>

int main(){

char palabras[]="Carrera de Matematicas Aplicadas y Computacion";
char nombre[]="ALFONSO FLORES ZENTENO";
int x;

printf("%s \n %s\n", palabras, &palabras[5]);
puts(palabras);
puts(&nombre[8]);

//El programa guarda en un arreglo una serie de caracteres y le asigna a cada 
//caracter su propio espacio en memoria, al imprimir el arreglo cambiando el n�mero en los corchetes
//se comienza a imprimir desde el caracter gusrdado en el espacio de memoria especificado.


return 0;
}
