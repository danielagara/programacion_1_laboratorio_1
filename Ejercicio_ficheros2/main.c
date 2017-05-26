#include <stdio.h>
#include <stdlib.h>
#include "strings.h"

int main()
{
    char cadena[55]={"Tengo sueño"};
    int cant;
    int escrito;

    FILE* f;
    f=fopen("prueba.txt", "w"); //(path,modo);
    if(f==NULL)
    {
        printf("No se puede crear fichero");
        exit(1);
    }
    cant=strlen(cadena);
    escrito=fwrite(cadena,sizeof(char),cant,f);
    if(escrito<cant)
    {
        printf("Problemas al escribir el fichero.");
    }
    fclose(f);

    return 0;
}
