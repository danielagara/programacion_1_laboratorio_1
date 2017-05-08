#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "strings.h"
#include "time.h"

/** \brief FUNCION SUMAR
 *
 * \param int primer numero
 * \param int segundo numero
 * \return resultado de la suma
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
 * \param int primer numero
 * \param int segundo numero
 * \return resultado de la resta
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
 * \param int primer numero
 * \param int segundo numero
 * \return resultado de la division
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
 * \param int primer numero
 * \param int segundo numero
 * \return resultado de la multiplicacion
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
 * \param int primer numero
 * \param int segundo numero
 * \return factorial del resultado
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
 * \param int vector
 * \param int tamaño del vector
 * \param int orden 1 para asc y 2 para dsc
 * \return void porque ordena el vector
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


/** \brief FUNCION GET NUMERO DECIMAL
 *
 * \param mensaje El mensaje a ser mostrado
 * \return el numero ingresado por el usuario
 *
 */
float getFloat(char mensaje[])
{
	float auxiliar;
	printf("%s", mensaje);
	scanf("%f", &auxiliar);
	return auxiliar;
}

/** \brief FUNCION GET NUMERO
 *
 * \param mensaje El mensaje a ser mostrado
 * \return el numero ingresado por el usuario
 *
 */
int getInt(char mensaje[])
{
	int auxiliar;
	printf("%s", mensaje);
	scanf("%d", &auxiliar);
	return auxiliar;
}

/** \brief FUNCION GET LETRA
 *
 * \param mensaje El mensaje a ser mostrado
 * \return el caracter ingresado por el usuario
 *
 */

char getChar(char mensaje[])
{
	char auxiliar;
	printf("%s", mensaje);
	fflush(stdin);
	scanf("%c", &auxiliar);
	return auxiliar;
}

/** \brief FUNCION GET NUMERO ALEATORIO
 *
 * \param desde numero aleatorio minimo
 * \param hasta numero aleatorio maximo
 * \param iniciar indica si se trata del primer numero solicitado, 1 es si
 * \return
 *
 */

char getNumeroAleatorio(int desde, int hasta, int iniciar)
{
	if(iniciar)
		srand(time(NULL));
	return desde + (rand() % (hasta + 1 - desde));
}

/** \brief FUNCION VERIFICAR DATO SOLO NUMEROS
 *
 * \param str Aray con la cadena a ser analizada
 * \return 1 si es numerico y 0 si no lo es
 *
 */

int esNumerico(char str[])
{
	int i=0;
	while(str[i] !='\0')
	{
		if(str[i]<'0' || str[i]>'9')
			return 0;
		i++;
	}
	return 1;
}

/** \brief FUNCION VERIFICAR DATO SOLO LETRAS
 *
 * \param str Aray con la cadena a ser analizada
 * \return 1 si es numerico y 0 si no lo es
 *
 */

int esSoloLetras(char str[])
{
	int i=0;
	while(str[i] != '\0')
	{
		if((str[i] != ' ') && (str[i] <'a' || str[i] > 'z') && (str[i] <'A' || str[i] > 'Z'))
			return 0;
		i++;
	}
	return 1;
}

/** \brief FUNCION VERIFICAR DATO SOLO LETRAS Y NUMEROS
 *
 * \param str Aray con la cadena a ser analizada
 * \return 1 si son letras, espacio y numeros,  y 0 si no lo es
 *
 */

int esAlfaNumerico(char str[])
{
	int i=0;
	while(str[i] != '\0')
	{
		if((str[i] != ' ') && (str[i] <'a' || str[i] > 'z') && (str[i] <'A' || str[i] > 'Z') && (str[i]<'0' || str[i]>'9'))
			return 0;
		i++;
	}
	return 1;
}

/** \brief FUNCION GET STRING
 *
 * \param mensaje El mensaje a ser mostrado
 * \param input array donde se cargara el texto ingresado
 * \return void porque solo lo obtiene
 *
 */

int getString(char mensaje[],char input[])
{
	printf("%s", mensaje);
	gets(input);
}

/** \brief FUNCION VALIDAR LETRAS DE STRING
 *
 * \param mensaje El mensaje a ser mostrado
 * \param input array donde se cargara el texto ingresado
 * \return 1 si el texto son solo letras, 0 si no lo son
 *
 */

 int getStringLetras(char mensaje[], char input[])
 {
	 char aux[256];
	 getString(mensaje,aux);
	 if(esSoloLetras(aux))
     {
         strcpy(input, aux);
		 return 1;
     }

	 else
     {
         return 0;
     }

 }

/** \brief FUNCION BUSCAR PRIMERA OCURRENCIA EN ARRAY
 *
 * \param array El array en el que se va a buscar
 * \param cantidad_de_elementos Longitud del array
 * \param valor El valor que se buca
 * \return Si no hay ocurrencia (-1) y si la hay posicion de la misma (i)
 *
 */
/*
int buscarPrimerOcurrencia(int array[], int cantidad_de_elementos, int valor)
{
	int i;
	for(i=0;i<cantidad_de_elementos;i++)
	{
		if(usuario[j].idNick==valor)
		{
			return i;
		}
	}
	return -1;
}

*/
