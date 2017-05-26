#include <stdio.h>
#include <stdlib.h>

int main()
{
    //char x;
    char cadena[50];
    FILE* f;
    f=fopen("prueba.txt", "r"); //(path,modo);
    if(f==NULL)
    {
        printf("No se puede crear fichero");
        exit(1);
    }
    /* CARACTER A CARACTER
    while(x!=EOF)
    {
        x=fgetc(f);
        printf("%c", x);
    }*/
    //DE A 50 CARACTERES
    while(!feof(f))
    {
        fgets(cadena,50,f);
        printf("%s", cadena);
    }

    fclose(f);
    return 0;
}
