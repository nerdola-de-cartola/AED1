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

    for(p = l->first; p != NULL; p = p->next) {
        printf("%s - %s %d\n", p->p.name, p->p.phone_number, p->p.calls);
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

    for(p = l->first; true; p = p->next) {
        if(l->size == 0) {
            l->first = new;
            l->last = new;
            new->next = NULL;
            new->prev = NULL;
            break;
        } 

        if(calls > p->p.calls) {
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
        scanf("%c%*c", &option);

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
            if(n->prev == NULL) break;

            while(n->p.calls > n->prev->p.calls) {
                tmp = n->prev;
                tmp2 = n->next;
                tmp3 = tmp->prev;

                n->next = tmp;
                n->prev = tmp->prev;

                tmp->prev = n;
                tmp->next = tmp2;

                if(tmp2 != NULL) tmp2->prev = tmp;
                if(tmp3 != NULL) tmp3->next = n;

                if(tmp->next == NULL) phone_book.last = tmp;

                if(n->prev == NULL) {
                    phone_book.first = n;
                    break;
                }
            }
            break;
        default :    
            printList(&phone_book);
            freeList(&phone_book);
            return 0;
        }
    }
}