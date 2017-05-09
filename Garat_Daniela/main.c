#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include "lib.c"
#include "strings.h"

int main()
{
    int i;
    int opcion;
    char seguir='s';
    eProgramador programador[50];
    eProyecto proyecto[1000];
    eProyectoProgramador proyectoPorProgramador[10000];
    eCategoria categoria[3];

    inicializarEstado(programador,50);
    definirCategorias(categoria,3);

    while(seguir!='n')
    {
        printf("\n1- Alta de programador\n");//OK
        printf("2- Modificar datos de programador\n");//OK
        printf("3- Baja de programador\n");//OK
        printf("4- Asignar programador a proyecto\n");//OK
        printf("5- Listado de programadores\n");//OK
        printf("6- Listado de proyectos\n");
        printf("7- Listado de proyectos de programador\n");
        printf("8- Poyecto demandante\n");
        printf("9- Salir\n");

        fflush(stdin);
        scanf("%d", &opcion);
        switch(opcion)
        {
            case 1://ALTA DE PROGRAMADOR
                altaDeprogramador(programador,50,categoria,3);
                break;

            case 2:
                modificarUsuario(programador,50);
                break;

            case 3:
                bajaDeProgramador(programador,50);
                break;

            case 4:
                asignarProgramadorAProyecto(programador,50,proyecto, 1000,proyectoPorProgramador,10000);
                break;

            case 5:
                mostrarProgramadores(programador,50, categoria,3, proyectoPorProgramador, 10000, proyecto, 1000);
                break;

            case 6:

                break;

            case 7:
                break;

			case 8:
				break;
            case 9:
                seguir='n';
                break;
        }
    }

    return 0;
}


