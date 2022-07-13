#include <stdio.h>
#include <stdlib.h>

int fib(int n, int * vet);

int main(void) {
    int x;
    int n, i;
    int * seq = NULL;
    scanf("%d", &n);

    seq = (int *) calloc(n, sizeof(int));
    seq[0] = 1;
    seq[1] = 1;

    fib(n, seq);

    printf("0");
    if(n != 0) printf(" ");
    for(i = 0; i < n; i++) {
        printf("%d", seq[i]);
        if(i != n-1) printf(" ");
    }
    printf("\n");
    
    free(seq);
    return 0;
}

int fib(int n, int * vet) {
    int fat;

    if(vet[n] != 0) return vet[n];
    fat = fib(n-2, vet) + fib(n-1, vet);
    vet[n] = fat;
    return fat;
}
