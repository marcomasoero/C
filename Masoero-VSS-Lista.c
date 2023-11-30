#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int valore;
    struct node* next;   
}Node;

int calcolaLunghezza(Node* lista){
    Node* l = lista;
    int lung = 0;
    while (l != NULL)
    {
        lung++;
        l = l->next;
    }
    return lung; 
}

int ricorsivaLunghezza(Node* lista, int lung){
    Node* l = lista;
    if(l != NULL){
        lung++;
        lung = ricorsivaLunghezza(l->next, lung);
    }
    return lung;
}

void stampaLista(Node* lista){
    Node* l = lista;
    while (l != NULL)
    {
        printf("%d ", l->valore);
        l = l ->next;
    }
}

void stampaListaRicorsiva(Node* lista){
    Node* l = lista;
    if(l != NULL){
        printf("%d ", l->valore);
        stampaListaRicorsiva(l->next);
    }
}

int main(){
    int n;
    int lung = 0;
    Node* lista = NULL;
    Node* l;

    do{
        printf("Inserire un numero naturale o -1 per terminare: ");
        scanf("%d", &n);
        if(n >= 0){
            if(lista == NULL){
                lista = (Node*) malloc(sizeof(Node));
                l = lista;
            } else {
                l->next = (Node*) malloc(sizeof(Node));
                l = l->next;
            }
            l->valore = n;
            l->next = NULL;
        }
    } while (n >= 0);

    l = lista;
    printf("\nNumeri inseriti:\n");

    while (l != NULL)
    {
        printf("%d - %p \n", l->valore, l->next);
        l = l->next;
    }

    printf("\nNumero di elementi: %d", calcolaLunghezza(lista));
    printf("\nNumero di elementi con ricorsiva: %d", ricorsivaLunghezza(lista, lung));

    printf("\nNumero di elementi:");
    stampaLista(lista);
    printf("\nNumero di elementi con ricorsiva:");
    stampaListaRicorsiva(lista);

    return 0;
}

/*
Per aggiungere un elemento all'inizio:

Node* head;
head = (Node*)malloc(sizeof(Node));
head->next = *lista;
head->valore = num;
*lista = head;
*/

/*
Per aggiungere un elemento alla fine:

Node *l = *lista;
while(l->next != NULL){
    l = l->next;
}
l->next = (Node*)malloc(sizeof(Node));
l = l->next;
l->valore = num;
l->next = NULL;
*/

/*
Per rimuovere l'ultimo elemento:

Node *l = *lista;
Node *l2 = l;
while(l->next != NULL){
    l2 = 1;
    l = l->next;
}
l2->next = NULL;
*/
