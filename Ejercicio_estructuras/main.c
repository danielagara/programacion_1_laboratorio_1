#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dia;
    int mes;
    int anio;//no funcan las ñ
}eFecNac;

typedef struct
{//estructura
    int legajo;
    char nombre[20];//todos los datos que la componen
    float sueldo;
    char sexo;
    eFecNac fecNac;
} ePersona;//la defino

void mostrarPersona (ePersona x);
void mostrarPersonas (ePersona x[], int cant);

int main()
{
    int i;
    ePersona unaPersona;//uso una variable de la estructura

    ePersona gente[5]={{111, "natalia", 5000, 'f', {4,5,2000}} , {222, "daniela", 6000, 'f', {4,5,2001}} , {333, "raul", 5000, 'm', {4,5,2002}} , {444, "soilo", 5000, 'm', {4,5,2003}} , {555, "noel", 7000, 'm', {4,5,2004}}};

    /*printf("Ingrese Legajo:\n\n ");
    fflush(stdin);
    scanf("%d", &unaPersona.legajo);//pongo el nombre de la variable que llama a mi estructura.el elemento a llenar

    printf("Ingrese nombre:\n\n ");
    fflush(stdin);
    gets(unaPersona.nombre);

    printf("Ingrese sueldo:\n\n ");
    fflush(stdin);
    scanf("%f", &unaPersona.sueldo);

    printf("Ingrese sexo:\n\n ");
    fflush(stdin);
    scanf("%c", &unaPersona.sexo);

    printf("Ingrese el dia de nacimiento:\n\n");
    fflush(stdin);
    scanf("%d", &unaPersona.fecNac.dia);

    printf("Ingrese el mes de nacimiento:\n\n ");
    fflush(stdin);
    scanf("%d", &unaPersona.fecNac.mes);

    printf("Ingrese anio de nacimiento:\n\n ");
    fflush(stdin);
    scanf("%d", &unaPersona.fecNac.anio);

    mostrarPersona(unaPersona);*/
    mostrarPersonas(gente, 5);
    //printf("\n\nLEGAJO: %d\n\nNOMBRE: %s\n\nSUELDO: %f\n\nSEXO: %c", unaPersona.legajo, unaPersona.nombre, unaPersona.sueldo, unaPersona.sexo);
    return 0;
}

void mostrarPersona (ePersona x)
{
    printf("\n\nLEGAJO:\n\n%d ", x.legajo);
    printf("\n\nNOMBRE:\n\n%s ", x.nombre);
    printf("\n\nSUELDO:\n\n%f ", x.sueldo);
    printf("\n\nSEXO:\n\n%c ", x.sexo);
    printf("\n\nFECHA DE NACIMIENTO: \n\n%d/%d/%d", x.fecNac);
}

void mostrarPersonas (ePersona x[], int cant)
{
    int j;
    for(j=0;j<cant;j++)
    {
        printf("\n---------------");
        mostrarPersona(x[j]);
    }
}
