#include <stdio.h>
#include <stdlib.h>

//FLATA FORMATO MATRIZ(?)
void inicializarMatriz(float matriz[][13]);
int validarLineaColectivo(char mensaje[]);
void mostrarMatrices(float matriz[][13]);
void calcularTotalXLinea(float matriz[][13]);
int main()
{
    float planillaColectivos[4][13];
    char seguir='s';
    int numeroLinea, numeroCoche;
    int fila;
    int columna;
    //i=0 es linea 1
    //i=1 es linea 2
    //i=2 es linea 3
    float totalRecaudado;

    inicializarMatriz(planillaColectivos);

    do
    {
        numeroLinea=validarLineaColectivo("Ingrese el numero de linea: (1 a 3)\n");

        numeroCoche=validarNumeroCoche("Ingrese el numero de coche: (1 a 12)\n");

        printf("Ingrese el total recaudado: ");
        fflush(stdin);
        scanf("%f", &totalRecaudado);

        fila=numeroLinea-1;
        columna=numeroCoche-1;
        planillaColectivos[fila][columna]=totalRecaudado;
        printf("\n\nDesea continuar?\n\n");
        fflush(stdin);
        scanf("%c", &seguir);
    }while(seguir=='s');

    calcularTotalXLinea(planillaColectivos);
    mostrarMatrices(planillaColectivos);

    return 0;
}

void inicializarMatriz(float matriz[][13])
{
    int i, j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<13;j++)
        {
            matriz[i][j]=0;
        }
    }
}


void mostrarMatrices(float matriz[][13])
{
    int i, j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<13;j++)
        {
            printf("%f", matriz[i][j]);
        }
        printf("\n");
    }
}

void calcularTotalXLinea(float matriz[][13])
{
    float totalAcumuladoLinea1=0;
    float totalAcumuladoLinea2=0;
    float totalAcumuladoLinea3=0;
    int i;
    for(i=0;i<12;i++)
    {
        totalAcumuladoLinea1=totalAcumuladoLinea1+matriz[0][i];
    }


    for(i=0;i<12;i++)
    {
        totalAcumuladoLinea2=totalAcumuladoLinea2+matriz[1][i];
    }


    for(i=0;i<12;i++)
    {
        totalAcumuladoLinea3=totalAcumuladoLinea3+matriz[2][i];
    }

    matriz[0][12]=totalAcumuladoLinea1;
    matriz[1][12]=totalAcumuladoLinea2;
    matriz[2][12]=totalAcumuladoLinea3;
}

int validarLineaColectivo(char mensaje[])
{
	int numeroLinea;
	printf("%s\n", mensaje);
	fflush(stdin);
	scanf("%d", &numeroLinea);
    while(numeroLinea>3 || numeroLinea<0)
    {
        printf("Ingrese el numero de linea: (1 a 3)\n");
        fflush(stdin);
        scanf("%d", &numeroLinea);
    }
	return numeroLinea;
}

int validarNumeroCoche(char mensaje[])
{
	int numeroCoche;
	printf("%s\n", mensaje);
	fflush(stdin);
	scanf("%d", &numeroCoche);
    while(numeroCoche>12 || numeroCoche<0)
    {
        printf("Ingrese el numero de coche: (1 a 12)\n");
        fflush(stdin);
        scanf("%d", &numeroCoche);
    }
	return numeroCoche;
}
