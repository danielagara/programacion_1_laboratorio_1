#include <stdio.h>
#include <stdlib.h>

int main()
{
    //PROTOTIPO 3: NO RECIBE NI DEVUELVE
    sumar();
    return 0;
}

void sumar(void)
{
    int num1;
    int num2;
    int resultado;

    printf("Ingrese el primer numero: ");
    scanf("%d", &num1);

    printf("Ingrese el segundo numero: ");
    scanf("%d", &num2);

    resultado=num1+num2;

    printf("El resultado de la suma es: %d" , resultado);
}
