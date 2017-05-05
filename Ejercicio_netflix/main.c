#include <stdio.h>
#include <stdlib.h>


/*
2- mostrar cada uno
3- mostrar clientes con su serie
4- por cada serie los clientes que la estan viendo
5- todos los clientes que ven TBBT (100)
6- La serie menos popular

Crear una cuarta estructura que permita relacionar un cliente con una serie, de esta manera podremos obtener una relacion
muchos a muchos (Un cliente que ve muchas series)

7- Todas las series que ven los clientes de nombre "Juan"
*/


typedef struct
{
    int idSerie;
    char titulo[20];
    int temporadas;
    char genero[20];
    int estado;
}eSerie;

typedef struct
{
    int idCliente;
    char nombre[30];
    int estado;
    int idSerie;
}eCliente;

typedef struct
{
    int idSerie[5];
    int cont;
} eLoser;

void cargarSeries(eSerie[]);
void cargarClientes(eCliente[]);

void mostrarCliente(eCliente clientes[]);
void mostrarClientes(eCliente clientes[], int cant);
void mostrarSeries(eSerie series[], int cant);
void mostrarSerie(eSerie series[]);
void mostrarClientesConSerie(eCliente clientes[], eSerie series[]);
void mostrarSeriesConClientes(eCliente clientes[], eSerie series[], int cant, int segcant);
void mostrarClientesTBBT(eCliente clientes[], eSerie series[], int cant, int cant2);
void mostrarSerieLoser(eCliente clientes[], eSerie series[], int cant, int cant2);



int main()
{
    int opcion, S=5, C=5;
    eSerie series[S];
    eCliente clientes[C];
    int contadorSerieTBBT=0;

    cargarSeries(series);
    cargarClientes(clientes);

    printf("1- mostrar cada uno\n");
    printf("2- mostrar clientes con su serie\n");
    printf("3- por cada serie los clientes que la estan viendo\n");
    printf("4- todos los clientes que ven TBBT (100)\n");
    printf("5- La serie menos popular\n");
    fflush(stdin);
    scanf("%d", &opcion);

    switch(opcion)
    {
        case 1:
        printf("MOSTRANDO CLIENTES \n\n");
        mostrarSeries(series, 5);
        mostrarClientes(clientes, 5);
        break;

        case 2:
        printf("MOSTRANDO CLIENTES CON SU SERIE \n\n");
        mostrarClientesConSerie(clientes, series);
        break;

        case 3:
        printf("MOSTRANDO SERIES CON SU CLIENTE \n\n");
        mostrarSeriesConClientes(clientes, series, 10, 5);
        break;

        case 4:
        printf("MOSTRANDO CLIENTES QUE MIRAN TBBT \n\n");
        mostrarClientesTBBT(clientes, series, 10, 5);
        break;

        case 5:
        mostrarSerieLoser(clientes, series, 10, 5);
        break;
    }


    return 0;
}

void cargarSeries(eSerie series[])
{
   int idSerie[5]={100,101,102,103,104};
    int estado[5]={1,1,1,1,1};
     char titulo[5][30]={"TBBT","BB","GOT","AHS","SCD"};
    int temporadas[5]={9,7,7,6,1};
    char genero[5][30]={"Comedia","Policial","Ciencia Ficcion","Terror","Comedia"};

    int i;
     for(i=0; i<5;i++)
    {
        series[i].idSerie = idSerie[i];
        strcpy(series[i].titulo, titulo[i]);
        series[i].estado = estado[i];
        series[i].temporadas = temporadas[i];
        strcpy(series[i].genero, genero[i]);
    }

}
void cargarClientes(eCliente clientes[])
{
    int id[10] = {1,2,3,4,5,6,7,8,9,10};
    char nombres[10][30]={"juan","maria","pedro","luis","romina","jose","andrea","patricia","luciano","camila"};
    int estado[10]={1,1,1,1,1,1,1,1,1,1};
    int idSerie[10]={100,100,101,103,103,101,102,103,100,100};
    int i;

    for(i=0; i<10;i++)
    {
        clientes[i].idCliente = id[i];
        strcpy(clientes[i].nombre, nombres[i]);
        clientes[i].estado = estado[i];
        clientes[i].idSerie = idSerie[i];
    }

}

