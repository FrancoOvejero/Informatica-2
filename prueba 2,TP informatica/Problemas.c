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



char * getKey(char *key){
char i=0;
while(*(key+i)!= ' '){
    i++;
}
*(key+i)=0;
return key+i+1;
}

int opcion(){
int cambio_gir;
char aux[20];
printf("Si se quiere iniciar normalmente escriba: Modo_Normal, \n Si quiere iniciar solamente la luz de giro escriba: Modo_Giro \n Para finalizar el programa escribir :Salir \n");
    gets(aux);
    if (!strcmp(aux,"Modo_Normal"))
    {cambio_gir=0;}
    if (!strcmp(aux,"Modo_Giro"))
    {cambio_gir=1;}
    if (!strcmp(aux,"Salir"))
    {cambio_gir=2;}
    return cambio_gir;
}

int lectura(char esperaOcambio[]){
    FILE *config;
    config = fopen("config.txt", "r");

    if(config==NULL)
    {   printf("Mira capo que las configuraciones no estan :7");
        system("PAUSE");
    }
    char cadena[40], *key, *val;
    char variables[2][20]={"TiempoSemaf", "TiempoGiro"}, i;
    char t_espera, t_cambio;

    fgets(cadena,40,config);
    do{
        key=cadena;
        if((*key) != '#' && strlen(key) >= 0){
            val=getKey(key);
            for(i=0;i<2;i++){
                if(!strcmp(key, variables[i])){
                    switch(i){
                        case 0:t_espera=atoi(val);
                        break;
                        case 1:t_cambio=atoi(val);
                        break;
                            }
                        }
                    }
                }
        fgets(cadena,40,config);
        }while (!feof(config)) ;
        if(strcmp(esperaOcambio, "espera") == 0){
            return t_espera;
        }else if(strcmp(esperaOcambio, "cambio") == 0){
            return t_cambio;
        }else{
            return -1;
        }

    fclose(config);
}

void semaforo(int opcion, int t_espera, int t_cambio){
int luzgiro;
switch(opcion)
{
    case normal:
    printf("----------------------------------\nEl semaforo empezo a cambiar entre colores durante %d segundos \n",t_espera);
    tiempo(t_espera);
    printf("El semaforo habilito la luz de giro a la izquierda durante %d segundos \n", t_cambio);
    luzgiro=1;
    tiempo(t_cambio);
    printf("El semaforo permanecera en rojo mientras el otro carril circula,cuando se lo habilite volvera a circular \n----------------------------------\n");
    luzgiro=0;
    break;


    case giro:


    printf("----------------------------------\nEl semaforo habilito la luz de giro a la izquierda durante %d segundos \n", t_cambio);
    tiempo(t_cambio);
    printf("Se detuvo la luz de giro y el semaforo sigue en rojo hasta que se lo vuelvan a habilitar\n----------------------------------\n");
    luzgiro=0;
    break;



    }

}

void tiempo(int auxi){
    int tfinal;
    double total;
    tfinal=auxi;
    clock_t inicio_t, final_t ;
    inicio_t=clock();
    final_t=clock();
    total=(final_t- inicio_t)/(double)CLOCKS_PER_SEC;

    while(total<tfinal){
        total=(final_t- inicio_t)/(double)CLOCKS_PER_SEC;
        final_t=clock();
    }
}
