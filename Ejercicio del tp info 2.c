#include <stdio.h>
#include <time.h>
#include <string.h>
#include <windows.h>

int cambio_gir,luzgiro;


char * getKey(char *key);
int main(int argc, char const *argv[])
{
FILE *config;
config = fopen("config.txt", "r");
if(config==NULL)
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
printf("Si se quiere iniciar normalmente pulse 0, \nSi quiere iniciar solamente la luz de giro pulse 1, \nPara finalizar el programa pulse 2\n");
    scanf("%d",&cambio_gir);


while(cambio_gir!=2){
switch(cambio_gir)//Los dos posibles casos del semaforo más el fin del programa
{
    case 0:{
    printf("El semaforo empezo a cambiar entre colores durante %d segundos \n",t_espera);
    sleep(t_espera*350);//Delay del programa hasta la proxima fase(bajado *350 de *1000 )
    printf("El semaforo habilito la luz de giro a la izquierda durante %d segundos \n", t_cambio);
    luzgiro=1;//Se habilita la luz de giro
    sleep(t_cambio*350);//Delay del programa hasta la proxima fase(bajado *350 de *1000 )
    printf("El semaforo permanecera en rojo mientras el otro carril circula,cuando se lo habilite volvera a circular \n");
    luzgiro=0;/*Se deshabilita la luz de giro>*/
    break;
    }

    case 1:{
    printf("El semaforo habilito la luz de giro a la izquierda durante %d segundos \n", t_cambio);
    sleep(t_cambio*350);//Delay del programa hasta la proxima fase(bajado *350 de *1000 )
    printf("Se detuvo la luz de giro y el semaforo sigue en rojo hasta que se lo vuelvan a habilitar\n");
    luzgiro=0;/*Se deshabilita la luz de giro*/
    break;
    }

}
printf("Si quiere volver iniciar normalmente pulse 0, \nSi quiere iniciar solamente la luz de giro pulse 1, \nPara finalizar  pulse 2\n");
       scanf("%d",&cambio_gir);

}
return 0;
}

char * getKey(char *key){
char i=0;
while(*(key+i)!= ' '){
    i++;
}
*(key+i)=0;
return key+i+1;
}
