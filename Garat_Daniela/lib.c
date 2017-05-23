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

/** \brief FUNCION INICIALIZAR ID
 *
 * \param eProgramador Utiliza la estructura con la informacion de los programadores
 * \param tamProg El tamaño que se le haya asignado al array
 * \return void
 *
 */

 void inicializarIdProgramador(eProgramador programador[], int tamProg)
{
    int i;
    for(i=0;i<tamProg;i++)
    {
        programador[i].idProgramador=-1;
    }
}

/** \brief FUNCION INICIALIZAR ESTADO PROGPROYE
 *
 * \param eProyectoProgramador Utiliza la estructura relacional
 * \param tamPP El tamaño que se le haya asignado al array
 * \return vois
 *
 */

void inicializarEstadoProyectoProgramador(eProyectoProgramador proyectoPorProgramador[], int tamPP)
{
    int i;
    for(i=0;i<tamPP;i++)
    {
        proyectoPorProgramador[i].estado=-1;
    }
}

/** \brief FUNCION INICIALIZAR HORAS PROGPROYE
 *
 * \param eProyectoProgramador Utiliza la estructura relacional
 * \param tamPP El tamaño que se le haya asignado al array
 * \return vois
 *
 */

void inicializarHorasProyectoProgramador(eProyectoProgramador proyectoPorProgramador[], int tamPP)
{
    int i;
    for(i=0;i<tamPP;i++)
    {
        proyectoPorProgramador[i].horasATrabajar=0;
    }
}

/** \brief FUNCION INICIALIZAR PROYECTO ID
 *
 * \param eProyecto Utiliza la estructura con la informacion de los proyectos
 * \param tamProye El tamaño que se le haya asignado al array
 * \return void
 *
 */

 void inicializarIdProyecto(eProyecto proyecto[], int tamProye)
{
    int i;
    for(i=0;i<tamProye;i++)
    {
        proyecto[i].idProyecto=-1;
    }
}


/** \brief FUNCION INICIALIZAR PROYECTO ESTADO
 *
 * \param eProyecto Utiliza la estructura con la informacion de los proyectos
 * \param tamProye El tamaño que se le haya asignado al array
 * \return void
 *
 */

  void inicializarEstadoProyecto(eProyecto proyecto[], int tamProye)
{
    int i;
    for(i=0;i<tamProye;i++)
    {
        proyecto[i].estado=-1;
    }
}

/** \brief FUNCION DEFINIR CATEGORIAS
 *
 * \param eCategoria Utiliza la estructura con la informacion de las categorias
 * \param tamCat El tamaño que se le haya asignado al array
 * \return void
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
 * \param eProgramador Utiliza la estructura con la informacion de los programadores
 * \param eCategoria Utiliza la estructura con la informacion de las categorias
 * \param tamProg El tamaño que se le haya asignado al array
 * \param tamCat El tamaño que se le haya asignado al array
 * \return void
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
 * \param eProgramador Utiliza la estructura con la informacion de los programadores
 * \param tamProg El tamaño que se le haya asignado al array
 * \return void
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
 * \param eProgramador Utiliza la estructura con la informacion de los programadores
 * \param tamProg El tamaño que se le haya asignado al array
 * \param eProyectoProgramador Utiliza la estructura relacional
 * \param tamPP El tamaño que se le haya asignado al array
 * \return void
 *
 */

 void bajaDeProgramador(eProgramador programador[], int tamProg, eProyectoProgramador proyectoProgramador[], int tamPP)
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

                for(i=0;i<tamPP;i++)
                {
                    if(programador[j].idProgramador==proyectoProgramador[i].idProgramador)
                    {
                        proyectoProgramador[i].estado=-1;
                    }
                }
                programador[j].estado=-1;
                printf("SU USUARIO SE ENCUENTRA INHABILITADO\n");
            }
        }
    }
}

/** \brief FUNCION ASIGNAR PROYECTO A PROGRAMADOR
 *
 * \param eProgramador Utiliza la estructura con la informacion de los programadores
 * \param tamProg El tamaño que se le haya asignado al array
 * \param eProyectoProgramador Utiliza la estructura relacional
 * \param tamPP El tamaño que se le haya asignado al array
 * \param eProyecto Utiliza la estructura con la informacion de los proyectos
 * \param tamProye El tamaño que se le haya asignado al array
 * \return void
 *
 */

