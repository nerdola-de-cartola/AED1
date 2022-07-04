#include <stdio.h>

long long int mdc(long long int a, long long int b);


int main(void) {
    long long int n1, n2;

    scanf("%lld", &n1);
    scanf("%lld", &n2);

    printf("%lld\n", mdc(n1, n2));
    
    return 0;
}

long long int mdc(long long int a, long long int b) {
    if(b == 0) return a;
    return mdc(b, a%b);
}