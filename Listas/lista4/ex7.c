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

void printList(List *l) {
    Node *p;

    for(p = l->first; p != NULL; p = p->next) {
        printf("%d ", p->n);
    }
    printf("\n");
}

void push(List *l, int value) {
    Node *new = NULL;

    new = (Node *) malloc(sizeof(Node));
    if(new == NULL) error("push");

    new->n = value;
    new->next = NULL;

    if(l->first == NULL) l->first = new;
    else l->last->next = new;
    l->last = new;
    l->size++;
}

bool insertList(List *l, int value, int prev) {
    Node *new = NULL;
    Node *p = NULL;
    int i;

    new = (Node *) malloc(sizeof(Node));
    if(new == NULL) error("insertList");

    new->n = value;

    for(p = l->first; p != NULL; p = p->next) {
        if(p->n == prev) {
            new->next = p->next;
            p->next = new;
            if(new->next == NULL) l->last = new;
            return true;
        }
    }

    free(new);
    return false;
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

int searchList(List *l, int value1, int value2) {
    Node *p = NULL;
    bool achei_primeiro, primeiro_1, primeiro_2;
    int i;

    i = 0;
    achei_primeiro = false;
    primeiro_1 = false;
    primeiro_2 = false;

    for(p = l->first; p != NULL; p = p->next) {
        if(achei_primeiro) {
            if(primeiro_1) {
                if(p->n == value2) return i;
            } else if(primeiro_2) {
                if(p->n == value1) return i;
            }
            i++;
        } else {
            if(p->n == value1) {
                achei_primeiro = true;
                primeiro_1 = true;
            } else if(p->n == value2) {
                achei_primeiro = true;
                primeiro_2 = true;
            }

        }
    }
}

int main(void) {
    List queue;
    char option;
    int input1, input2;
    int i;

    queue = newList();

    scanf("%d", &input1);
    for(i = 0; i < input1; i++) {
        scanf("%d", &input2);
        push(&queue, input2);
    }

    while(true) {
        scanf("%c", &option);

        switch(option) {
            case 'I':
                scanf("%d%d", &input1, &input2);
                insertList(&queue, input1, input2);
                printf("inserido %d\n", input1);
                break;
            case 'R':
                scanf("%d", &input1);
                removeList(&queue, input1);
                printf("removido %d\n", input1);
                break;
            case 'C':
                scanf("%d%d", &input1, &input2);
                printf("quantidade %d\n", searchList(&queue, input1, input2));
                break;
            case 'M':
                printf("lista ");
                printList(&queue);
                break;
            case 'F':
                printf("fim\n");
                freeList(&queue);
                return 0;
        }
    }
}