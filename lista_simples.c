#include<stdio.h>
#include<stdlib.h>

typedef struct lista{
    int qtd;
    struct registro *inicio;

}lista;

typedef struct registro{
    int valor;
    struct registro *prox;
}registro;

registro *aloca_registro();
lista *aloca_lista();
void incluir_final(lista *l1, int n);
void mostrar_lista(lista *l1);
void remover(lista *l, int x);


void main(){
    lista *l1;
    l1 = aloca_lista();
    int n = 0, opcao = -1;
    while(opcao != 0){
        printf("\n1 - adicionar no final");
        printf("\n2 - mostrar qtd lista");
        printf("\n3 - mostrar lista completa ");
        printf("\n4 - remover da lista ");
        printf("\n0 - sair ");
        printf("\n");
        scanf("%d",&opcao);
        if(opcao == 1){
            printf("\ninforme o numero a ser adicionado: ");
            scanf("%d",&n);
            incluir_final(l1,n);
        }
        if(opcao == 2){
            printf("\n qtd elementos na lista: %d",l1->qtd);
        }
        if(opcao == 3){
            mostrar_lista(l1);
        }
        if(opcao == 4){
            printf("informe o numero a ser removido: ");
            scanf("%d",&n);
            remover(l1,n);
        }
    }
}


lista *aloca_lista(){
    lista *l;
    l = (lista *)calloc(1,sizeof(lista));
    return l;
}

registro *aloca_registro(){
    registro *novo_reg;
    novo_reg = (registro*)calloc(1,sizeof(registro));
    return novo_reg;
}
void incluir_final(lista *l1, int n){
    registro *novo,*aux;
    novo = aloca_registro();
    novo->valor = n;
    if(l1->inicio == NULL){
        l1->inicio = novo;
        l1->qtd++;
    }
    else{
        aux = l1->inicio;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = novo;
        l1->qtd++;
    }
}
void mostrar_lista(lista *l1){
    if(l1->inicio == NULL){
        printf("lista vazia\n");
    }
    else{
        registro *aux;
        aux = l1->inicio;
        printf("elementos da lista: ");
        while(aux!=NULL){
            printf("%d ",aux->valor);
            aux = aux->prox;
        }
    }
}
void remover(lista *l, int x)
{
    if (l->inicio == NULL)
    {
        printf("\n Lista vazia");
        return;
    }

    registro *aux = NULL, *ant = NULL;
    aux = l->inicio;

    while (aux != NULL)
    {
        if (aux->valor == x)
        {
            if (ant == NULL)
            {
                l->inicio = aux->prox;
            }
            else
            {
                ant->prox = aux->prox;
            }
            free(aux);
            l->qtd--;
            printf("\n Numero removido");
            return;
        }
        else
        {
            ant = aux;
            aux = aux->prox;
        }
    }

    printf("\n Numero nao esta na lista");
    return;
}