#include <stdio.h>

long long int fat(long long int n);

int main(void) {
    long long int n;

    scanf("%lld", &n);

    if(n%2 == 0) n--;
    printf("%lld\n", fat(n));
    
    return 0;
}

long long int fat(long long int n) {
    if(n <= 0) return 1;
    return n * fat(n-2);
}