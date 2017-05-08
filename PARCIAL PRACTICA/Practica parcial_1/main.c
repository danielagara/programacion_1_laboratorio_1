#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "strings.h"


#define TAM_U 1000
#define TAM_C 600

#define LIBRE -1
#define OCUPADO 1
#define INHABILITADO -2

typedef struct
{
    int idNick;
    char nombre[50];
    int clave;
    char correoElectronico[100];
    int estado;
}eUsuario;

typedef struct
{
    int idComentario;
    char textoComentario[100];
    int contadorMG;
    int estadoComentario;
}eComentario;

typedef struct
{
    int idComentUsuario;
    int idNick;
    int clave;
    int idComentario;
}eComentarioUsuario;

typedef struct
{
    int idNick;
    char nombre[50];
    int clave;
    char correoElectronico[100];
}eAUXusuarios;

typedef struct
{
    int idNick;
    int contadorUsuarioComentario;

}eAUXmaxComentarioUsuario;

void inicializarEstado(eUsuario[], int);
void inicializarEstadoComentario(eComentario[], int);
void inicializarNICK(eUsuario[], int);
void inicializarContadorMG(eComentario[],int);
void altaDeUsuario(eUsuario[], int);
void modificarUsuario(eUsuario[], int);
void bajaDeUsuario(eUsuario[], int);
void nuevoComentario(eUsuario[], int,eComentario[],int, eComentarioUsuario[],int);
void nuevoMeGusta(eUsuario[],int,eComentario[], int,eComentarioUsuario[], int);
void mayorCantidadDeComentarios(eComentario[],int,eUsuario[],int,eComentarioUsuario[], int);

int main()
{
    eUsuario usuarios[20];
    eComentario comentarios[30];
    eComentarioUsuario comentarioPorUsuario[30];

    inicializarEstado(usuarios, 20);
    inicializarEstadoComentario(comentarios,30);
    inicializarNICK(usuarios,20);
    inicializarContadorMG(comentarios,30);

    int opcion;
    char seguir='s';



    while(seguir!='n')
    {
        printf("\n1- Alta de usuario\n");//ok
        printf("2- Modificar datos de usuario\n");//ok
        printf("3- Baja de usuario\n");//ok
        printf("4- Nuevo comentario\n");//ok
        printf("5- Nuevo ME GUSTA\n");//ok
        printf("6- Informar\n");
        printf("7- Listado de usuarios\n");
        printf("8- Salir\n");

        fflush(stdin);
        scanf("%d", &opcion);
        switch(opcion)
        {
            case 1://ALTA DE USUARIO
                altaDeUsuario(usuarios,20);
                break;

            case 2:
                modificarUsuario(usuarios,20);
                break;

            case 3:
                bajaDeUsuario(usuarios,20);
                break;

            case 4:
                nuevoComentario(usuarios,20,comentarios,30,comentarioPorUsuario,30);
                break;

            case 5:
                nuevoMeGusta(usuarios,20,comentarios,30,comentarioPorUsuario,30);
                break;

            case 6:
                printf("\n1. El usuario con mayor cantidad de comentarios:\n");
                mayorCantidadDeComentarios(comentarios,30,usuarios,20,comentarioPorUsuario,30);
                printf("\n2. El comentario con mayor cantidad de “Me gusta”:\n");
                //mayorCantidadDeMG
                printf("\n3. El valor promedio de “Me gusta”:\n");
                //promedioMeGusta
                break;

            case 7:
                break;

            case 8:
                seguir='n';
                break;
        }
    }


    return 0;
}

void inicializarEstado(eUsuario usuario[], int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        usuario[i].estado=-1;
    }
}

void inicializarEstadoComentario(eComentario comentario[], int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        comentario[i].estadoComentario=-1;
    }
}

void inicializarNICK(eUsuario usuario[], int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        usuario[i].idNick=-1;
    }
}

void inicializarContadorMG(eComentario comentario[], int tamCom)
{
    int i;
    for(i=0;i<tamCom;i++)
    {
        comentario[i].contadorMG=0;
    }
}

