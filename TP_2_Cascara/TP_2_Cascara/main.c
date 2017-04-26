#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"
#define S 20

typedef struct
{
    char nombre[20];
    int edad;
    int dni;
    int estado;
    char alta;
} eDatosPersonales;


void mostrarPersona(eDatosPersonales personas[], int cant);

int main()
{
    char seguir='s';
    int opcion=0;
    eDatosPersonales personas[S];
    int i, j, u, k;
    char respuesta;
    int contador=0;
    int auxDniBusqueda;
    char flagBusqueda='n';


    for(i=0;i<S;i++)
    {
        personas[i].estado=-1;
        personas[i].alta='n';

    }

    while(seguir=='s')
    {
        printf("1- Agregar persona\n"); //OK
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");//OK
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                while(contador<20)
                {
                    respuesta='s';
                    while(respuesta=='s')
                    {
                    if(personas[contador].estado!=-1)
                    {
                        printf("NO HAY LUGAR");
                        break;
                    }
                    else
                    {
                        personas[contador].estado=0;
                        personas[contador].alta='s';
                        for(j=contador;j<S;j++)
                        {
                            printf("Ingrese dni: \n\n");
                            fflush(stdin);
                            scanf("%d", &personas[j].dni);
                            if(personas[contador].dni!=personas[j].dni)
                            {
                                printf("Ingrese el nombre: \n\n");
                                fflush(stdin);
                                gets(personas[j].nombre);
                                personas[j].nombre[0]= toupper(personas[j].nombre[0]);//Pone la primera letra en mayusculas

                                printf("Ingrese la edad: \n\n");
                                fflush(stdin);
                                scanf("%d", &personas[j].edad);
                                break;
                            }
                            else if(personas[contador].dni==personas[j].dni)
                            {
                                printf("EL DNI YA FUE INGRESADO");
                                break;
                            }
                        }

                    }
                    printf("Quiere seguir ingresando? s o n:  ");
                    fflush(stdin);
                    scanf("%c", &respuesta);
                    if(respuesta=='s')
                    {
                        contador++;
                    }
                    }
                        contador++;
                        break;
                }
                break;
            case 2:
                printf("Ingrese el numero de DNI a borrar: ");
                fflush(stdin);
                scanf("%d", &auxDniBusqueda);
                for(k=0;k<contador;k++)
                {
                    if(personas[k].dni==auxDniBusqueda)
                    {
                        personas[k].alta='n';
                        flagBusqueda='s';
                        printf("Se borro a:%s ", personas[k].nombre);
                        break;
                    }
                    else if(flagBusqueda=='n')
                    {
                        printf("No se encontro el DNI");
                        break;
                    }
                }
                break;
            case 3:
                mostrarPersona(personas, contador);
                break;
            case 4:
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }
    return 0;
}

void mostrarPersona(eDatosPersonales personas[], int cant)
{
    int j;

        for(j=0;j<=cant;j++)
        {
            printf("\n---------------");
            printf("\n\nNOMBRE:\n\n%s ", personas[j].nombre);
            printf("\n\nEDAD:\n\n%d ", personas[j].edad);
            printf("\n\nDNI:\n\n%d ", personas[j].dni);
        }


}

