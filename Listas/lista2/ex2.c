#include <stdio.h>
#include <stdlib.h>

void reverse(int n, int * r);

int main(void) {
    int n, * r = NULL;

    scanf("%d", &n);
    r = calloc(1, sizeof(int));

    reverse(n, r);

    printf("%d\n", *r);

    return 0;
}

void reverse(int n, int * r) {
    int last_digit;

    if(n <= 0) return;
    *r *= 10;
    last_digit = n%10;
    *r += last_digit;

    reverse((n - last_digit) / 10, r);
}