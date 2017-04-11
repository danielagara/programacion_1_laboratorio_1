#include <stdio.h>
#include <stdlib.h>
#define tam 5

int main()
{
    int i, j, aux;
    int vec[tam]={5, 8, 1, 3, 7};


        printf("El vector inicial es:\n\n");
        for(i=0;i<tam;i++)
        {
            printf(" %d ", vec[i]);
        }

        for(i=0;i<tam;i++)//VA A ITERAR POR LAS VECES QUE SEA EL TAMAÑO DEL VECTOR
        {
            for(j=i+1;j<tam;j++)
            {
                if(vec[i]>vec[j])//si el de la izq es mayor al de la dere, lo paso MENOR A MAYOR
                {
                    aux=vec[i];
                    vec[i]=vec[j];
                    vec[j]=aux;
                }
            }

        }
        printf("\n\nEl vector ordenado ascendente queda:\n\n");
        for(i=0;i<tam;i++)
        {
            printf(" %d ", vec[i]);
        }

        printf("\n\nEl vector ordenado descendente queda:\n\n");
        for(i=tam-1;i>=0;i--)
        {
            printf(" %d ", vec[i]);
        }


    return 0;
}
