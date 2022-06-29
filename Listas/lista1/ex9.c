#include <stdio.h>

int main(void) {
    int n, div, sum_div;
    scanf("%d", &n);

    if(n <= 0) {
        printf("erro\n");
        return 0;
    }

    sum_div = 0;
    for(div = 1; div <= n/2; div++) {
        if(n%div == 0) {
            sum_div += div;
        }
    }

    if(sum_div == n) {
        printf("perfeito\n");
    } else {
        printf("imperfeito\n");
    }
    
    return 0;
}