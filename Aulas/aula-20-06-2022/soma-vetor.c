#include <stdio.h>
#include <stdlib.h>

int sumArray(int * v, int size);
int sumArray2(int * v, int size);

int main(void) {
    int size, i;
    int * v = NULL;

    scanf("%d", &size);
    v = (int *) calloc(size, sizeof(int));
    for(i = 0; i < size; i++) {
        scanf("%d", &v[i]);
    }

    printf("Soma: %d\n", sumArray(v, size));
    printf("Segunda soma: %d\n", sumArray2(v, size));
    
    free(v);
    return 0;
}

int sumArray(int * v, int size) {
    if(size == 1) return v[0];
    return v[size - 1] + sumArray(v, size - 1);
}

int sumArray2(int * v, int size) {
    if(size == 1) return v[0];
    return v[0] + sumArray2(&v[1], size - 1);
}