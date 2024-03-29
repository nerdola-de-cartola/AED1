#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 100

typedef struct {
    char name[SIZE];
    char phone_number[SIZE];
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

    for(p = l->first; p != NULL; p = p->next) {
        printf("%s - %s %d\n", p->p.name, p->p.phone_number, p->p.calls);
    }
}

void copyPerson(Person *dest, Person src) {
    dest->calls = src.calls;
    strcpy(dest->name, src.name);
    strcpy(dest->phone_number, src.phone_number);
}

void sortList(List *l) {
    Node *p = NULL;
    Node *q = NULL;
    Node *maior = NULL;
    Person swap;
    
    for(p = l->first; p->next != NULL; p = p->next) {
        maior = p;

        for(q = p->next; q != NULL; q = q->next) {
            if(q->p.calls > maior->p.calls) maior = q;
        }

        if(maior != p) {
            copyPerson(&swap, p->p);
            copyPerson(&p->p, maior->p);
            copyPerson(&maior->p, swap);
        }
    }
}

void insertList(List *l, char *name, char *phone_number, int calls) {
    Node *new = NULL;
    Node *p = NULL;

    new = (Node *) malloc(sizeof(Node));
    if(new == NULL) error("insertList");

    strcpy(new->p.name, name);
    strcpy(new->p.phone_number, phone_number);
    new->p.calls = calls;

    if(l->size == 0) l->first = new;
    else l->last->next = new;

    new->prev = l->last;
    new->next = NULL;
    l->last = new;
    
    l->size++;
}

void freeList(List *l) {
    Node * p = NULL;
    Node * tmp = NULL;

    for(p = l->first; p != NULL; p = tmp) {
        tmp = p->next;
        free(p);
    }

    *l = newList();
}

bool removeList(List *l, char *name) {
    Node * p = NULL;

    for(p = l->first; p != NULL; p = p->next) {
        if(strcmp(p->p.name, name) == 0) {
            if(l->size == 1) {
                freeList(l);
                return true;
            }

            if(p == l->first) l->first = p->next;
            else if(p == l->last) l->last = p->prev;
            else {
                p->prev->next = p->next;
                p->next->prev = p->prev;
            } 

            l->first->prev = NULL;
            l->last->next = NULL;
            l->size--;

            free(p);


            return true;
        }
    }

    return false;
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
    char name[SIZE];
    char phone_number[SIZE];
    int calls;

    phone_book = newList();

    insertList(&phone_book, "Hermanoteu", "4523-2248", 300);
    insertList(&phone_book, "Ooloneia", "4523-4887", 299);

    while(true) {
        scanf("%c", &option);

        switch (option) {
        case 'I':
            scanf("%s%s%d", name, phone_number, &calls);
            insertList(&phone_book, name, phone_number, calls);
            break;
        case 'R':
            scanf("%s", name);
            removeList(&phone_book, name);
            break;
        case 'L':
            scanf("%s", name);
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