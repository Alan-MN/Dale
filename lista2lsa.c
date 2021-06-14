#include<stdio.h>
#include<stdlib.h>

typedef struct lista{
    int qtd;
    struct registro *inicio;
    struct registro *fim;

}lista;

typedef struct registro{
    int valor;
    struct registro *ant;
    struct registro *prox;
}registro;

registro *aloca_registro();
lista *aloca_lista();
void incluir_final(lista *l1, int n);
void mostrar_lista(lista *l1);
void remover(lista *l, int x);
void mostrar_primeiro(lista *l1);
void mostrar_ultimo(lista *l1);




void main(){
    lista *l1;
    l1 = aloca_lista();
    int n = 0, opcao = -1;
    while(opcao != 0){
        printf("\n1 - adicionar no final");
        printf("\n2 - mostrar qtd lista");
        printf("\n3 - mostrar lista completa ");
        printf("\n4 - remover da lista ");
        printf("\n5 - mostrar primeiro ");
        printf("\n6 - mostrar ultimo ");
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
            //TEM Q AJEITAR REMOÇÃO

        }
        if(opcao == 5){
            mostrar_primeiro(l1);
        }
        if(opcao == 6){
            mostrar_ultimo(l1);
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
        //faltou dizer que novo->ant = aux
        novo->ant = aux;
        l1->fim = novo;
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
void mostrar_primeiro(lista *l1){
    if(l1->inicio == NULL){
        printf("lista vazia\n");
    }
    else{
        registro *aux;
        aux = l1->inicio;
        printf("\ninicio da lista: %d ", aux->valor);

    }
}
void mostrar_ultimo(lista *l1){
    if(l1->inicio == NULL){
        printf("lista vazia\n");
    }
    else{
        registro *aux;
        aux = l1->fim;
        printf("\nultimo da lista: %d",aux->valor);
    }
}
void remover(lista *l, int x)
{
    if (l->inicio == NULL)
    {
        printf("\n Lista vazia");
        return;
    }

    registro *aux, *ant;
    aux = l->inicio;

    int removido = 0;

    while(aux != NULL)
    {
        if(aux->valor == x)
        {
            //Caso aux seja o único número da lista
            if(aux->prox == NULL && aux == l->inicio)
            {
                //printf("caso 1");
                l->inicio = NULL;
                free(aux);
                removido = 1;
            }

            //caso aux esteja no meio da lista
            if(aux->prox != NULL && aux->ant != NULL)
            {
                //printf("caso 2");
                ant->prox = aux->prox;
                ant = aux->prox;
                ant->ant = aux->ant;
                free(aux);
                removido = 1;
            }

            //caso aux esteja no final da lista
            if(aux->prox == NULL)
            {
                //printf("caso 3");
                ant->prox = NULL;
                l->fim = ant;
                free(aux);
                removido = 1;
            }

            //caso aux esteja no começo da lista
            if(aux->ant == NULL && aux->prox != NULL)
            {
                //printf("caso 4");
                l->inicio = aux->prox;
                free(aux);
                removido = 1;
            }
        }
        ant = aux;
        aux = aux->prox;
    }

    if(removido)
        printf("\nNumero removido");
    else
        printf("\nNumero não encontrado");
}