void altaDeUsuario(eUsuario usuario[], int tam)
{
    int i, j;
    int auxNick;
    int repetido=0;
    int disponible=-1;

    for(i=0;i<tam;i++)
    {
        if(usuario[i].estado==-1)
        {
            usuario[i].estado=i;
            disponible=i;
        }
    }
    if(disponible!=tam && disponible!=-1)
    {
        printf("Ingrese su NICK:\n ");
        fflush(stdin);
        scanf("%d", &auxNick);
        for(j=0;j<tam;j++)
        {
            if(auxNick==usuario[j].idNick)
            {
                repetido=1;
                printf("EL NICK YA SE ENCUENTRA REGISTRADO");
                break;
            }
        }

            if(repetido==0)
            {
                usuario[disponible].idNick=auxNick;
                printf("Ingrese su nombre:\n ");
                fflush(stdin);
                gets(usuario[disponible].nombre);
                printf("Ingrese su correo electronico:\n ");
                fflush(stdin);
                gets(usuario[disponible].correoElectronico);
                printf("Ingrese su clave:\n ");
                fflush(stdin);
                scanf("%d", &usuario[disponible].clave);
            }
    }
}

void modificarUsuario(eUsuario usuarios[], int tam)
{
    eAUXusuarios auxusuarios[20];
    int i, j, opcion;
    char seguir='s';
    int posicion;

    while(seguir=='s')
    {
        printf("ELIJA LA OPCION A MODIFICAR: \n 1-NOMBRE \n 2-CORREO ELECTRONICO \n 3-CLAVE\n 4-SALIR \n");
        fflush(stdin);
        scanf("%d", &opcion);
        switch(opcion)
        {
            case 1://NOMBRE
                printf("Ingrese el nick\n");
                fflush(stdin);
                scanf("%d", &auxusuarios[0].idNick);
                for(j=0;j<tam;j++)
                {
                    if(auxusuarios[0].idNick==usuarios[j].idNick)
                    {
                        printf("ingrese nombre\n");
                        fflush(stdin);
                        gets(auxusuarios[0].nombre);
                        if(stricmp(usuarios[j].nombre,auxusuarios[0].nombre)==0)
                        {
                            printf("ingrese nuevo nombre\n");
                            fflush(stdin);
                            gets(auxusuarios[0].nombre);
                            strcpy(usuarios[j].nombre,auxusuarios[0].nombre);
                            printf("su nuevo nombre es %s \n", usuarios[j].nombre);
                        }
                    }
                }

            break;
            case 2://CORREO ELECTRONICO
                printf("Ingrese el nick\n");
                fflush(stdin);
                scanf("%d", &auxusuarios[0].idNick);
                for(j=0;j<tam;j++)
                {
                    if(auxusuarios[0].idNick==usuarios[j].idNick)
                    {
                        printf("ingrese correo electronico\n");
                        fflush(stdin);
                        gets(auxusuarios[0].correoElectronico);
                        if(stricmp(usuarios[j].correoElectronico,auxusuarios[0].correoElectronico)==0)
                        {
                            printf("ingrese nuevo correo electronico\n");
                            fflush(stdin);
                            gets(auxusuarios[0].correoElectronico);
                            strcpy(usuarios[j].correoElectronico,auxusuarios[0].correoElectronico);
                            printf("su nuevo nombre es %s\n", usuarios[j].correoElectronico);
                        }
                    }
                }
            break;
            case 3://CLAVE
                printf("Ingrese el nick\n");
                fflush(stdin);
                scanf("%d", &auxusuarios[0].idNick);
                for(j=0;j<tam;j++)
                {
                    if(auxusuarios[0].idNick==usuarios[j].idNick)
                    {
                        printf("ingrese la clave\n");
                        fflush(stdin);
                        scanf("%d", &auxusuarios[0].clave);
                        printf("%d\n%d\n", auxusuarios[0].clave, usuarios[j].clave);
                        if(auxusuarios[0].clave==usuarios[j].clave)
                        {
                            printf("ingrese nueva clave\n");
                            fflush(stdin);
                            scanf("%d",&auxusuarios[0].clave);
                            usuarios[j].clave=auxusuarios[0].clave;
                            printf("su nueva clave es %d\n", usuarios[j].clave);
                        }
                    }
                }
            break;
            case 4://SALIR
            seguir='n';
            break;

        }
    }
}

