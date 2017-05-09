#include "lib.h"
#include "strings.h"

/** \brief FUNCION INICIALIZAR ESTADO
 *
 * \param eProgramador Utiliza la estructura con la informacion de los programadores
 * \param tamProg El tamaño que se le haya asignado al array
 * \return void
 *
 */
void inicializarEstado(eProgramador programador[], int tamProg)
{
    int i;
    for(i=0;i<tamProg;i++)
    {
        programador[i].estado=-1;
    }
}

/** \brief FUNCION DEFINIR CATEGORIAS
 *
 * \param
 * \param
 * \return
 *
 */

void definirCategorias(eCategoria categoria[], int tamCat)
{
    int i;
    categoria[0].idCategoria=1;
    categoria[1].idCategoria=2;
    categoria[2].idCategoria=3;
    for(i=0;i<tamCat;i++)
    {
        if(categoria[i].idCategoria==1)
        {
            strcpy(categoria[i].descripcion,"JUNIOR");
            categoria[i].pagoXHora=100;
        }
        if(categoria[i].idCategoria==2)
        {
            strcpy(categoria[i].descripcion,"SEMI-SENIOR");
            categoria[i].pagoXHora=1000;
        }
        if(categoria[i].idCategoria==3)
        {
            strcpy(categoria[i].descripcion,"SENIOR");
            categoria[i].pagoXHora=10000;
        }
    }

}

/** \brief FUNCION ALTA DE PROGRAMADOR
 *
 * \param
 * \param
 * \return
 *
 */

void altaDeprogramador(eProgramador programador[], int tamProg, eCategoria categoria[], int tamCat)
{
    int i, j;
    int auxID;
    int repetido=0;
    int disponible=-1;

    for(i=0;i<tamProg;i++)
    {
        if(programador[i].estado==-1)
        {
            programador[i].estado=i;
            disponible=i;
            break;
        }
    }
    if(disponible!=tamProg && disponible!=-1)
    {
        printf("Ingrese su ID:\n ");
        fflush(stdin);
        scanf("%d", &auxID);
        for(j=0;j<tamProg;j++)
        {
            if(auxID==programador[j].idProgramador)
            {
                repetido=1;
                printf("EL ID YA SE ENCUENTRA REGISTRADO");
                break;
            }
        }


        if(repetido==0)
        {
            programador[disponible].idProgramador=auxID;
            printf("Ingrese su nombre:\n ");
            fflush(stdin);
            gets(programador[disponible].nombre);
            printf("Ingrese su apellido:\n ");
            fflush(stdin);
            gets(programador[disponible].apellido);
            printf("Ingrese su categoria 1=JUNIOR, 2=SEMISENIOR, 3=SENIOR:\n ");
            fflush(stdin);
            scanf("%d", &programador[disponible].idCategoria);
           // ==programador[disponible].idCategoria;
        }
    }
}

/** \brief FUNCION MODIFICAR PROGRAMADOR
 *
 * \param
 * \param
 * \return
 *
 */

