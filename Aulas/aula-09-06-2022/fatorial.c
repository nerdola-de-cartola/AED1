#include <stdio.h>

long long int fatorial(long long int n);

int main(void) {
    int n;

    scanf("%d", &n);

    printf("%lld\n", fatorial(n));
}

long long int fatorial(long long int n) {
    if(n == 1) return 1;
    else return n * fatorial(n-1);
}