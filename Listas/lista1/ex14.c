#include <stdio.h>

long long int fib(int n);
void fatora(long long int n);

int main(void) {
    int n;
    long long int f;
    scanf("%d", &n);
    if(n < 3 || n > 100) {
        printf("erro\n");
        return 0;
    }

    f = fib(n);
    printf("%lld\n", f);
    fatora(f);
    printf("\n");
    
    return 0;
}


long long int fib(int n) {
    if(n == 1 || n == 0) return 1;
    return fib(n-1) + fib(n-2);
}

void fatora(long long int n) {
    int i;

    for(i = 2; n > 1;) {
        if(n%i == 0) {
            n /= i;
            printf("%d ", i);
        } else {
            i++;
        }
    }
}