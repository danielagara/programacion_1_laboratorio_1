#ifndef TRAMITE_H_INCLUDED
#define TRAMITE_H_INCLUDED

typedef struct
{
    int DNI;
    char tipoTramite;
    int atendido;
    int numTurno;
}Tramite;

Tramite* newTramite(int DNI, char tipoTramite,int atendido,int numTurno);

int comparaTramite(void* pTramiteA,void* pTramiteB);

void escribirEnArchivoElArray(FILE* archivoTramites,ArrayList* lista);

void guardarArchivos(ArrayList* tramiteUrgente,ArrayList* tramiteRegular,ArrayList* turnosUrgentes,ArrayList* turnosRegulares);

#endif // TRAMITE_H_INCLUDED
