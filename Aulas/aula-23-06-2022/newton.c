#include <stdio.h>

int binomio(int n, int k);

int main(void) {
    int n, k;
    scanf("%d%d", &n, &k);
    if(k > n) {
        printf("N deve ser maior que K\n");
        return 1;
    }

    printf("%d\n", binomio(n, k));
    
    return 0;
}

int binomio(int n, int k) {
    if(n == k || k == 0) return 1;
    return binomio(n-1, k) + binomio(n-1, k-1);
}