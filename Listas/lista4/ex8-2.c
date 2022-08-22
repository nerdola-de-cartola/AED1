#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char *name;
    char *phone_number;
    int calls;
} Person;

typedef struct Node {
    Person p;
    struct Node * next;
    struct Node * prev;
} Node;

typedef struct List {
    Node *first;
    Node *last;
    int size;
} List;

void stringCopy(char **dest, char *src) {
    int size;
    
    *dest = NULL;
    size = strlen(src) + 1;

    *dest = (char *) malloc(size * sizeof(char));
    strcpy(*dest, src);
}

void freePerson(Person *p) {
    free(p->phone_number);
    free(p->name);
}

void freeNode(Node *n) {
    freePerson(&n->p);
    free(n);
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

void printList(List *l) {
    Node *p = NULL;

    for(p = l->last; p != NULL; p = p->prev) {
        printf("%s - %s %d\n", p->p.name, p->p.phone_number, p->p.calls);
    }
}

void sortList(List *l) {
    Node *p = NULL;
    Node *forward = NULL;
    Node *q = NULL;
    Node *p_min = NULL;
    Node *prev = NULL, *next = NULL;
    Person aux;

    p = l->first;
    while(p->next != NULL) {
        forward = p->next;

        p_min = p;
        q = p->next;

        while(q != NULL){
            if(p_min->p.calls > q->p.calls) p_min = q;
            q = q->next;
        }

        prev = p_min->prev;
        next = p_min->next;

        p_min->next = p->next;
        p_min->prev = p->prev;

        if(p->prev != NULL) p->prev->next = p_min;
        if(p->next != NULL) p->next->prev = p_min;

        p->next = next;
        p->prev = prev;

        if(prev != NULL) prev->next = p;
        if(next != NULL) next->prev = p;

        if(p_min->prev == NULL) l->first = p_min;
        if(p->prev == NULL) l->first = p;
        if(p_min->next == NULL) l->last = p_min;
        if(p->next == NULL) l->last = p;

        p = forward;
    }

}

void insertList(List *l, char *name, char *phone_number, int calls) {
    Node *new = NULL;
    Node *p = NULL;

    new = (Node *) malloc(sizeof(Node));
    if(new == NULL) error("insertList");

    stringCopy(&new->p.name, name);
    stringCopy(&new->p.phone_number, phone_number);
    new->p.calls = calls;

    if(l->size == 0) l->first = new;
    else l->last->next = new;

    new->prev = l->last;
    new->next = NULL;
    l->last = new;
    
    l->size++;
}

bool removeList(List *l, char *name) {
    Node * p = NULL;
    Node * prev = NULL;

    for(p = l->first; p != NULL; prev = p, p = p->next) {
        if(strcmp(p->p.name, name) == 0) {
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

            freeNode(p);
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
        freeNode(p);
    }

    l->first = NULL;
    l->last = NULL;
    l->size = 0;
}

Node *searchList(List *l, char *name) {
    Node * p = NULL;

    for(p = l->first; p != NULL; p = p->next) {
        if(strcmp(p->p.name, name) == 0) return p;
    }

    return NULL;
}

int main(void) {
    List phone_book;
    Node *n = NULL;
    Node *tmp, *tmp2, *tmp3;
    char option;
    char name[100];
    char phone_number[100];
    int calls;


    phone_book = newList();

    insertList(&phone_book, "Hermanoteu", "4523-2248", 300);
    insertList(&phone_book, "Ooloneia", "4523-4887", 299);

    while(true) {
        scanf("%c", &option);

        switch (option) {
        case 'I':
            scanf("%s%*c%s%*c%d%*c", name, phone_number, &calls);
            insertList(&phone_book, name, phone_number, calls);
            break;
        case 'R':
            scanf("%s%*c", name);
            removeList(&phone_book, name);
            break;
        case 'L':
            scanf("%s%*c", name);
            n = searchList(&phone_book, name);
            if(n != NULL) n->p.calls++;
            break;
        case 'F' :  
            sortList(&phone_book); 
            printList(&phone_book);
            freeList(&phone_book);
            return 0;
        }
    }
}