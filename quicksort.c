#include <stdio.h>
#include <stdlib.h>


long long int *cria_vetor(long long int n);
void mostrar_vetor(long long int *vet, long long int tam);
void quicksort(long long int * vet, long long int inicio, long long int fim);


int main()
{
    long long int *vet;
    long long int tam;

    for (tam = 100; tam <= 500; tam = tam + 100)
    {
        printf("\n Tamanho do vetor: %lld",tam);
        vet = cria_vetor(tam);
        printf("\nVetor desordenado: ");
        mostrar_vetor(vet, tam);
        quicksort(vet,0,tam-1);
        printf("\n Vetor Ordenado: ");
        mostrar_vetor(vet, tam);
        free(vet);
    }

    printf("\n");
    return 0;
}

long long int *cria_vetor(long long int n)
{
    long long int *vet, i, sorteio, aux;

    vet = (long long int *)calloc(n, sizeof(long long int));

    for (i = 0; i < n; i++)
    {
        vet[i] = i + 1;
    }

    for (i = 0; i < n; i++)
    {
        sorteio = rand() % n;
        aux = vet[i];
        vet[i] = vet[sorteio];
        vet[sorteio] = aux;
    }
    return vet;
}

void mostrar_vetor(long long int *vet, long long int tam)
{
    long long int i;
    printf("\nVetor: ");
    for (i = 0; i < tam; i++)
    {
        printf(" %lld", vet[i]);
    }
}

void quicksort(long long int * vet, long long int inicio, long long int fim)
{
    long long int pivo,aux,aux_troca;

    if (inicio>=fim)
    {
        return;
    }

    pivo = inicio;
    aux = fim;

    while(pivo!=aux)
    {
        if (pivo<aux)
        {
            if (vet[pivo]>vet[aux])
            {
                aux_troca = vet[pivo];
                vet[pivo] = vet[aux];
                vet[aux] = aux_troca;
                aux_troca = pivo;
                pivo = aux;
                aux = aux_troca;
            }
        }
        else
        {
            if (vet[pivo]<vet[aux])
            {
                aux_troca = vet[pivo];
                vet[pivo] = vet[aux];
                vet[aux] = aux_troca;
                aux_troca = pivo;
                pivo = aux;
                aux = aux_troca;
            }

        }
        if (pivo<aux)
        {
            aux--;
        }
        else
        {
            aux++;
        }
    }

    quicksort(vet,inicio,pivo-1);
    quicksort(vet,pivo+1,fim);
}