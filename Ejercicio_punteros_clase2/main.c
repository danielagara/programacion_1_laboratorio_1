#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFechaDeIngreso;

typedef struct
{
    int legajo;
    char nombre[20];
    float sueldo;
    eFechaDeIngreso fechaDeIngreso;
}eEmpleado;

void cargarEmpleado(eEmpleado* unEmpleado, eFechaDeIngreso fechaDeIngreso);

int main()
{
    /*int vec[]={3,2,1,4,8};
    printf("%d",vec[3]);
    printf("\n%d",*(vec+3));*/


    eEmpleado unEmpleado;
    eFechaDeIngreso fechaDeIngreso;
    cargarEmpleado(&unEmpleado, fechaDeIngreso);
    printf("Legajo: %d\n", unEmpleado.legajo);
    printf("Nombre: %s\n", unEmpleado.nombre);
    printf("Sueldo: %.2f\n", unEmpleado.sueldo);
    printf("Dia: %d\n", unEmpleado.fechaDeIngreso.dia);

    return 0;
}

void cargarEmpleado(eEmpleado* unEmpleado, eFechaDeIngreso fechaDeIngreso)
{
    //*x es el contenido del puntero, y &(*x) es la direc de memoria del contenido para poder hacer el scanf
    printf("Ingrese legajo\n");
    fflush(stdin);
    scanf("%d", &(*unEmpleado).legajo);

    printf("Ingrese nombre\n");
    fflush(stdin);
    gets((*unEmpleado).nombre);

    //misma manera de poner la expresion, en vez de punto flecha
    printf("Ingrese sueldo\n");
    fflush(stdin);
    scanf("%f", &unEmpleado->sueldo);

    printf("Ingrese dia\n");
    fflush(stdin);
    scanf("%d", &unEmpleado->fechaDeIngreso.dia);

}
