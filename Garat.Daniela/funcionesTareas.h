#ifndef FUNCIONESTAREAS_H_INCLUDED
#define FUNCIONESTAREAS_H_INCLUDED

typedef struct
{
    char descripcion[50];
    int prioridad;
    int tiempoDemora;
}Tarea;

Tarea* newTarea(char descripcion[50], int prioridad, int tiempoDemora);

void cargarTareasGenerales(ArrayList* tareasGenerales);

void cargartareasPAlta(ArrayList* tareasPAlta);

void cargartareasPBaja(ArrayList* tareasPBaja);

int comparaTareas(void* pTareaA,void* pTareaB);

void resuelveEnOrdenAltas(ArrayList* tareasPAlta);

void resuelveEnOrdenBajas(ArrayList* tareasPBaja);
#endif // FUNCIONESTAREAS_H_INCLUDED
