#include <stdio.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <windows.h>
#include "Problemas.h"



int main(int argc, char const *argv[])
{
    tiempo_t temp;
    temp.espera= lectura("espera");
    temp.cambio = lectura("cambio");
    temp.gir=0;
    printf("El tiempo seteado del semaforo principal es: %d\n",temp.espera);
    printf("El tiempo seteado de la luz de giro a la izquierda es: %d\n\n",temp.cambio);

    posibilidades_t estados=semaforo1;

    while(1){
        switch(estados){
            case semaforo1: estados=f_semaforonormal(&temp);
            break;
            case luzGiro1: estados=f_giro(&temp);
            break;
            case esperaRojo: estados=f_paro(&temp);
            break;
        }

    }

    system("cls");
    system("PAUSE");
    return 0;
}



