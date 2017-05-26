#include <stdio.h>
#include <stdlib.h>

typedef struct
{

}eNotebook;

int main()
{
    eNotebook* otraNotebook;
    FILE* f;
    f=fopen("prueba.bin","wb");//rb para solo leer
    if(f==NULL)
    {
        printf("No se puede crear su fichero");
        exit(1);
    }
    fwrite(otraNotebook,sizeof(eNotebook),1,f);//fread para leer
    fclose(f);
    return 0;
}
