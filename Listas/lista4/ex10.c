#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 31

typedef struct Node {
    char name[SIZE];
    int number;
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

bool push(List *l, char *name, int number) {
    Node *new = NULL;

    new = (Node *) malloc(sizeof(Node));
    if(new == NULL) error("push");

    strcpy(new->name, name);
    new->number = number;

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
        printf("%s %d\n", p->name, p->number);
    }
}

int main(void) {
    List circle;
    Node *p = NULL;
    char input_name[SIZE];
    int players, i, end, input_number;

    circle = newList();
    scanf("%d%*c", &players);
    for(i = 0; i < players; i++) {
        scanf("%s%*c%d%*c", input_name, &input_number);
        push(&circle, input_name, input_number);
    }

    end = circle.first->number;
    while(circle.size > 1) {
        i = 1;

        if(end%2 != 0) {
            p = circle.first->next;
            while(i < end) {
                i++;
                p = p->next;
            }
        } else {
            p = circle.last;
            while(i < end) {
                i++;
                p = p->prev;
            }
        }
        
        end = p->number;
        removeList(&circle, p->name);
    }
    
    printf("%s\n", circle.first->name);

    freeList(&circle);

    return 0;
}