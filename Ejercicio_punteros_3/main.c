#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* x;
    x=(int*)malloc(5*sizeof(int)); //para tener 5 elementos en memoria del tipo int
    //malloc solo le paso los bytes que necesito en memoria
    if(x==NULL) //para que me lo tome en c es con mayuscula, en csharp en minuscula
    {
        printf("No se puede asignar memoria");
        exit(1);
    }
     int i;
    for(i=0;i<5;i++)
    {
        printf("Ingrese numero: ");
        fflush(stdin);
        scanf("%d", (x+i));//es el puntero mas 1 que seria 4 bytes, 2 8 bytes, etc etc
    }
/*
    for(i=0;i<5;i++)
    {
        printf("\n%d", *(x+i)); //le muestro el contenido de la variable
    }
*/
    int* aux;
    aux=(int)realloc(x,sizeof(int)*10); //le asigno a un auxiliar todos los elementos de x y pido 5 bytes mas
    if(aux!=NULL)//si el realloc me devolvio una dire distinta de null, ahi lo igualo a x
    {
        x=aux;
    }
    for(i=5;i<10;i++)
    {
        printf("Ingrese numero: ");//pido la continuacion de lo que agrande
        fflush(stdin);
        scanf("%d", (x+i));
    }

    for(i=0;i<10;i++)//imprimo de una todos los 10 de x
    {
        printf("\n%d", *(x+i)); //le muestro el contenido de la variable
    }

    int* y;
    y=(int*)calloc(10,sizeof(int));
    for(i=0;i<10;i++)//imprimo de una todos los 10 de x
    {
        printf("\n%d", *(y+i)); //le muestro el contenido de la variable
    }
    return 0;
}
