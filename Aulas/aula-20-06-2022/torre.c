#include <stdio.h>

void towers(int nDiscos, char deHaste, char paraHaste, char auxHaste, int * i);

int main(void) {    
    int i = 0;
    towers(8, 'A', 'B', 'C', &i);
    return 0;
}

void towers(int nDiscos, char deHaste, char paraHaste, char auxHaste, int * i) {
    printf("%d\n", *i);
    (*i)++;
    // Se um disco somente, mova−o e retorne
    if(nDiscos==1) {
        printf("Move disco 1 de %c para %c\n", deHaste, paraHaste);
        return;
    }

    // Move (n−1) discos superiores de A para C, usando B
    towers(nDiscos - 1, deHaste, auxHaste, paraHaste, i);

    // Move disco remanescente de A para B ∗/
    printf("Move disco %d de %c para pino %c\n", nDiscos, deHaste, paraHaste);
    
    // Move, recursivamente, (n−1) discos de C para B, usando A
    towers(nDiscos - 1, auxHaste, paraHaste, deHaste, i);
}