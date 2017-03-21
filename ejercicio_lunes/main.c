#include <stdio.h>
#include <stdlib.h>

int main()
{

    int numero;
    int contador=0;
    int contadorPares=0;
    int contadorImpares=0;
    int acumuladorNumeros=0;
    int acumuladorImpares=0;
    int promedio;
    int max;
    int minImpar;
    int acumuladorTotal=0;
    int primerRango=0;
    int segundoRango=0;
    int tercerRango=0;
    int sumatoriaAntecedentes=0;
    int antecedentes;
    int unidad;
    char seguir='s';


    while(seguir=='s')
    {
        printf("Ingrese un numero positivo:");
        scanf("%d", &numero);
        acumuladorNumeros=acumuladorNumeros+numero;
    //contador++;

    if(numero % 2 == 0)
    {
        contadorPares++;
    }
    else
    {
        if(numero % 2 !=0)
        {
            contadorImpares++;
            acumuladorImpares=acumuladorImpares+numero;
        }
    }

    if(numero%2 !=0 && contador==0)
    {
        minImpar=numero;
    }
    else
    {
        if(numero<minImpar)
        {
            minImpar=numero;
        }
    }

    if(contador==0)
    {
        max=numero;
    }
    else
    {
        if(numero>max)
        {
            max=numero;
        }
    }

    if(numero>=3 && numero<=15)
    {
        primerRango++;
    }
    else
    {
        if(numero>=16 && numero<=29)
        {
            segundoRango++;
        }
        if(numero>=30)
        {
            tercerRango++;
        }
    }

    contador++;
    printf("Ingrese n para dejar de ingresar numeros o s para seguir: ");
    fflush(stdin);
    scanf("%c", &seguir );
    }

    for(antecedentes=1;antecedentes<=acumuladorImpares;antecedentes++)
    {
        sumatoriaAntecedentes=sumatoriaAntecedentes+antecedentes;
    }

    for(unidad=acumuladorImpares;unidad>0;unidad--)
    {
        printf("%d", unidad);
    }

    //for()
    promedio=(acumuladorTotal/contador);


    printf("\nLa cantidad de numeros pares es: %d", contadorPares);
    printf("\nLa cantidad de numeros impares es: %d", contadorImpares);
    printf("\nLa sumatoria de los impares es: %d", acumuladorImpares);
    printf("\nEl promedio de todos los numeros es: %d", promedio);
    printf("\nEl numero mayor ingresado es: %d", max);
    printf("\nEl numero impar menor ingresado es: %d", minImpar);
    printf("\nLa cantidad de numeros entre el 3 y el 15 es: %d", primerRango);
    printf("\nLa cantidad de numeros entre el 16 y el 29 es: %d", segundoRango);
    printf("\nLa cantidad de numeros de 30 o mas es: %d", tercerRango);
    printf("\nLa sumatoria de los antecedentes impares es: %d", sumatoriaAntecedentes);
}
