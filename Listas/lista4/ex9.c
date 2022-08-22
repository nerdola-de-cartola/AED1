#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 100

typedef struct Node {
    char name[SIZE];
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct {
    Node *first;
    Node *last;
    int size;
} List;

void error(const char *function_name) {
    printf("Erro na função %s\n", function_name);
    exit(0);
}

List newList() {
    List l;

    l.first = NULL;
    l.last = NULL;
    l.size = 0;

    return l;
}

bool push(List *l, char *name) {
    Node *new = NULL;

    new = (Node *) malloc(sizeof(Node));
    if(new == NULL) error("push");

    strcpy(new->name, name);

    if(l->size == 0) {
        l->first = new;
        l->last = new;
        new->prev = l->last;
        new->next = l->first;
        l->size++;
        return true;
    }
    
    l->last->next = new;
    l->first->prev = new;
    new->prev = l->last;
    new->next = l->first;
    l->last = new;
    l->size++;
    return true;
}

void freeList(List *l) {
    Node *p, *tmp;
    int i, total;

    total = l->size;

    for(p = l->first, i = 0; i < total; p = tmp, i++) {
        tmp = p->next;
        free(p);
    }

    l->first = NULL;
    l->last = NULL;
    l->size = 0;
}

bool removeList(List *l, char *name) {
    Node *p;
    int i;

    if(l->size == 1) {
        if(strcmp(l->first->name, name) == 0) {
            freeList(l);
            return true;
        }
    }

    for(p = l->first, i = 0; i < l->size; p = p->next, i++) {
        if(strcmp(p->name, name) == 0) {
            p->prev->next = p->next;
            p->next->prev = p->prev;
            if(p == l->last) l->last = p->prev;
            if(p == l->first) l->first = p->next;
            l->size--;
            free(p);
            return true;
        }
    }

    return false;
}

void printList(List *l) {
    Node *p;
    int i;

    for(p = l->first, i = 0; i < l->size; p = p->next, i++) {
        printf("%s\n", p->name);
    }
}

int main(void) {
    List circle;
    char input1[SIZE], input2[SIZE];
    Node *p;
    int i, j, k;
    int score;

    circle = newList();
    push(&circle, "Vovo");

    i = 0;
    while(true) {
        scanf("%s%*c", input1);
        if(strcmp(input1, "FIM") == 0) break;
        push(&circle, input1);
        i++;
    }

    j = i;
    score = 0;
    while(j > 0) {
        scanf("%s%*c", input1);
        scanf("%s%*c", input2);

        k = 0;
        if(strcmp(input2, "horario") == 0) {
            for(p = circle.first->next; k < 2 ; p = p->next) {
                if(strcmp(p->name, input1) == 0) {
                    removeList(&circle, p->name);
                    score++;
                    break;
                }

                k++;
            }
        } else if(strcmp(input2, "anti-horario") == 0) {
            for(p = circle.last; k < 2 ; p = p->prev) {
                if(strcmp(p->name, input1) == 0) {
                    removeList(&circle, p->name);
                    score++;
                    break;
                }

                k++;
            }
        }

        j--;
    }

    printf("%d\n", score);

    freeList(&circle);

    return 0;
}