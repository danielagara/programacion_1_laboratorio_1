#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

/** \brief FUNCION SUMAR
 *
 * \param int num1
 * \param int num2
 * \return 1
 *
 */

int sumar(int num1, int num2)
{
    int resultado;
    resultado=num1 + num2;
    return resultado;
}

/** \brief FUNCION RESTAR
 *
 * \param int num1
 * \param int num2
 * \return 1
 *
 */

int restar(int num1, int num2)
{
    int resultado;
    resultado=num1 - num2;
    return resultado;
}

/** \brief FUNCION DIVIDIR
 *
 * \param int num1
 * \param int num2
 * \return 1
 *
 */

int dividir(int num1, int num2)
{
    int resultado;
	char error;

	while(num2!=0)
	{
		resultado=num1 / num2;
		return resultado;
		break;
	}
	if(num2==0)
	{
		error=1;
		return error;
	}
}

/** \brief FUNCION MULTIPLICAR
 *
 * \param int num1
 * \param int num2
 * \return 1
 *
 */

int multiplicar(int num1, int num2)
{
    int resultado;
    resultado=num1 * num2;
    return resultado;
}

/** \brief FUNCION FACTORIALES
 *
 * \param int num1
 * \param int num2
 * \return 1
 *
 */

int factoriales(int num1, int num2)
{
    int resultado, factorial=1, antecedentes;
    resultado=num1 * num2;
	for(antecedentes=1;antecedentes<=resultado;antecedentes++)
    {
        factorial=factorial*antecedentes;
    }
    return factorial;
}

/** \brief FUNCION ORDEN DE VECTOR
 *
 * \param int vector,  
 * \param int tamaño del vector,
 * \param int orden 1 para asc y 2 para dsc
 * \return void
 *
 */

void OrdenDeVectores (int vec[], int tam, int orden)
{
    int i, j, aux;
    if(orden==1)
    {
        for(i=0;i<tam;i++)//ASCENDENTE
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
    }

    if(orden==2)
    {
        for(i=0;i<tam;i++)//DESCENDIENTE
        {
            for(j=i+1;j<tam;j++)
            {
                if(vec[i]<vec[j])
                {
                    aux=vec[i];
                    vec[i]=vec[j];
                    vec[j]=aux;
                }
            }
        }
    }

}