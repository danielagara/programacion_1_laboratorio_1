#include <stdio.h>
#include <stdlib.h>
#define A 10


//TERMINAR

typedef struct
{//estructura
    int vecLegajo[A];
    int vecEdad[A];
    int vecNota[A];
} eDatos;

void mostrarPersona (eDatos x);

int main()
{
    eDatos datosPersona;
    char seguir='s';
    int opcion=0;
    int i, u, j, legBusqueda, notaMax, contador=0, acumNotas=0;
    int disponibilidad=-1, estado=0;
    char respuesta;
    float promedio;
    char flagBusqueda='n';
    int contadorGeneral=0;

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
                respuesta='s';
                while(respuesta!='n')
                {
                    /*if(disponibilidad==-1)
                    {
                        printf("NO HAY LUGAR");
                    }
                    else
                    {*/

                for(j=0;j<A;j++)
                {
                    printf("1-Ingrese el numero de legajo\n");
                    scanf("%d", &datosPersona.vecLegajo[j]);
                    for(i=j+1;i<A;i++)
                    {
                        if(datosPersona.vecLegajo[j]!=datosPersona.vecLegajo[i])
                        {

                            printf("1-Ingrese la edad\n");
                            fflush(stdin);
                            scanf("%d", &datosPersona.vecEdad[i]);

                            printf("1-Ingrese la nota\n");
                            fflush(stdin);
                            scanf("%d", &datosPersona.vecNota[i]);
                            acumNotas=(acumNotas+datosPersona.vecNota[i]);
                            break;
                        }
                        else
                        {

                            printf("EL LEGAJO YA ESTA REGISTRADO");

                        }
                    }
                    break;
                }

                contadorGeneral++;
                printf("¿Quiere seguir ingresando datos? s o n", respuesta);
                fflush(stdin);
                scanf("%c", &respuesta);
                }
                break;

            case 2:

                printf("Ingrese el numero del legajo a buscar\t");
                scanf("%d", &legBusqueda);
                for(j=0;j<A;j++)
                {
                    if(legBusqueda==datosPersona.vecLegajo[j])
                    {
                        mostrarPersona(datosPersona);
                        flagBusqueda='s';
                    }
                    else
                    {
                        if(flagBusqueda=='n')
                        {
                            printf("No se encontro legajo");
                        }
                    }

                }
                break;

            case 3:
                for(i=0;i<A;i++)
                {
                    if(contador==0)
                    {
                        notaMax=datosPersona.vecNota[i];
                    }
                    else
                    {
                        if(datosPersona.vecNota[i]>notaMax)
                        {
                            notaMax=datosPersona.vecNota[i];
                        }
                    }

                    if(datosPersona.vecNota[i]==notaMax)
                    {
                        mostrarPersona(datosPersona);
                    }
                }
                break;

            case 4:
                promedio=(acumNotas/contadorGeneral);
                for(i=0;i<contadorGeneral;i++)
                {
                    if(datosPersona.vecNota[i]>promedio)
                    {
                        mostrarPersona(datosPersona);
                    }
                }
                break;

            case 5:
                for(i=0;i<contadorGeneral;i++)
                {
                    mostrarPersona(datosPersona);
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

void mostrarPersona (eDatos x)
{
    int i;
    for(i=0;i<A;i++)
    {
        printf("\n\nLEGAJO:\n\n%d ", x.vecLegajo[i]);
        printf("\n\nEDAD:\n\n%d ", x.vecEdad[i]);
        printf("\n\NOTA:\n\n%d ", x.vecNota[i]);
    }

}

