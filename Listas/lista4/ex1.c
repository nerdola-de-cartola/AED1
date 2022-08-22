#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int time_arrive;
    int time_limit;
} Paciente;

typedef struct Node {
    Paciente p;
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

void lePaciente(Paciente *p) {
    int hour, min, total_min;

    scanf("%d%d%d", &hour, &min, &p->time_limit);
    total_min = hour * 60;
    total_min += min;
    p->time_arrive = total_min;
}

bool push(List *l, Paciente p) {
    Node *new = NULL;

    new = (Node *) malloc(sizeof(Node));
    if(new == NULL) error("push");

    new->p = p;
    new->next = NULL;

    if(l->first == NULL) l->first = new;
    else l->last->next = new;
    l->last = new;
    l->size++;
}

Paciente pop(List *l) {
    Node *tmp;
    Paciente f;

    tmp = l->first;
    l->first = l->first->next;
    f = tmp->p;
    free(tmp);
    l->size--;
    return f;
}

int main(void) {
    List fila;
    Paciente p;
    int qtd_pacientes;
    int actual_time;
    int limits_break;
    int i;

    fila = newList();
    scanf("%d", &qtd_pacientes);
    limits_break = 0;

    while(qtd_pacientes--) {
        lePaciente(&p);   
        push(&fila, p);
    }

    p = pop(&fila);
    actual_time = p.time_arrive + 30;

    while(fila.size > 0){
        p = pop(&fila);

        if(p.time_arrive > actual_time) {
            actual_time = p.time_arrive + 30;      
            continue;
        }
        
        if(actual_time > p.time_arrive + p.time_limit) limits_break++;
        actual_time += 30;
    }

    printf("%d\n", limits_break);

    freeList(&fila);
    
    return 0;
}