#define ANCHO_PANTA 68
#define LARGO_NAME 50	
/*******************************
FUNCIONES DE VISUALIZACION
*******************************/
/** \brief Imprime el menu principal
 *
 * \return void
 *
 */
void imprimoMenu()
{
        imprimirTitulo("MENU");
        printf("1- AGREGAR PERSONA\n");
        printf("2- BORRAR PERSONA\n");
        printf("3- IMPRIMIR LISTA ORDENADA POR NOMBRE\n");
        printf("4- IMPRIMIR GRAFICO DE EDADES\n");
        printf("5- SALIR\n\n");
        printf("ELECCION: ");

}

/** \brief Imprime un mensaje de informacion
 *
 * \param message[] char Mensaje a mostrar
 * \return void
 *
 */
void infoMessage(char message[])
{
    printf("\nInfo ===> %s\n", message);
}


/** \brief Imprime un Titulo con formato
 *
 * \param titulo[] char titulo a mostrar
 * \return void
 *
 */
void imprimirTitulo(char titulo[])
{

        int i, largo, mitadPalabra, mitadPantalla;

        largo = strlen(titulo);
        mitadPalabra = largo / 2 + 1; //Como meto la division en entero me queda solo la parte entera
        mitadPantalla = ANCHO_PANTA / 2;

        system("cls");
        for(i=0;i<ANCHO_PANTA;i++) printf("*");
        printf("\n");
        printf("*");
        for(i=0;i<mitadPantalla-mitadPalabra;i++) printf(" ");
        printf("%s",titulo);
        for(i=0;i<mitadPantalla-mitadPalabra;i++) printf(" ");
        printf("*");
        printf("\n");
        for(i=0;i<ANCHO_PANTA;i++) printf("*");
        printf("\n");


}