#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED
typedef struct
{
    int idProgramador;
    char nombre[50];
    char apellido[50];
    int idCategoria;
    int estado;
}eProgramador;

typedef struct
{
    int idCategoria;
    char descripcion[50];
    int pagoXHora;
}eCategoria;

typedef struct
{
    int idProyecto;
    char nombre[50];
    int estado;
}eProyecto;

typedef struct
{
    int idProgramador;
    char nombre[50];
    char apellido[50];
    int idCategoria;
    int estado;
}eAUXProgramador;

typedef struct
{
	int idProyecto;
	int idProgramador;
	int horasATrabajar;
	int estado;
}eProyectoProgramador;

typedef struct
{
    int idProyecto;
    int contadorVecesProyecto;
}eProyectoMasDemandante;

void inicializarEstado(eProgramador[], int);
void inicializarIdProgramador(eProgramador[], int);
void inicializarIdProyecto(eProyecto[], int );
void inicializarEstadoProyecto(eProyecto proyecto[], int tamProye);
void inicializarEstadoProyectoProgramador(eProyectoProgramador[], int);
void definirCategorias(eCategoria[], int);
void altaDeprogramador(eProgramador [], int , eCategoria[], int);
void modificarUsuario(eProgramador[], int );
void bajaDeProgramador(eProgramador[], int, eProyectoProgramador[], int);
void asignarProgramadorAProyecto(eProgramador[], int, eProyecto[], int, eProyectoProgramador[], int );
void mostrarProgramadores(eProgramador[], int, eCategoria[], int, eProyectoProgramador[], int, eProyecto[], int);
void mostrarProyectos(eProgramador[], int, eProyectoProgramador[], int, eProyecto[], int);
void mostrarProyectosPorProgramador(eProgramador[], int, eProyectoProgramador[], int, eProyecto[], int);
void saberPoyectoMasDemandante(eProyectoProgramador[], int, eProyecto[], int, eProyectoMasDemandante[], int);

#endif // LIB_H_INCLUDED
