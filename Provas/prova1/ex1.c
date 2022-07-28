#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MIN_SIZE 1
#define MAX_SIZE 100

int somaMinMax(int *vet, int size);
void ordenaVetor(int *vet, int size);
int somaInVet(int *vet, int size, int max, int min);

int main(void) {
    int *vet = NULL;
    int size, i;

    while(true) {
        printf("Digite a o tamanho do vetor desejado: ");
        scanf("%d", &size);
        if(size >= MIN_SIZE && size <= MAX_SIZE) break;
    }

    vet = (int *) malloc(size * sizeof(int));
    printf("Digite cada um dos valores do seu vetor separados por um espaço: ");
    for(i = 0; i < size; i++) scanf("%d", &vet[i]);
    printf("A soma dos mínimos e máximos é: %d\n", somaMinMax(vet, size));

    free(vet);
    
    return 0;
}

int somaMinMax(int *vet, int size) {
    int i, min, max, soma = 0;

    if(size == 0) {
        printf("Erro, tamanho do vetor inválido\n");
        exit(0);
    }

    ordenaVetor(vet, size);

    min = vet[0];
    max = vet[size-1];
   
    soma = somaInVet(vet, size, max, min);

    return soma;
}

void ordenaVetor(int *vet, int size) {
    int min = 0;
    int i, tmp;

    if(size == 0) return;

    for(i = 1; i < size; i++) {
        if(vet[i] < vet[min]) min = i;
    }

    tmp = vet[0];
    vet[0] = vet[min];
    vet[min] = tmp;

    ordenaVetor(vet+1, size-1);
}

int somaInVet(int *vet, int size, int max, int min) {
    int soma = 0;

    if(size == 0) return 0;

    if(vet[0] == min) soma += min;
    if(vet[0] == max) soma += max;
    return soma + somaInVet(vet+1, size-1, max, min);
}