#include <stdio.h>
#include <stdlib.h>

void mostrarMatrices(int matriz[][4]);

int main()
{
    int matriz [3][4];

    int i, j;
    int numero;

    //cargar matriz
    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
        {
            printf("Ingrese un numero: ");
            fflush(stdin);
            scanf("%d", &numero);
            matriz[i][j]=numero;
        }
    }
    int matriz2[][4]={1,2,3,4,5,6,7,8,9,10,11,12};

    mostrarMatrices(matriz);


    mostrarMatrices(matriz2);
    return 0;
}

void mostrarMatrices(int matriz[][4])
{
    int i, j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
        {
            printf("    %d", matriz[i][j]);
        }
        printf("\n");
    }
}
