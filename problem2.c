#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "common_threads.h"
#include "mycommon.h"

volatile double v;
puerta puertaP;


void *hilo1(void *arg) {
    int y,z;
    y = 350;
    z = 25;
    cerrar_puerta(puertaP);
    sleep(2);
    v = (double)z/y;
    abrir_puerta(puertaP);
    return NULL;
}

void *hilo2(void *arg) {
    int x;
    x = 1250;
    cerrar_puerta(puertaP);
    v = (double)x*v;
    abrir_puerta(puertaP);
    return NULL;
}


int main(int argc, char *argv[]) {
    crear_puerta(puertaP);
    pthread_t p1, p2;
    Pthread_create(&p1, NULL, hilo1, NULL);
    Pthread_create(&p2, NULL, hilo2, NULL);
    Pthread_join(p1, NULL);
    Pthread_join(p2, NULL);
    printf("El resultado de hacer x*(z/y): %f\n", v);
    destruir_puerta(puertaP);
    return 0;
}
