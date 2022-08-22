#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int n;
    struct Node * next;
} Node;

typedef struct List {
    Node *first;
    Node *last;
    int size;
} List;

List newList() {
    List p;

    p.first = NULL;
    p.last = NULL;
    p.size = 0;

    return p;
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

bool push(List *l, int n) {
    Node *new = NULL;

    new = (Node *) malloc(sizeof(Node));
    if(new == NULL) error("push");

    new->n = n;
    new->next = NULL;

    if(l->first == NULL) l->first = new;
    else l->last->next = new;
    
    l->last = new;
    l->size++;

    return true;
}

bool removeList(List *l, int n) {
    Node * p = NULL;
    Node * prev = NULL;

    for(p = l->first; p != NULL; prev = p, p = p->next) {
        if(p->n == n) {
            if(l->size == 1) {
                l->first = NULL;
                l->last = NULL;
            } else if(p == l->first) {
                l->first = p->next;
            } else if(p == l->last) {
                l->last = prev;
                l->last->next = NULL;
            } else {
                prev->next = p->next;
            } 


            free(p);
            return true;
        }
    }

    return false;
}

void printList(List *l) {
    Node *p = NULL;

    for(p = l->first; p != NULL; p = p->next) {
        printf("%d ", p->n);
    }
    printf("\n");    
}

int main(void) {
    int input, n;
    List queue = newList();

    scanf("%d", &input);

    while(input--) {
        scanf("%d", &n);
        push(&queue, n);
    }

    scanf("%d", &input);

    while(input--) {
        scanf("%d", &n);
        removeList(&queue, n);
    }

    printList(&queue);
    freeList(&queue);

    return 0;
}