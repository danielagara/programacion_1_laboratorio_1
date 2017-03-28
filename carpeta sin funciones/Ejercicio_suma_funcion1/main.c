#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1;
    int num2;
    int resultado;

    printf("Ingrese el primer numero ");
    scanf("%d", &num1);

    printf("Ingrese el segundo numero ");
    scanf("%d", &num2);

    resultado=sumar(num1, num2);
    printf("El resultado de la suma es:%d", resultado);
    return 0;
}

int sumar(int numero1, int numero2)
{
    int resultado;
    resultado=numero1 + numero2;
    return resultado;
}
