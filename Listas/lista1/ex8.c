#include <stdio.h>

int main(void) {
    int n1, n2, div, menor;

    scanf("%d", &n1);
    scanf("%d", &n2);

    menor = n1;
    if(n2 < menor) menor = n2;

    for(div = menor; div >= 2; div--) {
        if(n1%div == 0 && n2%div == 0) {
            printf("%d\n", div);
            break;
        }
    }
    
    return 0;
}