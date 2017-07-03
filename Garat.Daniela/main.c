#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "funcionesTareas.h"

int main()
{
    ArrayList* tareasGenerales=al_newArrayList();
    ArrayList* tareasPAlta=al_newArrayList();
    ArrayList* tareasPBaja=al_newArrayList();


    Tarea* stTareasGenerales;
    Tarea* sttareasPAlta;
    Tarea* sttareasPBaja;

    char seguir='s';
    int opcion;

    while(seguir=='s')
    {
        system("cls");
        printf("1- CARGAR LISTA DE TAREAS\n");//TERMINADO
        printf("2- PARTICIONAR POR PRIORIDAD\n");
        printf("3- ORDENAR\n");
        printf("4- RESOLVER TAREAS\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1://GENERA LISTA DE TAREAS GENERALES
                cargarTareasGenerales(tareasGenerales);
                break;
            case 2://PARTICIONAR POR PRIORIDAD

                //PRIORIDAD ALTA
                cargartareasPAlta(tareasPAlta);

                //PRIORIDAD BAJA
                cargartareasPBaja(tareasPBaja);
                break;
            case 3://ORDENA LISTAS POR DEMORA DESC

                //PRIORIDAD ALTA
                tareasPAlta->sort(tareasPAlta,comparaTareas,0);

                //PRIORIDAD BAJA
                tareasPBaja->sort(tareasPBaja,comparaTareas,0);

                break;
            case 4:
                //RESOLVER TAREAS
                //ALTAS
                resuelveEnOrdenAltas(tareasPAlta);

                //BAJAS
                resuelveEnOrdenBajas(tareasPBaja);

                break;
            case 5:
                seguir='n';
                break;
        }
        system("pause");
    }
    return 0;
}
