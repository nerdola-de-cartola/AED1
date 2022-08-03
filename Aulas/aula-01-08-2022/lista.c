#include "lista.h"

List newList() {
    List p;

    p.first = NULL;
    p.last = NULL;
    p.size = 0;

    return p;
}

void printList(List *l, int ordem) {
    Node *p = NULL;

    if(ordem == CRESCENTE) {
        for(p = l->first; p != NULL; p = p->next) {
            printf("%d ", p->n);
        }
    } else if(ordem == DECRESCENTE) {
        for(p = l->last; p != NULL; p = p->prev) {
            printf("%d ", p->n);
        }
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

        if(value <= p->n) {
            new->prev = p->prev;
            new->next = p;
            if(p->prev != NULL) p->prev->next = new;
            p->prev = new;
            if(new->prev == NULL) l->first = new;
            if(new->next == NULL) l->last = new;
            break;
        }

        if(p == l->last) {
            p->next = new;
            new->prev = p;
            new->next = NULL;
            l->last = new;
            break;
        }

    }
    
    l->size++;
}

bool removeList(List *l, int value) {
    Node * p = NULL;

    for(p = l->first; p != NULL; p = p->next) {
        if(p->n == value) {
            p->prev->next = p->next;
            p->next->prev = p->prev;
            free(p);
            l->size--;
            return true;
        }
    }

    return false;
}

void freeList(List *l) {
    Node * p = NULL;
    Node * tmp = NULL;

    for(p = l->first; p != NULL; p = tmp) {
        tmp = p->next;
        free(p);
    }

    l->first = NULL;
    l->last = NULL;
    l->size = 0;
}

void error(const char *function_name) {
    printf("Erro na função %s\n", function_name);
    exit(0);
}

bool searchList(List *l, int value) {
    Node * p = NULL;

    for(p = l->first; p != NULL; p = p->next) {
        if(p->n == value) return true;
    }

    return false;
}

List sumList(List *l1, List *l2) {
    List s;
    Node *p = NULL;

    s = newList();
    copyList(&s, l1);
    
    for(p = l2->first; p != NULL; p = p->next) {
        insertList(&s, p->n);
    }

    return s;
}

void copyList(List *dest, List *source) {
    Node *p = NULL;
    if(dest->size != 0) freeList(dest);

    for(p = source->first; p != NULL; p = p->next) {
        insertList(dest, p->n);
    }
}