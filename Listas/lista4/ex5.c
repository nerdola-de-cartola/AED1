#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ERROR -1
#define SUCCESS 1

typedef struct Node {
    char str[21];
    struct Node * next;
} Node;

typedef struct List {
    Node *first;
    Node *last;
    int size;
} List;

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

List newList() {
    List p;

    p.first = NULL;
    p.last = NULL;
    p.size = 0;

    return p;
}

bool stackUp(List *l, char *value) {
    Node *new = NULL;

    new = (Node *) malloc(sizeof(Node));
    if(new == NULL) error("stackUp");
    strcpy(new->str, value);
    new->next = NULL;
    
    if(l->first == NULL) l->first = new;
    if(l->last != NULL) l->last->next = new; 
    l->last = new;
    l->size++;

    return true;
}

int unstack(List *l, char *last) {
    Node *p = NULL;

    if(l->size == 0) return ERROR;

    if(l->size == 1) {
        strcpy(last, l->first->str);
        freeList(l);
        return SUCCESS;
    }

    for(p = l->first; p->next != l->last; p = p->next);

    p->next = NULL;
    strcpy(last, l->last->str);
    free(l->last);
    l->last = p;
    l->size--;

    return SUCCESS;
}

int main(void) {
    List stack;
    char input[21];

    stack = newList();

    while(true) {
        scanf("%s", input);

        if(strcmp(input, "ESCOLA") == 0) break;

        stackUp(&stack, input);
    }

    while(true) {
        unstack(&stack, input);
        if(strcmp(input, "DIREITA") == 0) printf("Vire a ESQUERDA ");
        else printf("Vire a DIREITA ");

        if(stack.size == 0) {
            printf("para chegar em CASA.\n");
            break;
        }

        unstack(&stack, input);
        printf("na rua %s.\n", input);
    }

    return 0;
}