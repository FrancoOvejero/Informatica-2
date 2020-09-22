#include <stdio.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <windows.h>
#include "Problemas.h"

enum PosiblesEstados {
    normal,
    giro,
};

void waitFor (unsigned int secs)
{
    unsigned int retTime = time(0) + secs;   // Get finishing time.
    while (time(0) < retTime);   // Loop until it arrives.

}

char * getKey(char *key)
{
char i=0;
while(*(key+i)!= ' '){
    i++;
}
*(key+i)=0;
return key+i+1;
}

int opcion(){
char cambio_gir;
printf("Si se quiere iniciar normalmente pulse 0, \nSi quiere iniciar solamente la luz de giro pulse 1, \nPara finalizar el programa pulse 2\n");
    scanf("%d",&cambio_gir);
    return cambio_gir;
}

void semaforo(int opcion, int t_espera, int t_cambio){
int luzgiro;
switch(opcion)//Los dos posibles casos del semaforo más el fin del programa
{
    case normal:
    printf("----------------------------------\nEl semaforo empezo a cambiar entre colores durante %d segundos \n",t_espera);
    waitFor(t_espera);//Delay del programa hasta la proxima fase
    printf("El semaforo habilito la luz de giro a la izquierda durante %d segundos \n", t_cambio);
    luzgiro=1;//Se habilita la luz de giro
    waitFor(t_cambio);//Delay del programa hasta la proxima fase
    printf("El semaforo permanecera en rojo mientras el otro carril circula,cuando se lo habilite volvera a circular \n----------------------------------\n");
    luzgiro=0;/*Se deshabilita la luz de giro>*/
    break;


    case giro:


    printf("----------------------------------\nEl semaforo habilito la luz de giro a la izquierda durante %d segundos \n", t_cambio);
    waitFor(t_cambio);//Delay del programa hasta la proxima fase
    printf("Se detuvo la luz de giro y el semaforo sigue en rojo hasta que se lo vuelvan a habilitar\n----------------------------------\n");
    luzgiro=0;/*Se deshabilita la luz de giro*/
    break;



    }
}
