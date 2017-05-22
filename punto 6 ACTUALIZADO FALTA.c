void mostrarProyectos(eProgramador programador[], int tamProg, eCategoria categoria[], int tamCat, eProyectoProgramador proyectoProgramador[], int tamPP, eProyecto proyecto[], int tamProye)
{
    int i, j, k, l;
	int contadorCantidadProgramadores=0;
	int contadorProyectos=0;
	int contadorEstadoPP=0;

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

	for(i=0;i<tamPP;i++)
    {
        if(proyectoProgramador[i].estado!=-1)
		{
			contadorEstadoPP++;
		}
    }

 
	for(i=0;i<contadorEstadoPP;i++)
	{
		for(j=0;j<contadorProyectos;j++)
		{
			if(proyectoProgramador[i].idProyecto==proyecto[j].idProyecto)
			{
				for(k=0;k<contadorCantidadProgramadores;k++)
				{
					if(programador[k].idProgramador==proyectoProgramador[i].idProgramador)
					{
						if(programador[k].categoria==1)
						{
							contadorJunior++;
						}
						if(programador[k]==2)
						{
							contadorSemiSenior++;
						}
						if(programador[k].categoria==3)
						{
							contadorSenior++;
						}
					}
				}
			}
			totalProgramadores=contadorJunior+contadorSemiSenior+contadorSenior;
		}
	}
	
}