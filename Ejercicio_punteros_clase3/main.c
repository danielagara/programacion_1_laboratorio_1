#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char marca[20];
    char modelo[15];
    float precio;
}eNotebook;


void mostrarNotebook(eNotebook*x);
eNotebook* newNotebookParam(int id, char marca, char modelo, float precio);


int main()
{

    eNotebook* unaNotebook, otraNotebook;
    unaNotebook=newNotebook();
    otraNotebook=newNotebookParam(112, "HP", "Envy", 30.000);
    if(unaNotebook==NULL)
    {
        printf("No se puede asignar memoria\n");
        exit(1);

    }

    mostrarNotebook(unaNotebook);
    free(unaNotebook);
    return 0;
}

eNotebook* newNotebookParam(int id, char* marca, char modelo, float precio)
{
    eNotebook* x;
    x=(eNotebook*)malloc(sizeof(eNotebook));
    if(x!=NULL)
    {
        x->id=0;
        x->precio=0;
        strcpy(x->marca, "");
        strcpy(x->modelo, " ");
    }
    return x;
}

/*eNotebook* newNotebook (void)
{
    eNotebook* x;
    x=(eNotebook*)malloc(sizeof(eNotebook));
    if(x!=NULL)
    {
        x->id=0;
        x->precio=0;
        strcpy(x->marca, "");
        strcpy(x->modelo, " ");
    }
    return x;
}*/

void mostrarNotebook(eNotebook*x)
{
    printf("id: %d\n", x->id);
    printf("Marca: %s\n", x->marca);
    printf("Modelo: %s\n", x->modelo);
    printf("Precio: %.2f\n", x->precio);
}
