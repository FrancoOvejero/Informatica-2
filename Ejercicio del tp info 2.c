#include <stdio.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <windows.h>
#include "Problemas.c"


int main(int argc, char const *argv[])
{
    char cambio_gir;
FILE *config;//Lectura del archivo de configuraciones
config = fopen("config.txt", "r");

if(config==NULL)//Error por si el archivo no existe
{   printf("Mira capo que las configuraciones no estan :7");
    system("PAUSE");
    return 1;
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
printf("El tiempo seteado del semaforo principal es: %d\n",t_espera);
printf("El tiempo seteado de la luz de giro a la izquierda es: %d\n\n",t_cambio);
fclose(config);

cambio_gir=opcion();


while(cambio_gir!=2){

semaforo(cambio_gir,t_espera,t_cambio);
printf("Si quiere volver iniciar normalmente pulse 0, \nSi quiere iniciar solamente la luz de giro pulse 1, \nPara finalizar  pulse 2\n\n");
       scanf("%d",&cambio_gir);

}
return 0;
}



