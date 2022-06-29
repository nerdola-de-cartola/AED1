#include <stdio.h>

int mdc(int a, int b);

int main(void) {
    int a, b;
    scanf("%d%d", &a, &b);
    int m = mdc(a, b);
    printf("\n%d\n", m);
}

int mdc(int a, int b) {
    if(b == 0) {
        return a;
    }
    return mdc(b, a%b);
}