#include <stdio.h>
#include <stdlib.h>
#include "string.h"

/* CADA PASEO SON 100 PESOS
1-Cuantos paseos hizo Bobby?
2-Cual es el paseador que mas pasea?
3-Paseadores que pasearon dobermann.
4-Perros con sus razas.
5-Mostrar perros por raza.
6-Cuanto cobra cada paseador.
*/
typedef struct
{
    int idPaseador;
    char nombrePaseador[20];
}ePaseador;

typedef struct
{
    int idPerro;
    int idRaza;
    char nombrePerro[20];
}ePerro;

typedef struct
{
    int idRaza;
    char descripcionRaza[20];
}eRaza;

typedef struct
{
    int idPaseo;
    int idPaseador;
    int idPerro;
}ePaseo;

typedef struct
{
    int idPaseador;
    int cantidad;
}eCantidadPaseosPaseador;

void paseosDeBobby(ePaseo paseos[], ePerro perros[]);
void paseadorMasPasea(ePaseador plantel[], ePaseo paseo[]);
void paseadoresPaseanDobermann(ePaseador plantel[],ePaseo paseo[], eRaza razas[],ePerro perros[]);

int main()
{
    ePaseador plantel[]={{1,"Juan"},{2,"Miguel"},{3,"Ana"}};
    ePerro perros[]={{10,100,"Bobby"},{11,300,"Colita"},{12,200,"Rex"},{13,100,"Roberto"}};
    eRaza razas[]={{100,"Dobermann"},{200,"Dogo"},{300,"Salchicha"},{400,"Boxer"}};
    ePaseo paseos[]={{1,1,10},{2,1,12},{3,2,13},{4,3,11},{5,3,12},{6,1,11}};

    eCantidadPaseosPaseador paseosPaseador[3];
    int opcion, i;

    printf("1-Cuantos paseos hizo Bobby?\n"); //listo
    printf("2-Cual es el paseador que mas pasea?\n");//falta parte
    printf("3-Paseadores que pasearon dobermann.\n");//falta parte
    printf("4-Perros con sus razas.\n");
    printf("5-Mostrar perros por raza.\n");
    printf("6-Cuanto cobra cada paseador.\n");
    fflush(stdin);
    scanf("%d", &opcion);

    switch(opcion)
    {
        case 1://PASEOS DE BOBBY
            paseosDeBobby(paseos,perros);
            break;

        case 2://PASEADOR QUE MAS PASEA
            paseadorMasPasea(plantel,paseos);
            break;

        case 3:
            paseadoresPaseanDobermann(plantel,paseos,razas,perros);
    }

    return 0;
}

void paseosDeBobby(ePaseo paseos[], ePerro perros[])
{
    int i, j, contadorBobby=0;

    for(i=0;i<4;i++)
    {
        if(stricmp("Bobby",perros[i].nombrePerro)==0)
        {
            for(j=0;j<6;j++)
            {
                if(paseos[j].idPerro==perros[i].idPerro)
                {
                    contadorBobby++;
                }
            }
        }
    }
    printf("\nLos paseos de Bobby son: %d", contadorBobby);
}


void paseadorMasPasea(ePaseador plantel[], ePaseo paseo[], eCantidadPaseosPaseador paseosPaseador[])
{

    int i, j, k;
    for(j=0;j<3;j++)
    {
        paseosPaseador[i].idPaseador=plantel[i].idPaseador;
        paseosPaseador[i].cantidad=0;
    }

    for(i=0;i<3;i++)
    {
        for(j=0;j<;j++)
        {
            if(paseo[i].idPaseador==plantel[j].idPaseador)
            {

                //printf("%s\n", plantel[j].nombrePaseador); PRINTEA LOS NOMBRES
            }
        }

    }

}

void paseadoresPaseanDobermann(ePaseador plantel[],ePaseo paseo[], eRaza razas[],ePerro perros[])
{
    int i, j, k;

    for(i=0;i<6;i++)
    {
        for(j=0;j<3;j++)
        {
            if(paseo[i].idPaseador==plantel[j].idPaseador)
            {
                for(k=0;k<4;k++)
                {
                    if(paseo[i].idPerro==perros[k].idPerro)
                    {
                        if(perros[k].idRaza==100)
                        {
                            printf("%s\n", plantel[j].idPaseador);
                        }

                    }
                }
            }
        }

    }

}

