#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define ERRO -1
#define SIZE 1000

typedef struct Node {
    char n;
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

bool stackUp(List *l, char value) {
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

char unstack(List *l) {
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

bool priority(char c, char t){
    int pc, pt;

    if(c == '^') pc = 4;
    else if(c == '*' || c == '/') pc = 2;
    else if(c == '+' || c == '-') pc = 1;
    else if(c == '(') pc = 4;

    if(t == '^') pt = 3;
    else if(t == '*' || t == '/') pt = 2;
    else if(t == '+' || t == '-') pt = 1;
    else if(t == '(') pt = 0;

    return (pc > pt);
}

bool isOperator(char c) {
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^' ) return true;
    return false;
}

void posFix(char *infix, char *posfix) {
    List p;
    int i, j;
    char c, t;

    memset(posfix, '\0', SIZE);
    p = newList();
    stackUp(&p, '(');

    i = 0;
    j = 0;
    do {
        c = infix[i];
        i++;
        if(isalnum(c)){
            posfix[j] = c;
            j++;
        } else if(c == '(') {
            stackUp(&p, '(');
        } else if(c == ')' || c == '\0') {
            do {
                t = unstack(&p);
                if(t != '(') {
                    posfix[j] = t;
                    j++;
                }
            } while(t != '(');
        } else if(isOperator(c)) {
            while(true) {
                t = unstack(&p);
                if(priority(c, t)) {
                    stackUp(&p, t);
                    stackUp(&p, c);
                    break;
                }

                posfix[j] = t;
                j++;
            }
        }
    } while(c != '\0');

    freeList(&p);
}

bool check(char *str) {
    List stack;
    char last;
    int i;
    bool correct;

    stack = newList();
    correct = true;
    i = 0;
    while(str[i] != '\0') {
        if(str[i] == '(') stackUp(&stack, str[i]);

        if(str[i] == ')') {
            last = unstack(&stack);
            if(last != '(') {
                correct = false;
                break;
            }
        }

        i++;
    }

    if(stack.size != 0) correct = false;
    freeList(&stack);

    return correct;
}

int main(void) {
    char input[SIZE];
    char output[SIZE];
    int tests;
    int i;

    scanf("%d%*c", &tests);

    while(tests--) {
        scanf("%[^\n]%*c", input);

        if(!check(input)) {
            printf("mal-formada\n");
            continue;
        }

        posFix(input, output);
        i = 0;
        while(output[i] != '\0') {
            if(output[i+1] == '\n') printf("%c", output[i]);
            else printf("%c ", output[i]);
            i++;
        }
        printf("\n");
    }

    return 0;
}