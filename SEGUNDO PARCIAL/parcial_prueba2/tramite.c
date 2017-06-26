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
