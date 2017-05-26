#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* f;
    f=fopen("prueba", "w"); //(path,modo);
    if(f==NULL)
    {
        printf("No se puede crear fichero");
        exit(1);
    }
    fprintf(f,"Hola mundo!\n");
    fclose(f);

    return 0;
}
