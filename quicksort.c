#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long int *gera_vetor(long long int n);
void printa_vetor( long long int *vet,  long long int t);
void quicksort(long long int *vet, long long int inicio, long long int fim);

int main()
{
    long long int *vet;
    long long int tam;
    srand(time(NULL));
    double tempo_gasto;
    FILE * arq;
    arq = fopen("tempos_quicksort.csv","a+");
    if ( arq==NULL){
        return 0;
    }
    for (tam = 10000; tam <= 1100000; tam = tam+100000 ){

        printf("\n Tamanho do vetor: %lld",tam);
        vet = gera_vetor(tam);
        clock_t begin = clock();
        quicksort(vet,0,tam-1);
        clock_t end = clock();
        tempo_gasto = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("\n Tempo para ordenar: %f",tempo_gasto);
        fprintf(arq,"%lld;%f\n",tam,tempo_gasto);
        free(vet);

    }

    
    fclose(arq);

    printf("\n");
    return 0;
}

long long int *gera_vetor(long long int n)
{
    long long int *vet, aleatorio,aux;

    vet = (long long int *)calloc(n, sizeof(long long int));

    for (long long int i = 0; i < n; i++)
    {
        vet[i] = i + 1;
    }

    for (long long int i = 0; i < n; i++)
    {
        aleatorio = rand() % n;
        aux = vet[i];
        vet[i] = vet[aleatorio];
        vet[aleatorio] = aux;
    }
    return vet;
}
void printa_vetor( long long int *vet,  long long int t)
{
    long long int i;
    printf("\nVetor: ");
    for (i = 0; i < t; i++)
    {
        printf(" %lld", vet[i]);
    }
}

void quicksort(long long int *vet, long long int inicio, long long int fim) {
    long long int i, j, pivo, y;
     
    i = inicio;
    j = fim;
    pivo = vet[(inicio + fim) / 2];
     
    while(i <= j) {
        while(vet[i] < pivo && i < fim) {
            i++;
        }
        while(vet[j] > pivo && j > inicio) { 
            j--;
        }
        if(i <= j) {
            y = vet[i];
            vet[i] = vet[j];
            vet[j] = y;
            i++;
            j--;
        }
    }
     
    if(j > inicio) {
        quicksort(vet, inicio, j);
    }
    if(i < fim) {
        quicksort(vet, i, fim);
    }
}