void asignarProgramadorAProyecto(eProgramador programador[], int tamProg, eProyecto proyecto[], int tamProye, eProyectoProgramador proyectoProgramador[], int tamPP)
{
	int i, j, k, l;
	char respuesta;
	int auxIDProyecto;
	int contadorProyectos=0;
	int contadorCantidadProgramadores=0;
	int auxIdProgramador;
	int disponible=-1;
	int disponibleProyecto=-1;

	printf("Quiere ingresar un nuevo proyecto (c) o asignar uno existente (e)?");
	fflush(stdin);
	scanf("%c", &respuesta);
	if(respuesta=='e')
	{
		for(i=0;i<tamProye;i++)
		{
		    if(proyecto[i].estado!=-1)
            {
                printf("\nLos proyectos ya ingresados son:\n");
                printf("\nID DE PROYECTO: %d  NOMBRE DE PROYECTO: %s\n", proyecto[i].idProyecto, proyecto[i].nombre);
            }
		}
		printf("Ingrese el id del proyecto que quiere asignar: ");
		fflush(stdin);
		scanf("%d", &auxIDProyecto);
		for(i=0;i<tamProye;i++)
		{
			if(auxIDProyecto==proyecto[i].idProyecto)
			{
				printf("El proyecto que usted eligio es: %s \n", proyecto[i].nombre);
				for(l=0;l<tamProg;l++)
                {
                    if(programador[l].estado!=-1 && programador[l].idProgramador!=-1)
					{
						printf("Los progamadores disponibles son:\n\n");
						printf("\n\nID PROGRAMADOR:\n\n%d ", programador[l].idProgramador);
						printf("\n\nNOMBRE:\n\n%s ", programador[l].nombre);
						printf("\n\nAPELLIDO:\n\n%s ", programador[l].apellido);
					}
                }

                printf("\n\nIngrese el id del programador al que quiere asignar el proyecto:\n");
                fflush(stdin);
                scanf("%d", &auxIdProgramador);
                for(j=0;j<tamProg;j++)
                {
                    if(auxIdProgramador==programador[j].idProgramador && programador[j].estado!=-1)
                    {
                        for(k=0;k<tamPP;k++)
                        {
                            if(proyectoProgramador[k].estado==-1)
                            {
                                proyectoProgramador[k].estado=k;
                                disponible=k;
                                break;
                            }
                        }
                        if(disponible!=tamPP && disponible!=-1)
                        {
                            proyectoProgramador[disponible].idProgramador=programador[j].idProgramador;
                            proyectoProgramador[disponible].idProyecto=proyecto[i].idProyecto;
                            printf("\n\nIngrese la cantidad de horas que el programador debe trabajar:\n");
                            fflush(stdin);
                            scanf("%d", &proyectoProgramador[disponible].horasATrabajar);
                            printf("\n\nEL PROYECTO FUE ASIGNADO CORRECTAMENTE\n\n");
                            break;
                        }
                        else
                        {
                            printf("NO HAY LUGAR");
                            break;
                        }
                    }
                }

            }
            break;
        }

		}


	if(respuesta=='c')
	{
		for(l=0;l<tamProye;l++)
		{
			if(proyecto[l].estado==-1)
			{
				proyecto[l].estado=l;
				disponibleProyecto=l;
				break;
			}
		}
		if(disponibleProyecto!=-1 && disponibleProyecto!=tamProye)
		{
			printf("Ingrese el id del proyecto que quiere crear: ");
			fflush(stdin);
			scanf("%d", &auxIDProyecto);
			for(i=0;i<tamProye;i++)
			{
				if(auxIDProyecto!=proyecto[i].idProyecto)
				{
					proyecto[disponibleProyecto].idProyecto=auxIDProyecto;
					printf("Ingrese el nombre del proyecto:  ");
					fflush(stdin);
					gets(proyecto[disponibleProyecto].nombre);
                    for(l=0;l<tamProg;l++)
                    {
                        if(programador[l].estado!=-1 && programador[l].idProgramador!=-1)
                        {
                            printf("Los progamadores disponibles son:");
                            printf("\n\nID PROGRAMADOR:\n\n%d ", programador[l].idProgramador);
                            printf("\n\nNOMBRE:\n\n%s ", programador[l].nombre);
                            printf("\n\nAPELLIDO:\n\n%s ", programador[l].apellido);
                        }
                    }
						printf("Ingrese el id del programador al que quiere asignar el proyecto:\n");
                        fflush(stdin);
                        scanf("%d", &auxIdProgramador);
						for(j=0;j<tamProg;j++)
                        {

							if(auxIdProgramador==programador[j].idProgramador && programador[j].estado!=-1)
							{
								for(k=0;k<tamPP;k++)
								{
									if(proyectoProgramador[k].estado==-1)
									{
										proyectoProgramador[k].estado=i;
										disponible=i;
										break;
									}
								}

								if(disponible!=tamPP && disponible!=-1)
								{
									proyectoProgramador[disponible].idProgramador=programador[j].idProgramador;
									proyectoProgramador[disponible].idProyecto=proyecto[disponibleProyecto].idProyecto;
									printf("Ingrese la cantidad de horas que el programador debe trabajar:\n");
									fflush(stdin);
									scanf("%d", &proyectoProgramador[disponible].horasATrabajar);
									printf("EL PROYECTO FUE ASIGNADO CORRECTAMENTE");
									break;
								}
								else
								{
									printf("NO HAY LUGAR");
									break;
								}
							}
                        }
				}
				break;
			}

		}
	}

}