void mostrarCliente(eCliente clientes[])
{
    int i;
    for(i=0; i<10; i++)
    {
        printf("\n---------------");
        printf("\n\nID CLIENTE:\n\n%d ", clientes[i].idCliente);
        printf("\n\nNOMBRE:\n\n%s ", clientes[i].nombre);
        printf("\n\nID SERIE:\n\n%d ", clientes[i].idSerie);
    }

}

void mostrarSerie(eSerie series[])
{
    int i;
    for(i=0;i<10;i++)
    {
        printf("\n---------------");
        printf("\n\ID SERIE:\n\n%d ", series[i].idSerie);
        printf("\n\nTITULO:\n\n%s ", series[i].titulo);
        printf("\n\nTEMPORADAS:\n\n%d ", series[i].temporadas);
        printf("\n\nGENERO:\n\n%c ", series[i].genero);
    }

}


void mostrarSeries(eSerie series[], int cant)
{
    int j;
    for(j=0;j<cant;j++)
    {
        mostrarSerie(series);
    }
}


void mostrarClientes(eCliente clientes[], int cant)
{
    int j;
    for(j=0;j<cant;j++)
    {
        mostrarCliente(clientes);
    }
}

void mostrarClientesConSerie(eCliente clientes[], eSerie series[])
{
    int j;
    for(j=0;j<10;j++)
    {
        printf("\n\nNOMBRE:\n\n%s ", clientes[j].nombre);
        printf("\n\nID SERIE:\n\n%d ", clientes[j].idSerie);
    }
}

void mostrarSeriesConClientes(eCliente clientes[], eSerie series[], int cant, int segcant)
{
    int j, i;
    for(i=0;i<5;i++)
    {
        for(j=0;j<10;j++)
        {
            if(clientes[j].idSerie==series[i].idSerie)
            {
                printf("\n\nID SERIE:\n\n%d ", series[i].idSerie);
                printf("\n\nNOMBRE:\n\n%s ", clientes[j].nombre);
            }

        }
    }
}

void mostrarClientesTBBT(eCliente clientes[], eSerie series[], int cant, int cant2)
{//da con error
    int contadorSerieTBBT=0;
    int j, i;
    for(j=0;j<10;j++)
    {
        if(clientes[j].idSerie==100)
        {
            contadorSerieTBBT++;
        }series[i].idSerie;
    }


        for(i=0;i<contadorSerieTBBT;i++)
        {
            for(j=0;j<10;j++)
            {
                if(clientes[i].idSerie==100)
                {
                    printf("\n\nID SERIE:\n\n%d ", clientes[i].idSerie);
                    printf("\n\nNOMBRE:\n\n%s ", clientes[i].nombre);
                    break;
                }
            }
        }

}

void mostrarSerieLoser(eCliente clientes[], eSerie series[], int cant, int cant2)
{
    eLoser losers[5];
    int i, j, min;
    int aux[5];

    for(i=0;i<5;i++)
    {
        losers[i].idSerie=series[i].idSerie;

        printf("\n%d", losers[i].idSerie);
    }

    /*for(j=0;j<10;j++)
        {

            if(clientes[j].idSerie==losers[i].idSerie)
            {
               losers[i].cont++;
            }
        }
    if(i==0)
    {
        min=losers[i].cont;
    }
    else if(min<losers[i].cont)
    {
        min=losers[i].cont;
        printf("%d\n%d", min, losers[j].idSerie);
    }
        printf("\n%d", losers[i].cont);

    //FALTA TERMINAR Y HACER CON ESTRUCTURA QUE UNA ECLIENTESERIE*/
}
