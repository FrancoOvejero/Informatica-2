#ifndef PROBLEMAS_H_INCLUDED
#define PROBLEMAS_H_INCLUDED

typedef enum {
  semaforo1 = 0,
  luzGiro1 = 1,
  esperaRojo = 2,
}posibilidades_t;

typedef struct {
  char t;         // tiempo actual
  char espera;     // tiempo de espera
  char cambio;    // tiempo de giro
  int gir;
}tiempo_t;

int f_giro(tiempo_t *temp);
int f_semaforonormal(tiempo_t *temp);
int f_paro(tiempo_t *temp);
char * getKey(char *key);
int lectura(char esperaOcambio[]);
void tiempo(int auxi);
#endif
