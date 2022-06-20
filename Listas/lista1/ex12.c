#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int leVetor(int ** v);
bool elementoExiste(int * v, int size, int ele);
void uniao(int * v1, int size1, int *v2, int size2);
void interseccao(int * v1, int size1, int *v2, int size2);
void diferenca(int * v1, int size1, int *v2, int size2);
void imprimeConjunto(char * str, int * v, int size);


int main(void) {
    int size1, size2;
    int * v1 = NULL, * v2 = NULL;

    size1 = leVetor(&v1);
    size2 = leVetor(&v2);

    uniao(v1, size1, v2, size2);
    interseccao(v1, size1, v2, size2);
    diferenca(v1, size1, v2, size2);
    diferenca(v2, size2, v1, size1);
    
    free(v1);
    free(v2);
    return 0;
}

int leVetor(int ** v) {
    int i, input, size;

    scanf("%d", &size);

    if(size < 1) {
        printf("O numero de elementos do vetor deve ser maior do que zero – programa cancelado\n");
        exit(0);
    }

    *v = (int *) calloc(size, sizeof(int));

    for(i = 0; i < size; i++) {
        scanf("%d", &input);
        if(elementoExiste(*v, size, input)) {
            (*v)[i] = input;
        } else {
            printf("O vetor não pode ter elementos repetidos = programa cancelado\n");
            exit(0);
        }
    }

    return size;
}

bool elementoExiste(int * v, int size, int ele) {
    int i;

    for(i = 0; i < size; i++) {
        if(v[i] == ele) return false;
    }

    return true;
}

void uniao(int * v1, int size1, int *v2, int size2){
    int i, j;
    int * c = NULL;

    c = (int *) calloc(size1+size2, sizeof(int));

    for(i = 0; i < size1; i++) {
        c[i] = v1[i];
    }

    for(j = 0; j < size2; j++) {
        if(elementoExiste(c, i, v2[j])) {
            c[i] = v2[j];
            i++;
        }
    }

    imprimeConjunto("união", c, i);

    free(c);
}

void interseccao(int * v1, int size1, int *v2, int size2) {
    int i, j;
    int * c = NULL;

    c = (int *) calloc(size1+size2, sizeof(int));

    for(i = 0, j = 0; j < size1; j++) {
        if(!elementoExiste(v2, size2, v1[j])) {
            c[i] = v1[j];
            i++;
        }
    }

    imprimeConjunto("diferença", c, i);
    free(c);

}

void diferenca(int * v1, int size1, int *v2, int size2) {
    int i, j;
    int * c = NULL;

    c = (int *) calloc(size1+size2, sizeof(int));

    for(i = 0, j = 0; j < size1; j++) {
        if(elementoExiste(v2, size2, v1[j])) {
            c[i] = v1[j];
            i++;
        }
    }

    imprimeConjunto("diferença", c, i);
    free(c);
}

void imprimeConjunto(char * str, int * v, int size) {
    int i;

    printf("Vetor que representa a %s dos vetores de entrada:", str);

    for(i = 0; i < size; i++) {
        printf(" %d", v[i]);
    }
    printf("\n");
}