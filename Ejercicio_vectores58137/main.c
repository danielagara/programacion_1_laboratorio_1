#include <stdio.h>
#include <stdlib.h>
#define tam 5

int main()
{
    int i, j, aux;
    int vec[tam]={5, 8, 1, 3, 7};



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
    printf("El vector ordenado queda:\n");
    for(i=0;i<tam;i++)
    {
        printf(" %d ", vec[i]);
    }
    return 0;
}
