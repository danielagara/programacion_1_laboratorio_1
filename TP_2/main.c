#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "string.h"
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
    int contadorMenores=0, contadorEntre=0, contadorMayores=0;
    int men, ent, may;
    int okI;
    char okC;
    char columnaMenores[20][3], columnaEntre[20][3], columnaMayores[20][3];
    int auxDniBusqueda;
    char flagBusqueda='n';
    int longMenores, longEntre, longMayores;


    for(i=0;i<S;i++)
    {
        personas[i].estado=-1;
        personas[i].alta='n';

    }

    while(seguir=='s')
    {
        printf("\n\n1- Agregar persona\n"); //OK FALTA VERIFICACION CARACTERES P/NOMBRE
        printf("2- Borrar persona\n");//OK
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
                        for(j=contador+1;j<S;j++)
                        {
                            do
                            {
                                printf("Ingrese dni: \n\n");
                                fflush(stdin);
                                okI=scanf("%d", &personas[j].dni);
                            }while(!okI);

                            if(personas[contador].dni!=personas[j].dni)
                            {
                                printf("Ingrese el nombre: \n\n");
                                fflush(stdin);
                                gets(personas[j].nombre);
                                personas[j].nombre[0]= toupper(personas[j].nombre[0]);

                                do
                                {
                                    printf("Ingrese la edad: \n\n");
                                    fflush(stdin);
                                    okI=scanf("%d", &personas[j].edad);
                                } while(!okI);
                                while(personas[j].edad<=0 || personas[j].edad>=100)
                                {
                                    printf("ERROR, Ingrese la edad: \n\n");
                                    fflush(stdin);
                                    scanf("%d", &personas[j].edad);
                                }
                                if(personas[j].edad<18)
                                {
                                    contadorMenores++;
                                }
                                else
                                {
                                    if(personas[j].edad>18 && personas[j].edad<36)
                                    {
                                        contadorEntre++;
                                    }
                                    if(personas[j].edad>35)
                                    {
                                        contadorMayores++;
                                    }
                                }

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
                for(k=1;k<contador;k++)
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
                printf("%d\t%d\t%d\n\n", contadorMenores, contadorEntre, contadorMayores);
/*
                for(men=0;men<contadorMenores;men++)
                {
                    columnaMenores[men]='*';
                    printf("%c\n", columnaMenores[men]);

                }

                for(ent=0;ent<contadorEntre;ent++)
                {
                    columnaEntre[ent]='*';
                    printf("\t%c\n", columnaEntre[ent]);
                }
                for(may=0;may<contadorMayores;may++)
                {
                    columnaMayores[may]='*';
                    printf("\t\t%c\n", columnaMayores[may]);
                }

*/
                //p columnaMenores[20][3]
                for(i=0;i<20;i++)
                {
                    //HACER CON LO DE MATRIZZZZZ DEFINIDAS YA ARRIBA
                }

                //p columnaEntre[20][3]
                //p columnaMayores[20][3]
                printf("<18\t19-35\t>35\n");

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

        for(j=1;j<=cant;j++)
        {
            printf("\n---------------");
            printf("\n\nNOMBRE:\n\n%s ", personas[j].nombre);
            printf("\n\nEDAD:\n\n%d ", personas[j].edad);
            printf("\n\nDNI:\n\n%d ", personas[j].dni);
        }


}
