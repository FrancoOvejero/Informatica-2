#include <stdio.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <windows.h>
#include "Problemas.h"


int main(int argc, char const *argv[])
{
    char cambio_gir;
    int t_espera = lectura("espera");
    int t_cambio = lectura("cambio");
    printf("El tiempo seteado del semaforo principal es: %d\n",t_espera);
    printf("El tiempo seteado de la luz de giro a la izquierda es: %d\n\n",t_cambio);

    cambio_gir = opcion();


    while(cambio_gir!=2){

    semaforo(cambio_gir,t_espera,t_cambio);
    cambio_gir = opcion();

    }

    system("cls");
    system("PAUSE");
    return 0;
}



