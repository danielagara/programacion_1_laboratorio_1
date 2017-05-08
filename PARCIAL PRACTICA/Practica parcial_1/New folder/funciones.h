#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

//funcion sumar
int sumar(int num1, int num2);

//funcion restar
int restar(int num1, int num2);

//funcion dividir

int dividir(int num1, int num2);

//funcion multiplicar
int multiplicar(int num1, int num2);

//funcion factoriales
int factoriales(int num1, int num2);

//funcion ordenar vector
void OrdenDeVectores (int vec[], int tam, int orden);

//funcion esSoloLetras
int esSoloLetras(char str[]);


//funcion getString
int getString(char mensaje[], char input[]);


//funcion obtener numero
int getInt(char mensaje[]);

//funcion obtener numero decimal
float getFloat(char mensaje[]);

//funcion obtener char
char getChar(char mensaje[]);

//funcion getNumeroAleatorio
char getNumeroAleatorio(int desde, int hasta, int iniciar);

//funcion esNumerico
int esNumerico(char str[]);

//funcion esAlfaNumerico
int esAlfaNumerico(char str[]);

//funcion primera ocurrencia en array
int buscarPrimerOcurrencia(int array[], int cantidad_de_elementos, int valor);

/*
//funcion getstringletras
 int getStringLetras(char mensaje[], char input[]);
*/
#endif // FUNCIONES_H_INCLUDED
