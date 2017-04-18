#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char nombre[20], apellido[30], nomape[100];//por lo menos 52
    //int cantidadN=strlen(nombre);
    //int cantidadA=strlen(apellido);
    int i=0;

    printf("Ingrese su nombre:\n\n ", nombre);
    gets(nombre);

    printf("Ingrese su apellido:\n\n ", apellido);
    gets(apellido);

    /*    while(i==0)
        {
            putchar(toupper(nombre[i]));

        }
    */

    strcat(apellido, ", ");
    // NO ES NECESARIO HACERLO SEPARADO strcat(apellido, " ");
    strcpy(nomape, apellido);
    strcat(nomape, nombre);
//SACADO DE LO QUE DIJO EL PROFE

    //strlwr(nomape);
    nomape[0]=toupper(nomape[0]);//en el indice 0 lo paso a mayuscula sabiendo que me va a cambiar el de la primera cadena

    for(i=0;i<100;i++)//va a iterar cuantas veces sea el tamaño del array
    {
        if(nomape[i]==' ')//cuando sea el espacio
        {
            nomape[i+1]=toupper(nomape[i+1]);//el espacio +1 va a ser la primera letra de la seg cadena y la pone en mayus
        }
    }

    printf("Su nombre y apellido es:\n\n%s ", nomape);
    return 0;
}
