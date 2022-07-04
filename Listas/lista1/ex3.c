#include <stdio.h>
#include <stdlib.h>

void erro();

int main(void) {
    int n, i, j, sum;

    scanf("%d", &n);
    if(n <= 0 || n > 1000) erro();

    sum = 2;
    n--;
    for(i = 3; n > 0; i++) {
        for(j = 2; j < i; j++) {
            if(i%j == 0) break;
        }

        if(i == j) {
            sum += i;
            n--;
        }
    }

    printf("%d\n", sum);

    return 0;
}

void erro() {
    printf("erro\n");
    exit(0);
}