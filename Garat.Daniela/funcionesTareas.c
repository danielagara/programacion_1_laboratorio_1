#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "funcionesTareas.h"

/** \brief Crea una tarea en el Array List (tipo estructura tarea)
 *
 * \param  descripcion Descripcion de la tarea
 * \param  prioridad Prioridad de la tarea
 * \param  tiempoDemora Tiempo de demora de la tarea
 * \return pTarea puntero a tarea
 *
 */

Tarea* newTarea(char descripcion[50], int prioridad, int tiempoDemora)
{
    Tarea* returnAux = NULL;
    Tarea* pTarea= malloc(sizeof(Tarea));

    if(pTarea != NULL)
    {
        strcpy(pTarea->descripcion,descripcion);
        pTarea->prioridad=prioridad;
        pTarea->tiempoDemora = tiempoDemora;
        returnAux = pTarea;
    }

    return returnAux;

}

/** \brief Carga del archivo las tareas generales al array list
 *
 * \param tareasGenerales ArrayList
 * \return void
 *
 */


void cargarTareasGenerales(ArrayList* tareasGenerales)
{
    ArrayList* auxArray = al_newArrayList();
    Tarea* auxTarea;
    int i;

    FILE* archivoTareasGenerales;
    char descripcion[50], prioridad[10], timpoDemora[10];
    Tarea* pTarea;

    archivoTareasGenerales = fopen("tar.csv", "r");

    if(archivoTareasGenerales != NULL)
    {
        while(!feof(archivoTareasGenerales))
        {
            fscanf(archivoTareasGenerales, "%[^,],%[^,],%[^\n]\n", descripcion, prioridad, timpoDemora);
            pTarea = newTarea(descripcion,atoi(prioridad), atoi(timpoDemora));
            tareasGenerales->add(tareasGenerales,pTarea);
        }
    }
}


/** \brief Carga del archivo al array list tareas de prioridad alta
 *
 * \param tareasPAlta ArrayList
 * \return void
 *
 */

void cargartareasPAlta(ArrayList* tareasPAlta)
{
    ArrayList* auxArray = al_newArrayList();
    Tarea* auxTarea;
    int i;

    FILE* archivotareasPAlta;
    char descripcion[50], prioridad[10], timpoDemora[10];
    Tarea* pTarea;

    archivotareasPAlta = fopen("tar.csv", "r");

    if(archivotareasPAlta != NULL)
    {
        while(!feof(archivotareasPAlta))
        {
            fscanf(archivotareasPAlta, "%[^,],%[^,],%[^\n]\n", descripcion, prioridad, timpoDemora);
            pTarea = newTarea(descripcion,atoi(prioridad), atoi(timpoDemora));
			if(pTarea->prioridad==1)
			{
				tareasPAlta->add(tareasPAlta,pTarea);
			}

        }
    }
}


/** \brief Carga del archivo al array list tareas de prioridad baja
 *
 * \param tareasPBaja Array List
 * \return void
 *
 */

void cargartareasPBaja(ArrayList* tareasPBaja)
{
    ArrayList* auxArray = al_newArrayList();
    Tarea* auxTarea;
    int i;

    FILE* archivotareasPBaja;
    char descripcion[50], prioridad[10], timpoDemora[10];
    Tarea* pTarea;

    archivotareasPBaja = fopen("tar.csv", "r");

    if(archivotareasPBaja != NULL)
    {
        while(!feof(archivotareasPBaja))
        {
            fscanf(archivotareasPBaja, "%[^,],%[^,],%[^\n]\n", descripcion, prioridad, timpoDemora);
            pTarea = newTarea(descripcion,atoi(prioridad), atoi(timpoDemora));
			if(pTarea->prioridad==0)
			{
				tareasPBaja->add(tareasPBaja,pTarea);
			}

        }
    }
}

/** \brief Compara las tareas por tiempo de demora
 *
 * \param pTareaA tarea A
 * \param pTareaB tarea B
 * \return 1 si ptareaA mayor a pTareaB; -1 si pTareaB mayor a pTareaA; 0 si OK
 *
 */

int comparaTareas(void* pTareaA,void* pTareaB)
{

    if(((Tarea*)pTareaA)->tiempoDemora>((Tarea*)pTareaB)->tiempoDemora)
    {
        return 1;
    }
    if(((Tarea*)pTareaA)->tiempoDemora<((Tarea*)pTareaB)->tiempoDemora)
    {
        return -1;
    }
    return 0;
}

/** \brief Resuelve las tareas prioridad Alta ordenadas por menor tiempo
 *
 * \param tareasPAlta ArrayList
 * \return void
 *
 */

 void resuelveEnOrdenAltas(ArrayList* tareasPAlta)
 {
    int i;
    Tarea* proximaTareaAlta;
    tareasPAlta->sort(tareasPAlta,comparaTareas,1);
    if(tareasPAlta->isEmpty(tareasPAlta)==0)
    {
        printf("\nALTATATAT\n\n");
        while(tareasPAlta->len(tareasPAlta)>0)
        {
            proximaTareaAlta=(Tarea*)tareasPAlta->pop(tareasPAlta,0);
            printf("SU DESCRIPCION ES : %s\n", proximaTareaAlta->descripcion);
            printf("SU PRIORIDAD ES : %d\n", proximaTareaAlta->prioridad);
            printf("SU TIEMPO DE DEMORA ES : %d\n\n", proximaTareaAlta->tiempoDemora);
        }
    }
    else if(tareasPAlta->isEmpty(tareasPAlta)==1)
    {
        printf("NO HAY QUEDAN TAREAS DE PRIORIDAD ALTA POR REALIZAR :) \n");
    }
 }


 /** \brief Resuelve las tareas prioridad Baja ordenadas por menor tiempo
  *
  * \param tareasPBaja
  * \return void
  *
  */

void resuelveEnOrdenBajas(ArrayList* tareasPBaja)
{
    int i;
    Tarea* proximaTareaBaja;
    tareasPBaja->sort(tareasPBaja,comparaTareas,1);
    if(tareasPBaja->isEmpty(tareasPBaja)==0)
    {
        printf("\nBAJAJAJA\n\n");
        while(tareasPBaja->len(tareasPBaja)>0)
        {
            proximaTareaBaja=(Tarea*)tareasPBaja->pop(tareasPBaja,0);
            printf("SU DESCRIPCION ES : %s\n", proximaTareaBaja->descripcion);
            printf("SU PRIORIDAD ES : %d\n", proximaTareaBaja->prioridad);
            printf("SU TIEMPO DE DEMORA ES : %d\n", proximaTareaBaja->tiempoDemora);
        }
    }
    else if(tareasPBaja->isEmpty(tareasPBaja)==1)
    {
        printf("NO HAY QUEDAN TAREAS DE PRIORIDAD BAJA POR REALIZAR :) \n");
    }
}
