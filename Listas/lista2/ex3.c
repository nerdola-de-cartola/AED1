#include <stdio.h>
#include <stdlib.h>

void decToBin(int n, char * bin, int size);

int main(void) {
    int testes, n, i, size;
    char * bin;
    scanf("%d", &testes);

    while(testes--) {
        scanf("%d", &n);
        size = 32;
        bin = (char *) calloc(size, sizeof(char));

        decToBin(n, bin, size);


        for(i = 0; i < size; i++) {
            if(bin[i] != 0) break;
        }

        for(i = i; i < size; i++) {
            printf("%c", bin[i] + '0');
        }
        printf("\n");
    }

    free(bin);
    
    return 0;
}

void decToBin(int n, char * bin, int size) {
    if(size == 0) {
        printf("Erro\n");
        exit(0);
    }

    if(n <= 0) return;
    size--;
    bin[size] = n%2;
    decToBin(n/2, bin, size);
}