/** \brief FUNCION MOSTRAR PROGRAMADORES
 *
 * \param eProgramador Utiliza la estructura con la informacion de los programadores
 * \param tamProg El tamaño que se le haya asignado al array
 * \param eProyectoProgramador Utiliza la estructura relacional
 * \param tamPP El tamaño que se le haya asignado al array
 * \param eProyecto Utiliza la estructura con la informacion de los proyectos
 * \param tamProye El tamaño que se le haya asignado al array
 * \param eCategoria Utiliza la estructura con la informacion de las categorias
 * \param tamCat El tamaño que se le haya asignado al array
 * \return void
 *
 */

void mostrarProgramadores(eProgramador programador[], int tamProg, eCategoria categoria[], int tamCat, eProyectoProgramador proyectoProgramador[], int tamPP, eProyecto proyecto[], int tamProye)
{
    int i, j, k;
	int auxPrecioXHora;
	int auxHorasATrabajar;
	int gananciaTotalProyecto;

    for(i=0;i<tamProg;i++)
    {
		if(programador[i].estado!=-1 && programador[i].idProgramador!=-1)
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

}

/** \brief FUNCION MOSTRAR PROYECTOS
 *
 * \param eProgramador Utiliza la estructura con la informacion de los programadores
 * \param tamProg El tamaño que se le haya asignado al array
 * \param eProyectoProgramador Utiliza la estructura relacional
 * \param tamPP El tamaño que se le haya asignado al array
 * \param eProyecto Utiliza la estructura con la informacion de los proyectos
 * \param tamProye El tamaño que se le haya asignado al array
 * \return void
 *
 */

void mostrarProyectos(eProgramador programador[], int tamProg, eProyectoProgramador proyectoProgramador[], int tamPP, eProyecto proyecto[], int tamProye)
{
    int i, j, k;
	int contadorJunior=0;
	int contadorSemiSenior=0;
	int contadorSenior=0;

	for(i=0;i<tamPP;i++)
	{
		for(j=0;j<tamProye;j++)
		{
			if(proyectoProgramador[i].idProyecto==proyecto[j].idProyecto && proyectoProgramador[i].estado!=-1 && proyecto[j].estado!=-1)
			{
				for(k=0;k<tamProg;k++)
				{
					if(programador[k].idProgramador==proyectoProgramador[i].idProgramador && programador[k].estado!=-1)
					{

						if(programador[k].idCategoria==1)
						{
							contadorJunior++;
						}
						if(programador[k].idCategoria==2)
						{
							contadorSemiSenior++;
						}
						if(programador[k].idCategoria==3)
						{
							contadorSenior++;
						}

                        printf("\n\-------------------------:\n\n");
                        printf("\n\nID PROYECTO:\n\n%d ", proyecto[j].idProyecto);
                        printf("\n\nNOMBRE PROYECTO:\n\n%s ", proyecto[j].nombre);
                        printf("\n\nLA CANTIDAD DE PROGRAMADORES DE ACUERDO A SU CATEGORIA SON:\n\n");
                        if(contadorJunior!=0)
                        {
                            printf("\nJUNIOR: %d   \n", contadorJunior);
                        }

                        if(contadorSemiSenior!=0)
                        {
                            printf("\nSEMI-SENIOR: %d  \n", contadorSemiSenior);
                        }

                        if(contadorSenior!=0)
                        {
                            printf("\nSENIOR: %d   \n", contadorSenior);
                        }
					}

				}

			}

		}
	}

}

/** \brief FUNCION PROYECTOS POR PROGRAMADOR
 *
 * \param eProgramador Utiliza la estructura con la informacion de los programadores
 * \param tamProg El tamaño que se le haya asignado al array
 * \param eProyectoProgramador Utiliza la estructura relacional
 * \param tamPP El tamaño que se le haya asignado al array
 * \param eProyecto Utiliza la estructura con la informacion de los proyectos
 * \param tamProye El tamaño que se le haya asignado al array
 * \return void
 *
 */

void mostrarProyectosPorProgramador(eProgramador programador[], int tamProg, eProyectoProgramador proyectoProgramador[], int tamPP, eProyecto proyecto[], int tamProye)
{
    int i, j, k, l;
	int contadorCantidadProgramadores=0;
	int contadorProyectos=0;
	int auxIDProgramador;

	for(i=0;i<tamProye;i++)
	{
		if(proyecto[i].idProyecto!=-1)
		{
			contadorProyectos++;
		}
	}

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
	}

	printf("Ingrese el id del programador a consultar:  ");
	fflush(stdin);
	scanf("%d", &auxIDProgramador);
	for(i=0;i<tamPP;i++)
	{
		if(auxIDProgramador==proyectoProgramador[i].idProgramador)
		{
			printf("\n\nID PROYECTO:\n\n%d ", proyectoProgramador[i].idProyecto);
			for(j=0;j<contadorProyectos;j++)
			{
				if(proyectoProgramador[i].idProyecto==proyecto[j].idProyecto)
				{
					printf("\n\nNOMBRE PROYECTO:\n\n%s ", proyecto[j].nombre);
				}
			}
		}
	}
}

