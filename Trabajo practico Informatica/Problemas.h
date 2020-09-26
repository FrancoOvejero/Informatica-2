#ifndef PROBLEMAS_H_INCLUDED
#define PROBLEMAS_H_INCLUDED

char * getKey(char *key);
void waitFor (unsigned int secs);
int opcion();
void semaforo(int opcion, int t_espera, int t_cambio);
int lectura(char esperaOcambio[]);

#endif
