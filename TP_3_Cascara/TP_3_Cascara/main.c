#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

typedef struct{
    char titulo[50];
    char genero[20];
    int duracion;
    char descripcion[500];
    int puntaje;
    char linkImagen[200];
    int estado;
}eMovie;

int main()
{
    char seguir='s';
    int opcion=0;
    int totalVectorPeliculas=1;
    int contadorPeliculas=0;
    int i;

    eMovie unaPelicula;
    FILE* archivoPeliculas;
    archivoPeliculas=fopen("Peliculas.dat", "rb");

    eMovie* vectorPelicula=(eMovie*)malloc(sizeof(eMovie)*totalVectorPeliculas);
    eMovie* AUXvectorPelicula;
    if(archivoPeliculas!=NULL)
    {
        //primer parametro: donde van las peliculas, el sizeof de la estructura, cantidad de elementos de ese tamaño, nombre archivo
        while(fread((void*)(vectorPelicula+contadorPeliculas),sizeof(eMovie), 1, archivoPeliculas)==1)
        {
            contadorPeliculas++;
            totalVectorPeliculas++;

            AUXvectorPelicula=(eMovie*)realloc(vectorPelicula,sizeof(eMovie)*totalVectorPeliculas);
            if(AUXvectorPelicula!=NULL)
            {
                vectorPelicula=AUXvectorPelicula;
            }
        }
        fclose(archivoPeliculas);
    }

    /*for(i=0;i<contadorPeliculas;i++)
    {
        printf("%s\n", vectorPelicula[i].titulo);

    }*/


    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("4- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1://ALTA DE PELICULA
                altaDeMovie(&unaPelicula);//Agrego una pelicula
                AUXvectorPelicula=(eMovie*)realloc(vectorPelicula,sizeof(eMovie)*totalVectorPeliculas);
                if(AUXvectorPelicula!=NULL)
                {
                    vectorPelicula=AUXvectorPelicula;
                }
                vectorPelicula[contadorPeliculas]=unaPelicula;
                contadorPeliculas++;
                totalVectorPeliculas++;
                break;

            case 2://MODIFICACION DE PELICULA
                char AUXtituloPelicula[50];
                printf("Ingrese el titulo de la pelicula a modificar\n");
                fflush(stdin);
                gets(AUXtituloPelicula);
                for(i=0;i<contadorPeliculas;i++)
                {
                    if(stricmp(AUXtituloPelicula,vectorPelicula[i].titulo)==0)
                    {
                        printf("INGRESE NUEVOS DATOS\n\n");

                        printf("Ingrese el titulo de la pelicula\n ");
                        fflush(stdin);
                        gets(vectorPelicula[i].titulo);
                        printf("Ingrese el genero de la pelicula:\n ");
                        fflush(stdin);
                        gets(vectorPelicula[i].genero);
                        printf("Ingrese la duracion:\n ");
                        fflush(stdin);
                        scanf("%d", &vectorPelicula[i].duracion);
                        printf("Ingrese la descripcion de la pelicula:\n ");
                        fflush(stdin);
                        gets(vectorPelicula[i].descripcion);
                        printf("Ingrese el puntaje:\n ");
                        fflush(stdin);
                        scanf("%d", &vectorPelicula[i].puntaje);
                        printf("Ingrese el link de la imagen de portada de la pelicula:\n ");
                        fflush(stdin);
                        gets(vectorPelicula[i].linkImagen);
                        break;
                    }
                }
                break;

            case 3://BAJA DE PELICULA
                printf("Ingrese el titulo de la pelicula a dar de baja\n");
                fflush(stdin);
                gets(AUXtituloPelicula);
                for(i=0;i<contadorPeliculas;i++)
                {
                    if(stricmp(AUXtituloPelicula,vectorPelicula[i].titulo)==0)
                    {
                        vectorPelicula[i].estado=0;
                        break;
                    }
                }
               break;

            case 4://CREA PAG WEB
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
