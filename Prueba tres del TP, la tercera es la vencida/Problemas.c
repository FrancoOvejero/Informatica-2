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

int f_semaforonormal(tiempo_t *temp)
{
    printf("----------------------------------\nEl semaforo empezo a cambiar entre colores durante %d segundos \n",temp->espera);
    tiempo(temp->espera);
    return 1;

}

int f_giro(tiempo_t *temp)
{
    printf("El semaforo habilito la luz de giro a la izquierda durante %d segundos \n", temp->cambio);
    tiempo(temp->cambio);
    if(temp->gir==1){
    temp->gir=0;
    return 0;
    }
    return 2;

}

int f_paro(tiempo_t *temp){
    temp->gir=1;
    printf("Esta circulando el otro semaforo, el principal esta en rojo,en %d segundos se habilitara la luz de giro\n", temp->espera);
    tiempo(temp->espera);
    return 1;
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
