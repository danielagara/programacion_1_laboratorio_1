#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x=5;
    int* p;
    p=&x;
    *p=10;
    printf("%d", x);
    printf("\n\n%d", *p);

    int vec[5];
    int numero;
    int i;
    for(i=0;i<5;i++)
    {
        printf("Ingrese un numero");
        fflush(stdin);
        scanf("%d", vec+i);

        printf("%d", *(vec+i));
    }

    return 0;
}
