#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void altaDeMovie(eMovie* pelicula)
{
    int i, j;
    int repetido=0;
    pelicula->estado=1;

    printf("Ingrese el titulo de la pelicula\n ");
    fflush(stdin);
    gets(pelicula->titulo);
    printf("Ingrese el genero de la pelicula:\n ");
    fflush(stdin);
    gets(pelicula->genero);
    printf("Ingrese la duracion:\n ");
    fflush(stdin);
    scanf("%d", &pelicula->duracion);
    printf("Ingrese la descripcion de la pelicula:\n ");
    fflush(stdin);
    gets(pelicula->descripcion);
    printf("Ingrese el puntaje:\n ");
    fflush(stdin);
    scanf("%d", &pelicula->puntaje);
    printf("Ingrese el link de la imagen de portada de la pelicula:\n ");
    fflush(stdin);
    gets(pelicula->linkImagen);
}


void generarPagina(eMovie lista[], char nombre[], int contadorPeliculas)
{
    for(i=0;i<contadorPeliculas;i++)
    {
        if(vectorPelicula[i].estado==1)
        {

        }
    }
}
