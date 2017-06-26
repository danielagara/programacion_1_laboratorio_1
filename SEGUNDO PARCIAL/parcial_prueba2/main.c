#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "tramite.h"
int main()
{
    ArrayList* tramiteUrgente=al_newArrayList();
    ArrayList* tramiteRegular;
    tramiteRegular=al_newArrayList();

    ArrayList* turnosUrgentes;
    turnosUrgentes=al_newArrayList();

    ArrayList* turnosRegulares;
    turnosRegulares=al_newArrayList();

    int DNI;
    char tipoTramite;
    int atendido;
    int opcion;
    int numTurno=0;

    Tramite* nuevoTramite;
    Tramite* proximoTurno;

    Tramite* noAtendidoU;
    Tramite* noAtendidoR;

    Tramite* atendidosUrgentes;
    Tramite* atendidosRegulares;

    int lengthUr=tramiteUrgente->len(tramiteUrgente);
    int lenghtReg=tramiteRegular->len(tramiteRegular);

    int i;

    char seguir='s';

    while(seguir=='s')
    {
        system("cls");
        printf("1- TRAMITE URGENTE\n");
        printf("2- TRAMITE REGULAR\n");
        printf("3- PROXIMO CLIENTE\n");
        printf("4- LISTAR\n");
        printf("5- INFORMAR\n");
        printf("6- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                //NUEVO TRAMITE URGENTE
                numTurno++;
                printf("Ingrese su DNI\n");
                fflush(stdin);
                scanf("%d",&DNI);
                tipoTramite='u';
                atendido=-1;
                nuevoTramite=newTramite(DNI,tipoTramite,atendido,numTurno);
                tramiteUrgente->add(tramiteUrgente,nuevoTramite);
                printf("SU TURNO ES-> %d \n", numTurno);
                system("pause");
                break;
            case 2:
                //NUEVO TRAMITE REGULAR
                numTurno++;
                printf("Ingrese su DNI\n");
                fflush(stdin);
                scanf("%d",&DNI);
                tipoTramite='r';
                atendido=-1;
                nuevoTramite=newTramite(DNI,tipoTramite,atendido, numTurno);
                tramiteRegular->add(tramiteRegular,nuevoTramite);
                printf("SU TURNO ES-> %d \n", numTurno);
                system("pause");
                break;
            case 3:
                //PROXIMO CLIENTE

                //URGENTE
                if(tramiteUrgente->isEmpty(tramiteUrgente)==0)
                {
                    proximoTurno=(Tramite*)tramiteUrgente->pop(tramiteUrgente,0);
                    printf("SU DNI ES : %d\n", proximoTurno->DNI);
                    printf("SU NUMERO DE TURNO ES: %d\n", proximoTurno->numTurno);
                    proximoTurno->atendido=0;
                    turnosUrgentes->add(turnosUrgentes,proximoTurno);
                }//REGULAR
                else if(tramiteUrgente->isEmpty(tramiteUrgente)==1)
                {
                    if(tramiteRegular->isEmpty(tramiteRegular)==0)
                    {
                        proximoTurno=(Tramite*)tramiteRegular->pop(tramiteRegular,0);
                        printf("SU DNI ES : %d\n", proximoTurno->DNI);
                        printf("SU NUMERO DE TURNO ES: %d\n", proximoTurno->numTurno);
                        proximoTurno->atendido=0;
                        turnosRegulares->add(turnosRegulares,proximoTurno);
                    }
                    else if(tramiteRegular->isEmpty(tramiteRegular)==1)
                    {
                        printf("NO HAY QUEDAN TRAMITES POR ATENDER\n");
                    }
                }
                printf("OK\n");
                system("pause");
                break;
            case 4://ERROR EN SEGUNDO PRINT
                //LISTA PERSONAS SIN ATENDER
                //URGENTES
                if(tramiteUrgente->isEmpty(tramiteUrgente)==0)
                {
                    printf("      POR ATENDER URGENTES        \n");
                    for(i=0;i<tramiteUrgente->len(tramiteUrgente);i++)
                    {
                        noAtendidoU=(Tramite*)tramiteUrgente->get(tramiteUrgente,i);
                        printf("DNI: %d \n", noAtendidoU->DNI);
                    }
                }
                else if(tramiteUrgente->isEmpty(tramiteUrgente)==1)
                {
                    printf("NO HAY URGENTES SIN ATENDER\n");
                }

                //REGULARES:
                if(tramiteRegular->isEmpty(tramiteRegular)==0)
                {
                    printf("     POR ATENDER REGULARES        \n");
                    for(i=0;i<tramiteRegular->len(tramiteRegular);i++)
                    {
                        noAtendidoR=(Tramite*)tramiteRegular->get(tramiteRegular,i);
                        printf("DNI: %d\n", noAtendidoR->DNI);
                    }
                }
                else if(tramiteRegular->isEmpty(tramiteRegular)==1)
                {
                    printf("NO HAY REGULARES SIN ATENDER\n");
                }
                system("pause");
                break;
            case 5:
                //CLIENTES ATENDIDOS
                //URGENTES
                turnosUrgentes->sort(turnosUrgentes,comparaTramite,0);
                if(turnosUrgentes->isEmpty(turnosUrgentes)==0)
                {
                    printf("      ATENDIDOS URGENTES:         \n");
                    for(i=0;i<turnosUrgentes->size;i++)
                    {
                        atendidosUrgentes=(Tramite*)turnosUrgentes->get(turnosUrgentes,i);
                        printf("DNI: %d\n",atendidosUrgentes->DNI);
                    }
                }
                else if(turnosUrgentes->isEmpty(turnosUrgentes)==1)
                {
                    printf("NO SE HAN ATENDIDO TRAMITES URGENTES\n");
                }

                //REGULARES
                turnosRegulares->sort(turnosRegulares,comparaTramite,0);
                if(turnosRegulares->isEmpty(turnosRegulares)==0)
                {
                    printf("     ATENDIDOS REGULARES:    \n");
                    for(i=0;i<turnosRegulares->size;i++)
                    {
                        atendidosRegulares=(Tramite*)turnosRegulares->get(turnosRegulares,i);
                        printf("DNI: %d\n", atendidosRegulares->DNI);
                    }
                }
                else if(turnosRegulares->isEmpty(turnosRegulares)==1)
                {
                    printf("NO SE HAN ATENDIDO TRAMITES REGULARES\n");
                }
                system("pause");
                break;
            case 6:
            seguir='n';
            break;
        }

    }

    return 0;
}
