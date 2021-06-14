#include <stdio.h>
#include<stdlib.h>
#include <time.h>


long long int *gera_vetor(long long int n);
void printa_vetor( long long int *vet,  long long int t);
long long int busca_binaria(long long int *vet,long long int fim, long long int X,long long int inicio);



void main()
{
  long long int N,X,*vet;
  printf("\ninforme o tamanho do vetor: ");
  scanf("%lld",&N);
  vet = gera_vetor(N);
  printa_vetor(vet,N);
  printf("\ninforme o numero a ser procurado: ");
  scanf("%lld",&X);
  busca_binaria(vet,N,X,0);
  
    
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

long long int *gera_vetor(long long int n)
{
    long long int *vet, aleatorio,aux;

    vet = (long long int *)calloc(n, sizeof(long long int));

    for (long long int i = 0; i < n; i++)
    {
        vet[i] = i + 1;
    }

    
    return vet;
}

long long int busca_binaria(long long int *vet,long long int fim, long long int X,long long int inicio)
{
  long long int meio = (fim+inicio)/2;

  while (inicio <= fim) {
  if (vet[meio] < X){
    inicio = meio + 1;
  }
  else if (vet[meio] == X) {
    printf("o numero %d foi achado no vetor.\n", X);
    break;
  }
  else{
    fim = meio - 1;
  }
  meio = (inicio + fim)/2;
  }
  if (inicio > fim)
  printf("o numero %d nao foi achado no vetor.\n", X);

}
