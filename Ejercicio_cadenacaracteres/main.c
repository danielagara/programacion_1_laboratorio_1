#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nombre[20];

    printf("Escribe tu nombre: ");
    //scanf("%s", nombre);//sin & porque estoy usando todo el array, no una direccion de memoria de un elemento solo
    gets(nombre); //se usa para que me tome hasta cuando lo paso con un espacio ej juan carlos, con el scan solo me toma juan
    printf("\nUsted se llama:%s", nombre);
    return 0;
}
