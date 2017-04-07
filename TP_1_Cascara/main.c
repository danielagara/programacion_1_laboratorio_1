#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
	int num1, num2; resultado;
	int resultadoSumar, resultadoRestar, resultadoDividir, resultadoMultiplicar, resultadoFactorial;
	char bandera1="n"; bandera2="n";

    while(seguir=='s')
    {
        printf("1- Ingresar 1er operando (A=x)\n"); //H
        printf("2- Ingresar 2do operando (B=y)\n"); //H
        printf("3- Calcular la suma (A+B)\n"); //H FUNCION 
        printf("4- Calcular la resta (A-B)\n"); //H FUNCION
        printf("5- Calcular la division (A/B)\n");//H FUNCION
        printf("6- Calcular la multiplicacion (A*B)\n"); //H FUNCION
        printf("7- Calcular el factorial (A!)\n");//H FUNCION
        printf("8- Calcular todas las operacione\n");//H 
        printf("9- Salir\n"); //H

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
			printf("Ingrese el primer numero ");
			scanf("%d", &num1);
			bandera1="s";
			break;
            case 2:
			printf("Ingrese el segundo numero ");
			scanf("%d", &num2);
			bandera2="s";
                break;
            case 3:
			while(bandera1=="s" && bandera2=="s")
			{
				resultado=sumar(num1, num2);
				printf("El resultado de la suma es:%d", resultado);
			}
                break;
            case 4:
			while(bandera1=="s" && bandera2=="s")
			{
				resultado=restar(num1, num2);
				printf("El resultado de la resta es:%d", resultado);
			}
                break;
            case 5:
			while(bandera1=="s" && bandera2=="s")
			{
				resultado=dividir(num1, num2);
				printf("El resultado de la division es:%d", resultado);
			}
			
                break;
            case 6:
			while(bandera1=="s" && bandera2=="s")
			{
				resultado=multiplicar(num1, num2);
				printf("El resultado de la multiplicacion es:%d", resultado);
			}
                break;
            case 7:
			while(bandera1=="s" && bandera2=="s")
			{
				factorial=factoriales(num1, num2);
				printf("El factorial del resultado es:%d", factorial);
			}
                break;
            case 8:
			while(bandera1=="s" && bandera2=="s")
			{
				resultadoSumar=sumar(num1, num2);
				printf("El resultado de la suma es:%d", resultado);
				
				resultadoRestar=restar(num1, num2);
				printf("El resultado de la resta es:%d", resultado);
				
				resultadoDividir=dividir(num1, num2);
				printf("El resultado de la division es:%d", resultado);
				
				resultadoMultiplicar=multiplicar(num1, num2);
				printf("El resultado de la multiplicacion es:%d", resultado);
				
				resultadoFactorial=factoriales(num1, num2);
				printf("El factorial del resultado es:%d", factorial);
			}
                break;
            case 9:
                seguir = 'n';
                break;
        }

	}
    return 0;
}