void bajaDeUsuario(eUsuario usuarios[], int tam)
{
    char respuesta;
    int auxNICK;
    int i, j;

    printf("Ingrese el nick\n");
    fflush(stdin);
    scanf("%d", &auxNICK);
    for(j=0;j<tam;j++)
    {
        if(auxNICK==usuarios[j].idNick)
        {
            printf("Esta seguro que quiere dar de baja su usuario? S o N\n");
            fflush(stdin);
            scanf("%c", &respuesta);
            if(respuesta!='n')
            {
                usuarios[j].estado=-2;
                printf("SU USUARIO SE ENCUENTRA INHABILITADO\n%d",usuarios[j].estado);
            }
        }
    }
}

void nuevoComentario(eUsuario usuario[], int tamUs, eComentario comentario[], int tamCom,  eComentarioUsuario comentarioUsuario[], int tamCU)
{
    int i, j,disponible;
    int id;

    for(i=0;i<tamCom;i++)
    {
        if(comentario[i].estadoComentario==-1)
        {
            comentario[i].estadoComentario=i;
            disponible=i;
            break;
        }
    }
    if(disponible!=tamCom && disponible!=-1)
    {
            printf("Ingrese su nick\n");
            fflush(stdin);
            scanf("%d", &comentarioUsuario[disponible].idNick);
            for(j=0;j<tamUs;j++)
            {
                if(comentarioUsuario[disponible].idNick==usuario[j].idNick)
                {
                    printf("Ingrese su clave\n");
                    fflush(stdin);
                    scanf("%d", &comentarioUsuario[disponible].clave);
                    if(usuario[j].clave==comentarioUsuario[disponible].clave)
                    {
                        comentario[j].idComentario=disponible;
                        printf("Escriba el comentario:\n");
                        fflush(stdin);
                        gets(comentario[j].textoComentario);
                        printf("Su comentario se registro exitosamente:%s\n",comentario[j].textoComentario);
                        printf("El identificador de su comentario es:%d\n",comentario[j].idComentario);
                    }
                }
            }
    }
}

void nuevoMeGusta(eUsuario usuario[], int tamUs, eComentario comentario[], int tamCom,  eComentarioUsuario comentarioUsuario[], int tamCU)
{
    int i, j;
    int auxNICK, auxCLAVE, auxIDCOM;

        printf("Ingrese su nick\n");
        fflush(stdin);
        scanf("%d", &auxNICK);
        for(j=0;j<tamUs;j++)
        {
            if(auxNICK==usuario[j].idNick)
            {
                printf("Ingrese su clave\n");
                fflush(stdin);
                scanf("%d", &auxCLAVE);
                if(usuario[j].clave==auxCLAVE)
                {
                    for(i=0;i<tamCom;i++)
                    {
                        printf("Ingrese identificador del comentario:\n");
                        fflush(stdin);
                        scanf("%d", &auxIDCOM);
                        if(auxIDCOM==comentario[i].idComentario)
                        {
                            comentario[i].contadorMG++;
                            printf("Este comentario ahora tiene esta cantidad de MG:%d\n",comentario[i].contadorMG);
                        }
                    }
                }
            }
        }
}

void mayorCantidadDeComentarios(eComentario comentarios[], int tamCom, eUsuario usuarios[], int tamUs, eComentarioUsuario comentarioUsuario[], int tamCU)
{
    int i, j, k, max;

    eAUXmaxComentarioUsuario auxComentarioUsuario[20];

    for(i=0;i<tamUs;i++)
    {
        auxComentarioUsuario[i].contadorUsuarioComentario=0;
    }

    for(i=0;i<tamUs;i++)
    {
        for(j=0;j<tamCU;j++)
        {
            if(usuarios[i].idNick==comentarioUsuario[j].idNick)
            {
                auxComentarioUsuario[i].idNick=usuarios[i].idNick;
                auxComentarioUsuario[j].contadorUsuarioComentario++;
            }
        }
    }

    for(i=0; i<tamUs;i++)
    {
         if(i==0)
        {
            max=auxComentarioUsuario[i].contadorUsuarioComentario;
        }
        else
        {
            if(auxComentarioUsuario[i].contadorUsuarioComentario>max)
            {
                max=auxComentarioUsuario[i].contadorUsuarioComentario;
            }

        }
    }

    for(i=0; i<tamUs; i++)
    {
        if(auxComentarioUsuario[i].contadorUsuarioComentario==max)
        {
            for(k=0;k<tamUs;k++)
            {
                if(usuarios[k].idNick==auxComentarioUsuario[i].idNick)
                {
                    printf("%s\n", usuarios[k].nombre);

                }
            }
        }
    }

}
