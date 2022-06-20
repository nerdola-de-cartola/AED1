#include <stdio.h>

long long int fib(int n);
long long int fatora(long long int n);

int main(void) {
    int n;
    long long int f;
    scanf("%d", &n);
    if(n <= 3 || n >= 100) {
        printf("O numero de ordem deve ser maior ou igual a 3 e menor ou igual a 100 – programa cancelado\n");
    }

    f = fib(n);
    printf("O numero da sequencia de Fibonacci que corresponde a ordem %d é: %lld\n", n, f);
    printf("Fatoracao de %lld:", f);
    fatora(f);
    printf("\n");
    
    return 0;
}


long long int fib(int n) {
    if(n == 1 || n == 2) return 1;
    return fib(n-1) + fib(n-2);
}

long long int fatora(long long int n) {
    int i;

    for(i = 2; n > 1;) {
        if(n%i == 0) {
            n /= i;
            printf(" %d", i);
            if(n > 1) {
                printf(" X");
            }
        } else {
            i++;
        }
    }
}