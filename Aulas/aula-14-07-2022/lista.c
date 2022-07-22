#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int n;
    struct Node * next;
} Node;

typedef struct Lista {
    Node *primeiro;
} Lista;

Node * novaLista();
void adicionaLista(Node * lista, int value);
void imprimeLista(Node * lista);
void liberaLista(Node * lista);
void removeLista(Node * lista, int value);

int main(void) {
    Node * lista;

    lista = novaLista();

    adicionaLista(lista, 1);
    adicionaLista(lista, 2);
    adicionaLista(lista, 3);
    adicionaLista(lista, 4);
    imprimeLista(lista);

    removeLista(lista, 3);
    removeLista(lista, 5);
    imprimeLista(lista);

    liberaLista(lista);

    return 0;
}

Node * novaLista() {
    Node * p = NULL;

    p = (Node *) malloc(sizeof(Node));
    if(p == NULL) {
        printf("Erro em malloc, função novaLista\n");
        exit(0);
    }
    p->n = 0;
    p->next = NULL;

    return p;
}

void adicionaLista(Node * lista, int value) {
    Node * p = NULL;
    Node * tmp = NULL;

    p = lista;
    while (true) {
        if(p->next == NULL) {
            tmp = (Node *) malloc(sizeof(Node));
            tmp->n = value;
            tmp->next = NULL;
            p->next = tmp;
            break;
        }
        p = p->next;
    }
}

void imprimeLista(Node * lista) {
    Node * p = NULL;

    for(p = lista->next; p->next != NULL; p = p->next) {
        printf("%d ", p->n);
    }
    printf("%d\n", p->n);
}

void liberaLista(Node * lista) {
    Node * p = NULL;
    Node * tmp = NULL;

    for(p = lista; p->next != NULL; p = tmp) {
        tmp = p->next;
        free(p);
    }
    free(p);

    lista = NULL;
}

void removeLista(Node * lista, int value) {
    Node * p = NULL;
    Node * tmp_p = NULL;
    Node * tmp_n = NULL;

    for(p = lista->next; p->next != NULL; tmp_p = p, p = p->next) {
        if(p->n == value) {
            tmp_n = p->next;
            free(p);
            tmp_p->next = tmp_n;
            break;
        }
    }
}