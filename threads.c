#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "common_threads.h"
#include "mycommon.h"
#include <time.h>
#include <sys/time.h>

volatile int counter = 0 ;//esta es la shared?
puerta puertaP;
int loops;
struct timeval start, stop;
double secs = 0;

void *worker(void *arg) {
    int i;
    //cerrar_puerta(puertaP);
    for (i = 0; i < loops; i++) {
	cerrar_puerta(puertaP);
	counter++;
	abrir_puerta(puertaP);
    }
    //abrir_puerta(puertaP);
    return NULL;
}

int main(int argc, char *argv[]) {
    gettimeofday(&start, NULL);
    if (argc != 2) {
	fprintf(stderr, "usage: threads <loops>\n");
	exit(1);
    }
    crear_puerta(puertaP);
    loops = atoi(argv[1]);
    pthread_t p1, p2;
    printf("Initial value : %d\n", counter);
    Pthread_create(&p1, NULL, worker, NULL);
    Pthread_create(&p2, NULL, worker, NULL);
    Pthread_join(p1, NULL);
    Pthread_join(p2, NULL);
    printf("Final value   : %d\n", counter);
    destruir_puerta(puertaP);
    gettimeofday(&stop, NULL);
    secs = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
    printf("time taken %f\n ms", secs);
    return 0;
}
