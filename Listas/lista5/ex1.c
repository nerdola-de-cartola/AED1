#include <stdio.h>
#include <stdlib.h>

#define CRESCENTE 1
#define DECRESCENTE 0 

void printArray(int *arr, int size, char ordem);
void sort(int *v, int *c, int i, int f);
void merge(int *v, int *c, int i, int m, int f);
void mergeSort(int *v, int n);

int main(void) {
    int *odds = NULL, *pairs = NULL;
    int qtd_odds = 0, qtd_pairs = 0;
    int n, i, input;

    scanf("%d", &n);

    odds = calloc(n, sizeof(int));
    pairs = calloc(n, sizeof(int));
    
    if(odds == NULL || pairs == NULL) return 1;

    for(i = 0; i < n; i++) {
        scanf("%d", &input);

        if(input%2 == 0) {
            qtd_pairs++;
            pairs[qtd_pairs-1] = input;
        } else {
            qtd_odds++;
            odds[qtd_odds-1] = input;
        }
    }

    mergeSort(odds, qtd_odds);
    mergeSort(pairs, qtd_pairs);

    printArray(pairs, qtd_pairs, CRESCENTE);
    printArray(odds, qtd_odds, DECRESCENTE);

    free(odds);
    free(pairs);

    return 0;
}

void printArray(int *arr, int size, char ordem) {
    int i;

    if(ordem == CRESCENTE) {
        for(i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
    } else {
        for(i = size-1; i >= 0; i--) {
            printf("%d ", arr[i]);
        }
    }

    printf("\n");
}

/*
  Dado um vetor de inteiros v e um inteiro n >= 0, ordena o vetor v[0..n-1] em ordem crescente.
*/
void mergeSort(int *v, int n) {
  int *c = malloc(sizeof(int) * n);
  sort(v, c, 0, n - 1);
  free(c);
}

/*
  Dado um vetor de inteiros v e dois inteiros i e f, ordena o vetor v[i..f] em ordem crescente.
  O vetor c é utilizado internamente durante a ordenação.
*/
void sort(int *v, int *c, int i, int f) {
  if(i >= f) return;

  int m = (i + f) / 2;

  sort(v, c, i, m);
  sort(v, c, m + 1, f);

  /* Se v[m] <= v[m + 1], então v[i..f] já está ordenado. */
  if(v[m] <= v[m + 1]) return;

  merge(v, c, i, m, f);
}


/*
  Dado um vetor v e três inteiros i, m e f, sendo v[i..m] e v[m+1..f] vetores ordenados,
  coloca os elementos destes vetores, em ordem crescente, no vetor em v[i..f].
*/
void merge(int *v, int *c, int i, int m, int f) {
    int z, iv = i, ic = m + 1;

    for(z = i; z <= f; z++) c[z] = v[z];

    z = i;

    while(iv <= m && ic <= f) {
        /* Invariante: v[i..z] possui os valores de v[iv..m] e v[ic..f] em ordem crescente. */

        if(c[iv] <= c[ic]) v[z++] = c[iv++];
        else v[z++] = c[ic++];
    }

    while(iv <= m) v[z++] = c[iv++];
    while(ic <= f) v[z++] = c[ic++];
}