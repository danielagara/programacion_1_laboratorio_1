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
}eProyectoProgramador;

typedef struct
{
    int idProyecto;
    int contadorProyectoDemandante;
}eAUXProyectoMasDemandante;

void inicializarEstado(eProgramador[], int);
void definirCategorias(eCategoria[], int);
void altaDeprogramador(eProgramador [], int , eCategoria[], int);
void modificarUsuario(eProgramador[], int );
void bajaDeProgramador(eProgramador[], int);
void asignarProgramadorAProyecto(eProgramador[], int, eProyecto[], int, eProyectoProgramador[], int );
void mostrarProgramadores(eProgramador[], int, eCategoria[], int, eProyectoProgramador[], int, eProyecto[], int);

#endif // LIB_H_INCLUDED
