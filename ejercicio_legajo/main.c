#include <stdio.h>
#include <stdlib.h>
#define A 10

int main()
{
    char seguir='s';
    int opcion=0;
    int i, vecLegajo[A], vecEdad[A], vecNota[A], legBusqueda, notaMax, contador=0, acumNotas=0;
    float promedio;
    char flagBusqueda='n';

    while(seguir=='s')
    {
        printf("1- Ingreso de todos los datos\n");
        printf("2- Buscar por legajo\n");
        printf("3- Maxima nota listando a todos los alumnos que tengan esa nota\n");
        printf("4- Calcular promedio de notas. Listando a todos los alumnos que superen el promedio.\n");
        printf("5- Listar todos\n");
        printf("6- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                for(i=0; i<A;i++) //para que vaya sumando hasta que llega a los 10 alumnos
                {
                    printf("1-Ingrese el numero de legajo\n");
                    scanf("%d", &vecLegajo[i]);
                    printf("1-Ingrese la edad\n");
                    scanf("%d", &vecEdad[i]);
                    printf("1-Ingrese la nota\n");
                    scanf("%d", &vecNota[i]);
                    acumNotas=(acumNotas+vecNota[i]);
                }
                break;

            case 2:
                printf("Ingrese el numero del legajo a buscar\t");
                scanf("%d", &legBusqueda);
                if(legBusqueda==vecLegajo[i])
                {
                    printf("%d\t%d\t%d\n", vecLegajo[i], vecEdad[i], vecNota[i]);
                    flagBusqueda='s';
                }
                else
                {
                    if(flagBusqueda=='n')
                    {
                        printf("No se encontro legajo");
                    }
                }
                break;

            case 3:
                for(i=0;i<A;i++)
                {
                    if(contador==0)
                    {
                        notaMax=vecNota[i];
                    }
                    else
                    {
                        if(vecNota[i]>notaMax)
                        {
                            notaMax=vecNota[i];
                        }
                    }

                    if(vecNota[i]==notaMax)
                    {
                        printf("%d\t%d\t%d\n", vecLegajo[i], vecEdad[i], vecNota[i]);
                    }
                }
                break;

            case 4:
                promedio=(acumNotas/A);
                for(i=0;i<A;i++)
                {
                    if(vecNota[i]>promedio)
                    {
                        printf("%d\t%d\t%d\n", vecLegajo[i], vecEdad[i], vecNota[i]);
                    }
                }
                break;
            case 5:
                for(i=0;i<A;i++)
                {
                    printf("%d\t%d\t%d\n", vecLegajo[i], vecEdad[i], vecNota[i]);
                }
                break;
            case 6:
                contador++;
                seguir = 'n';
                break;
        }

    }
    return 0;
}
