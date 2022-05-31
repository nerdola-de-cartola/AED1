#include <stdio.h>
    
// guarda um inteiro OU um vetor de 4 bytes
typedef union {
    int value;
    unsigned char byte[4];
} intParts;
    
int main () {
    intParts a;
    int i;
    
    a.value = 653459;
    
    printf("%d: ", a.value);
    
    for(i = 0; i < 4; i++) {
        printf ("%02x ", a.byte[i]);
    }
    
    printf ("\n");
}