void modificarUsuario(eProgramador programador[], int tamProg)
{
    eAUXProgramador auxprogramador[20];
    int i, j, opcion;
    char seguir='s';
    int posicion;

    while(seguir=='s')
    {
        printf("ELIJA LA OPCION A MODIFICAR: \n 1-NOMBRE \n 2-CORREO ELECTRONICO \n 3-idCategoria\n 4-SALIR \n");
        fflush(stdin);
        scanf("%d", &opcion);
        switch(opcion)
        {
            case 1://NOMBRE
                printf("Ingrese el idProgramador\n");
                fflush(stdin);
                scanf("%d", &auxprogramador[0].idProgramador);
                for(j=0;j<tamProg;j++)
                {
                    if(auxprogramador[0].idProgramador==programador[j].idProgramador)
                    {
                        printf("ingrese nombre\n");
                        fflush(stdin);
                        gets(auxprogramador[0].nombre);
                        if(stricmp(programador[j].nombre,auxprogramador[0].nombre)==0)
                        {
                            printf("ingrese nuevo nombre\n");
                            fflush(stdin);
                            gets(auxprogramador[0].nombre);
                            strcpy(programador[j].nombre,auxprogramador[0].nombre);
                            printf("su nuevo nombre es %s \n", programador[j].nombre);
                        }
                    }
                }

            break;
            case 2://APELLIDO
                printf("Ingrese el idProgramador\n");
                fflush(stdin);
                scanf("%d", &auxprogramador[0].idProgramador);
                for(j=0;j<tamProg;j++)
                {
                    if(auxprogramador[0].idProgramador==programador[j].idProgramador)
                    {
                        printf("ingrese su appelido\n");
                        fflush(stdin);
                        gets(auxprogramador[0].apellido);
                        if(stricmp(programador[j].apellido,auxprogramador[0].apellido)==0)
                        {
                            printf("ingrese nuevo apellido\n");
                            fflush(stdin);
                            gets(auxprogramador[0].apellido);
                            strcpy(programador[j].apellido,auxprogramador[0].apellido);
                            printf("su nuevo apellido es %s\n", programador[j].apellido);
                        }
                    }
                }
            break;
            case 3://idCategoria
                printf("Ingrese el idProgramador\n");
                fflush(stdin);
                scanf("%d", &auxprogramador[0].idProgramador);
                for(j=0;j<tamProg;j++)
                {
                    if(auxprogramador[0].idProgramador==programador[j].idProgramador)
                    {
                        printf("Ingrese su categoria 1=JUNIOR, 2=SEMISENIOR, 3=SENIOR:\n");
                        fflush(stdin);
                        scanf("%d", &auxprogramador[0].idCategoria);
                        printf("%d\n%d\n", auxprogramador[0].idCategoria, programador[j].idCategoria);
                        if(auxprogramador[0].idCategoria==programador[j].idCategoria)
                        {
                            printf("ingrese nueva idCategoria\n");
                            fflush(stdin);
                            scanf("%d",&auxprogramador[0].idCategoria);
                            programador[j].idCategoria=auxprogramador[0].idCategoria;
                            printf("su nueva idCategoria es %d\n", programador[j].idCategoria);
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

/** \brief FUNCION BAJA DE PROGRAMADOR
 *
 * \param
 * \param
 * \return
 *
 */

 void bajaDeProgramador(eProgramador programador[], int tamProg)//FALTA SACARLO DE LOS PROYECTOS
{
    char respuesta;
    int auxPROG;
    int i, j;

    printf("Ingrese el idProgramador\n");
    fflush(stdin);
    scanf("%d", &auxPROG);
    for(j=0;j<tamProg;j++)
    {
        if(auxPROG==programador[j].idProgramador)
        {
            printf("Esta seguro que quiere dar de baja su usuario? S o N\n");
            fflush(stdin);
            scanf("%c", &respuesta);
            if(respuesta!='n')
            {
                programador[j].estado=-1;
                printf("SU USUARIO SE ENCUENTRA INHABILITADO\n");
            }
        }
    }
}

/** \brief FUNCION ASIGNAR PROYECTO A PROGRAMADOR
 *
 * \param
 * \param
 * \return
 *
 */

 void asignarProgramadorAProyecto(eProgramador programador[], int tamProg, eProyecto proyecto[], int tamProye, eProyectoProgramador proyectoProgramador[], int tamPP)
{
    int i, j, contadorCantidadProgramadores=0;

	for(i=0;i<tamProg;i++)
	{
		if(programador[i].estado!=-1)
		{
			contadorCantidadProgramadores++;
		}
	}

	for(i=0;i<contadorCantidadProgramadores;i++)
	{
		printf("ESTOS SON LOS PROGRAMADORES DISPONIBLES:\nNombre:%s\nId del programador:%d\n", programador[i].nombre, programador[i].idProgramador);
		printf("A que programador elige? Ingrese su id\n");
		fflush(stdin);
		scanf("%d",&proyectoProgramador[i].idProgramador);
		for(j=0;j<tamProg;j++)
        {
            if(proyectoProgramador[i].idProgramador==programador[j].idProgramador)
            {
                printf("A que proyecto lo quiere asignar? Ingrese el id del mismo\n");
                fflush(stdin);
                scanf("%d", &proyectoProgramador[i].idProyecto);
                proyecto[j].idProyecto=proyectoProgramador[i].idProyecto;
                printf("Ingrese la cantidad de horas que el programador debe trabajar:\n");
                fflush(stdin);
                scanf("%d", &proyectoProgramador[i].horasATrabajar);
                printf("EL PROYECTO HA SIDO ASIGNADO CORRECTAMENTE:\n");
            }
        }
	}
}

/** \brief FUNCION MOSTRAR PROGRAMADORES
 *
 * \param
 * \param
 * \return
 *
 */

void mostrarProgramadores(eProgramador programador[], int tamProg, eCategoria categoria[], int tamCat, eProyectoProgramador proyectoProgramador[], int tamPP, eProyecto proyecto[], int tamProye)
{
    int i, j, k;
	int auxPrecioXHora;
	int auxHorasATrabajar;
	int gananciaTotalProyecto;
	int contadorCantidadProgramadores=0;

	for(i=0;i<tamProg;i++)
	{
		if(programador[i].estado!=-1)
		{
			contadorCantidadProgramadores++;
		}
	}

    for(i=0;i<contadorCantidadProgramadores;i++)
    {
        printf("\n---------------");
        printf("\n\nID PROGRAMADOR:\n\n%d ", programador[i].idProgramador);
        printf("\n\nNOMBRE:\n\n%s ", programador[i].nombre);
		printf("\n\nAPELLIDO:\n\n%s ", programador[i].apellido);
		for(j=0;j<tamCat;j++)
		{
			if(programador[i].idCategoria==categoria[j].idCategoria)
			{
				auxPrecioXHora=categoria[j].pagoXHora;
				printf("\n\nDESCRIPCION DE CATEGORIA:\n\n%s ", categoria[j].descripcion);
			}
		}
        for(k=0;k<tamPP;k++)
		{
			if(programador[i].idProgramador==proyectoProgramador[k].idProgramador)
			{
				auxHorasATrabajar=proyectoProgramador[k].horasATrabajar;
				printf("\n\nID PROYECTO:\n\n%d ", proyecto[k].idProyecto);
			}
		}
		gananciaTotalProyecto=auxPrecioXHora*auxHorasATrabajar;
        printf("\n\nGANANCIA TOTAL POR PROYECTO:\n\n%d ", gananciaTotalProyecto);

    }

}
