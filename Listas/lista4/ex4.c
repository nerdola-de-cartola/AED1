#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ERRO -1

typedef struct Node {
    int n;
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

bool stackUp(List *l, int value) {
    Node *new = NULL;

    new = (Node *) malloc(sizeof(Node));
    if(new == NULL) error("stackUp");

    new->n = value;
    new->next = NULL;
    
    if(l->first == NULL) l->first = new;
    if(l->last != NULL) l->last->next = new; 
    l->last = new;
    l->size++;

    return true;
}

int unstack(List *l) {
    Node *p = NULL;
    int last;

    if(l->size == 0) return ERRO;

    if(l->size == 1) {
        last = l->first->n;
        freeList(l);
        return last;
    }

    for(p = l->first; p->next != l->last; p = p->next);

    p->next = NULL;
    last = l->last->n;
    free(l->last);
    l->last = p;
    l->size--;

    return last;
}

int main(void) {
    char str[1001];
    char last;
    List stack;
    int i;

    stack = newList();
    scanf("%[^\n]%*c", str);

    i = 0;
    while(str[i] != '\0') {
        if(str[i] == '(') stackUp(&stack, str[i]);
        if(str[i] == ')') {
            last = unstack(&stack);
            if(last != '(') {
                printf("incorreta\n");
                freeList(&stack);
                return 0;
            }
        }
        i++;
    }

    printf("correta\n");
    freeList(&stack);

    return 0;
}