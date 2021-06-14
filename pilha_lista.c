#include <stdio.h>
#include <stdlib.h>

/*
2) Construa uma pilha utilizando uma lista ligada.
Obs. Implemente as operações Push, pop, stackpop e empty.
*/

typedef struct stack
{
    int total;
    struct node *tos;
    struct node *header;
}stack;

typedef struct node
{
    int content;
    struct node *next;
}node;

stack *allocate_stack();
node *allocate_node();

void push(stack *stack1, int x);
void pop(stack *stack1);
void stackpop(stack *stack1);
int empty(stack *stack1);

int main()
{
    stack *stack1;
    stack1 = allocate_stack();

    int input = 0;
    int x = 0;

    while(input != 5)
    {
        printf("\n[1] - push");
        //Push adiciona elemento no topo da pilha

        printf("\n[2] - pop");
        //Pop remove elemento no topo da pilha

        printf("\n[3] - stackpop");
        //stackpop retorna o valor no topo da pilha (mas não o remove)

        printf("\n[4] - empty");
        //Fala se a pilha está vazia ou não
        
        printf("\n[5] - Fim\n");
        
        scanf("%d", &input);

        switch (input)
        {
        case 1:
            printf("Numero a ser adicionado: ");
            scanf("%d", &x);
            push(stack1, x);
            break;

        case 2:
            pop(stack1);
            break;

        case 3:
            stackpop(stack1);
            break;

        case 4:
            if(empty(stack1))
            {
                printf("\nVazia");
            }
            else
            {
                printf("\nNao vazia");
            }
            break;

        case 5:
            break;

        default:
            printf("\nOpcao invalida");
            break;
        }
    }

    printf("\n");

    return 0;
}

stack *allocate_stack()
{
    stack *new_stack;
    new_stack = (stack*)malloc(sizeof(stack));

    new_stack->tos = NULL;
    new_stack->header = NULL;
    new_stack->total = 0;

    return new_stack;
}

node *allocate_node()
{
    node *new_node;
    new_node = (node*)malloc(sizeof(node));

    new_node->content = 0;
    new_node->next = NULL;

    return new_node;
}

void push(stack *stack1, int x)
{
    node *new_node;
    new_node = allocate_node();
    new_node->content = x;

    if (stack1->header == NULL)
    {
        stack1->header = new_node;
        stack1->tos = new_node;   
        stack1->total++;
    }
    else
    {
        node *aux;
        aux = stack1->tos;
        
        aux->next = new_node;
        stack1->tos = new_node;
        stack1->total++;
    }
}

void pop(stack *stack1)
{
    if(stack1->header == NULL)
    {
        printf("\nPilha vazia");
    }
    else
    {
        node *aux, *ant;
        ant = NULL;
        aux = stack1->header;

        while(aux->next != NULL)
        {
            ant = aux;
            aux = aux->next;
        }

        if(ant == NULL)
        {
            stack1->tos = NULL;
            stack1->header = NULL;
            free(aux);
        }
        else
        {
            stack1->tos = ant;
            ant->next = NULL;
        }
    }
}

void stackpop(stack *stack1)
{
    if(stack1->header == NULL)
    {
        printf("\nPilha vazia");
    }
    else
    {
        node *aux;
        aux = stack1->tos;

        printf("\n>>> %d <<<", aux->content);
    }
}

int empty(stack *stack1)
{
    if(stack1->header == NULL)
    {
        return 1;
    }

    return 0;
}