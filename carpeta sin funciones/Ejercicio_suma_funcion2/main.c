#include <stdio.h>
#include <stdlib.h>

int main()
{
    //CON SEGUNDO TIPO DE FUNCION, RECIBE NO DEVUELVE
    int num1;
    int num2;
    int resultado;

    printf("Ingrese el primer numero ");
    scanf("%d", &num1);

    printf("Ingrese el segundo numero ");
    scanf("%d", &num2);

    resultado=sumar(num1, num2);
    return 0;
}
void sumar(int num1, int num2)
{
    int resultado;
    resultado=num1+num2;

    printf("El resultado de la suma es: %d", resultado);
}