/** \brief FUNCION PROYECTO MAS DEMANDANTE
 *
 * \param eProyectoProgramador Utiliza la estructura relacional
 * \param tamPP El tamaño que se le haya asignado al array
 * \param eProyecto Utiliza la estructura con la informacion de los proyectos
 * \param tamProye El tamaño que se le haya asignado al array
 * \param eProyectoMasDemandante Utiliza una estructura auxiliar con la informacion de los id de proyectos y contador
 * \param tamPMD El tamaño que se le haya dado al array
 * \return void
 *
 */

void saberPoyectoMasDemandante(eProyectoProgramador proyectoProgramador[], int tamPP, eProyecto proyecto[], int tamProye, eProyectoMasDemandante proyectoMasDemandante[], int tamPMD)
{
    int i, j, k, max;

    for(i=0;i<tamPMD;i++)
    {
        proyectoMasDemandante[i].idProyecto=proyecto[i].idProyecto;
        proyectoMasDemandante[i].contadorVecesProyecto=0;
    }

    for(i=0;i<tamPMD;i++)
    {
        for(j=0;j<tamPP;j++)
        {
            if(proyectoMasDemandante[i].idProyecto==proyectoProgramador[j].idProyecto)
            {
                proyectoMasDemandante[i].contadorVecesProyecto++;
            }
        }
    }

    for(i=0; i<tamPMD;i++)
    {
         if(i==0)
        {
            max=proyectoMasDemandante[i].contadorVecesProyecto;
        }
        else
        {
            if(proyectoMasDemandante[i].contadorVecesProyecto>max)
            {
                max=proyectoMasDemandante[i].contadorVecesProyecto;
            }

        }
    }

    for(i=0; i<tamPMD; i++)
    {
        if(proyectoMasDemandante[i].contadorVecesProyecto==max)
        {
            for(k=0;k<tamProye;k++)
            {
                if(proyecto[k].idProyecto==proyectoMasDemandante[i].idProyecto)
                {
                    printf("%s\n", proyecto[k].nombre);

                }
            }
        }
    }
}

