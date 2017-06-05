#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

/*
void altaDeMovie(eMovie* pelicula)
{
    int i, j;

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


void generarPagina(eMovie* lista, char nombre[], int contadorPeliculas)
{
    for(i=0;i<contadorPeliculas;i++)
    {
        if(vectorPelicula[i].estado==1)
        {
            fprintf(archivoPWeb, "%s","			<div class='row'>\n\n\n");
            fprintf(archivoPWeb, "%s","			<article class='col-md-4 article-intro'>\n");
            fprintf(archivoPWeb, "%s","                <a href='#'>\n");
            fprintf(archivoPWeb, "%s","                    <img class='img-responsive img-rounded' src='");
            fprintf(archivoPWeb, "%s",lista[i].linkImagen);
            fprintf(archivoPWeb, "%s","' alt=''>\n");
            fprintf(archivoPWeb, "%s","                </a>\n");
            fprintf(archivoPWeb, "%s","                <h3>\n");
            fprintf(archivoPWeb, "%s","                    <a href='#'>");
            fprintf(archivoPWeb, "%s", lista[i].titulo);
            fprintf(archivoPWeb, "%s","</a>\n");
            fprintf(archivoPWeb, "%s","                </h3>\n");
            fprintf(archivoPWeb, "%s","				<ul>\n");
            fprintf(archivoPWeb, "%s","					<li>");
            fprintf(archivoPWeb, "%s","Género: %s", lista[i].genero);
            fprintf(archivoPWeb, "%s","</li>\n");
            fprintf(archivoPWeb, "%s","					<li>");
            fprintf(archivoPWeb, "%s","Puntaje: %s", lista[i].puntaje);
            fprintf(archivoPWeb, "%s","</li>\n");
            fprintf(archivoPWeb, "%s","					<li>");
            fprintf(archivoPWeb, "%s","Duracion: %s", lista[i].duracion);
            fprintf(archivoPWeb, "%s","</li>\n");
            fprintf(archivoPWeb, "%s","				</ul>\n");
            fprintf(archivoPWeb, "%s","                <p>%s", lista[i].descripcion);
            fprintf(archivoPWeb, "%s","</p>\n");
            fprintf(archivoPWeb, "%s","            </article>\n");
            fprintf(archivoPWeb, "%s","        </div>\n");
            fprintf(archivoPWeb, "%s","        <!-- /.row -->\n");
        }
    }
}*/
