#include <stdio.h>

#define true 1

long long int fib(long long int n);
long long int sumFib(long long int n);

int main(void) {
    int n;
    while(true) {
        scanf("%d", &n);
        printf("%lld\n", sumFib(n));
    }
}

long long int fib(long long int n) {
    if(n == 1 || n == 2) return 1;
    else return fib(n-1) + fib(n-2);
}

long long int sumFib(long long int n) {
    if(n == 1) return 1;
    return fib(n) + sumFib(n-1);
}