/** \brief FUNCION MOSTRAR PROYECTOS Y VALOR
 *
 * \param eProyectoProgramador Utiliza la estructura relacional
 * \param tamPP El tamaño que se le haya asignado al array
 * \param eProyecto Utiliza la estructura con la informacion de los proyectos
 * \param tamProye El tamaño que se le haya asignado al array
 * \param eCategoria Utiliza la estructura con la informacion de las categorias
 * \param tamCat El tamaño que se le haya asignado al array
 * \return void
 *
 */

 void mostrarProyectosValor(eProgramador programador[], int tamProg, eProyectoProgramador proyectoProgramador[], int tamPP, eProyecto proyecto[], int tamProye, eCategoria categoria[], int tamCat)
{
    int i, j, k;
	int contadorJunior=0;
	int contadorSemiSenior=0;
	int contadorSenior=0;
	int auxiliarValorHJunior;
	int auxiliarValorHSemiSenior;
	int auxiliarValorHSenior;
	int valorJunior=0;
	int valorSemiSenior=0;
	int valorSenior=0;
	int valorTotalProyecto=0;



	for(i=0;i<tamCat;i++)
	{
		if(categoria[i].idCategoria==1)
		{
			auxiliarValorHJunior=categoria[i].pagoXHora;
		}
		if(categoria[i].idCategoria==2)
		{
			auxiliarValorHSemiSenior=categoria[i].pagoXHora;
		}
		if(categoria[i].idCategoria==3)
		{
			auxiliarValorHSenior=categoria[i].pagoXHora;
		}
	}


    for(j=0;j<tamProye;j++)
    {
        for(i=0;i<tamPP;i++)
        {
            if(proyectoProgramador[i].idProyecto==proyecto[j].idProyecto && proyectoProgramador[i].estado!=-1 && proyecto[j].estado!=-1)
            {
                for(k=0;k<tamProg;k++)
                {
                    if(programador[k].idProgramador==proyectoProgramador[i].idProgramador && programador[k].estado!=-1)
                    {
                        if(programador[k].idCategoria==1 && proyectoProgramador[i].horasATrabajar>0)
                        {
                            valorJunior=(auxiliarValorHJunior*proyectoProgramador[i].horasATrabajar);
                        }
                        if(programador[k].idCategoria==2 && proyectoProgramador[i].horasATrabajar>0)
                        {
                            valorSemiSenior=(auxiliarValorHSemiSenior*proyectoProgramador[i].horasATrabajar);
                        }
                        if(programador[k].idCategoria==3&& proyectoProgramador[i].horasATrabajar>0)
                        {
                            valorSenior=(auxiliarValorHSenior*proyectoProgramador[i].horasATrabajar);
                        }
                        printf("%d\n", valorJunior);
                        printf("%d\n", valorSemiSenior);
                        printf("%d\n", valorSenior);

                        if(proyectoProgramador[i].idProyecto==proyecto[j].idProyecto && proyectoProgramador[i].estado!=-1 && proyecto[j].estado!=-1 && programador[k].idProgramador==proyectoProgramador[i].idProgramador && programador[k].estado!=-1)
                        {
                            printf("\n\-------------------------:\n\n");
                            printf("\n\nID PROYECTO:\n\n%d ", proyecto[j].idProyecto);
                            printf("\n\nNOMBRE PROYECTO:\n\n%s ", proyecto[j].nombre);
                            valorTotalProyecto=valorJunior+valorSemiSenior+valorSenior;
                            printf("\n\nVALOR PROYECTO:\n\n%d ", valorTotalProyecto);
                        }

                    }


                }

            }
        }

    }

}
