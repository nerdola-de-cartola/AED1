#include <stdio.h>
#include <stdlib.h>

void erro();

int main(void) {
    int semanas, min_prod, max_prod;

    scanf("%d", &semanas);
    if(semanas < 1) erro();

    min_prod = ((5*4) + (3*2)) * 8 * semanas;
    max_prod = ((5*5) + (3*2)) * 8 * semanas;

    printf("%d\n", min_prod);
    printf("%d\n", max_prod);
    
    return 0;
}

void erro() {
    printf("erro\n");
    exit(0);
}