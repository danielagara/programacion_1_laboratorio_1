#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "tramite.h"

Tramite* newTramite(int DNI, char tipoTramite,int atendido, int numTurno)
{
    Tramite* returnAux = NULL;
    Tramite* pTramite= malloc(sizeof(Tramite));

    if(pTramite != NULL)
    {
        pTramite->DNI = DNI;
        pTramite->tipoTramite=tipoTramite;
        pTramite->atendido = atendido;
        pTramite->numTurno=numTurno;
        returnAux = pTramite;
    }

    return returnAux;

}

/** \brief Compara DNI de tramites atendidos
 *
 * \param pTramiteA primero a comparar
 * \param pTramiteB segundo a comparar
 * \return 0 si termino, 1 si pTramiteA es > que pTramiteB, -1 si pTramiteA es < que pTramiteB
 *
 */


int comparaTramite(void* pTramiteA,void* pTramiteB)
{

    if(((Tramite*)pTramiteA)->DNI > ((Tramite*)pTramiteB)->DNI)
    {
        return 1;
    }
    if(((Tramite*)pTramiteA)->DNI < ((Tramite*)pTramiteB)->DNI)
    {
        return -1;
    }
    return 0;
}

/** \brief Escribir en archivo csv
 *
 * \param archivoTramites Archivo a guardar el al
 * \param lista array list
 * \return void
 *
 */

 void escribirEnArchivoElArray(FILE* archivoTramites,ArrayList* lista)
{
    Tramite* auxTramite;
    int i;

    for(i=0; i< lista->len(lista);i++)
    {
        auxTramite = (Tramite*)lista->get(lista,i);
        fprintf(archivoTramites,"%d,%c,%d,%d\n",auxTramite->DNI,auxTramite->tipoTramite,auxTramite->atendido,auxTramite->numTurno);
    }

}


/** \brief Guarda archivos csv
 *
 * \param tramiteUrgente array list de tramites urgentes
 * \param tramiteRegular array list de tramites regulares
 * \param turnosUrgentes array list de turnos urgentes
 * \param turnosRegulares array list de turnos regulares
 * \return
 *
 */

 void guardarArchivos(ArrayList* tramiteUrgente,ArrayList* tramiteRegular,ArrayList* turnosUrgentes,ArrayList* turnosRegulares)
{
    int i;
    FILE* archivoTramitesUr = fopen("TramitesUrgentes.csv", "w");
	FILE* archivoTramitesReg = fopen("TramitesRegulares.csv", "w");
	FILE* archivoTurnosUr = fopen("TurnosUrgentes.csv", "w");
	FILE* archivoTurnosReg = fopen("TurnosRegulares.csv", "w");

    if(archivoTramitesUr!=NULL)
    {
        escribirEnArchivoElArray(archivoTramitesUr,tramiteUrgente);
    }

    if(archivoTramitesReg!=NULL)
    {
        escribirEnArchivoElArray(archivoTramitesReg,tramiteRegular);
    }

    if(archivoTurnosUr!=NULL)
    {
        escribirEnArchivoElArray(archivoTurnosUr,turnosUrgentes);
    }

    if(archivoTurnosUr!=NULL)
    {
        escribirEnArchivoElArray(archivoTurnosReg,turnosRegulares);
    }
}
