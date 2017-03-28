#include <stdio.h>
#include <stdlib.h>

int sumar(void);

int main()
{
    //PROTOTIPO 3: NO RECIBE NI DEVUELVE
    int resultado;
    sumar();
    printf("El resultado de la suma es: %d", resultado);
    return 0;
}

int sumar(void)
{
    int num1;
    int num2;
    int resultado;

    printf("Ingrese el primer numero: ");
    scanf("%d", &num1);

    printf("Ingrese el segundo numero: ");
    scanf("%d", &num2);

    resultado=num1+num2;

    return resultado;
}
