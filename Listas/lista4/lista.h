#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define CRESCENTE 0
#define DECRESCENTE 1

typedef struct Node {
    int n;
    struct Node * next;
    struct Node * prev;
} Node;

typedef struct List {
    Node *first;
    Node *last;
    int size;
} List;

List newList();

void insertList(List *l, int value);

bool removeList(List *l, int value);

void printList(List *l, int ordem);

void freeList(List *l);

void error(const char *function_name);

bool searchList(List *l, int value);

List sumList(List *l1, List *l2);

void copyList(List *dest, List *source);