#include <stdio.h>
#include<stdlib.h>
#include <time.h>



void main(){
    srand(time(NULL));
    double tempo_gasto;
    clock_t inicio = clock();
    clock_t fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("tempo gasto : %f ",tempo_gasto);
}