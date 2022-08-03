#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

void removeList(List *l, int value);

void printList(List *l);

void freeList(List *l);

void error(const char *function_name);