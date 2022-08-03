#include "lista.h"

List newList() {
    List p;

    p.first = NULL;
    p.last = NULL;
    p.size = 0;

    return p;
}

void printList(List *l) {
    Node *p = NULL;

    for(p = l->first; p != NULL; p = p->next) {
        printf("%d ", p->n);
    }
    printf("\n");
}
void insertList(List *l, int value) {
    Node *new = NULL;
    Node *p = NULL;

    new = (Node *) malloc(sizeof(Node));
    if(new == NULL) error("insertList");
    new->n = value;

    for(p = l->first; true; p = p->next) {
        if(l->size == 0) {
            l->first = new;
            l->last = new;
            new->next = NULL;
            new->prev = NULL;
            break;
        } 

        if(p == l->last) {
            p->next = new;
            new->prev = p;
            new->next = NULL;
            l->last = new;
            break;
        }

        if(value <= p->n) {
            new->prev = p->prev;
            new->next = p;
            p->prev = new;
            if(new->prev == NULL) l->first = new;
            if(new->next == NULL) l->last = new;
            break;
        }
    }
    
    l->size++;
}

/*


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
*/

void error(const char *function_name) {
    printf("Erro na função %s\n", function_name);
    exit(0);
}