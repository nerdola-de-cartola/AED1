#include <stdio.h>
#include "conjuntos.h"

int main(void) {
    Conjunto c, d, dif, comp, uni, inter;
    Conjunto * cp;
    long long int nc;
    int teste = 1, i;

    criaConjunto(&c);
    criaConjunto(&d);

    insereElementoConjunto(&c, 1);
    insereElementoConjunto(&c, 2);
    insereElementoConjunto(&c, 3);
    insereElementoConjunto(&c, 4);
    insereElementoConjunto(&c, 5);
    insereElementoConjunto(&c, 6);
    insereElementoConjunto(&c, 7);
    
    insereElementoConjunto(&d, 10);
    insereElementoConjunto(&d, 5);
    insereElementoConjunto(&d, 12);

    cp = conjuntoPartes(&c);
    nc = pow(2, c.size);
    for(i = 0; i < nc; i++) {
        mostraConjunto(&cp[i], CRESCENTE);
    }

    // printf("Elementos maiores do que %d: %d\n", teste, maior(&c, teste));
    // printf("Elementos menores do que %d: %d\n", teste, menor(&c, teste));

    // dif = diferenca(&c, &d);
    // mostraConjunto(&dif, CRESCENTE);

    // comp = complemento(&c, &d);
    // mostraConjunto(&comp, CRESCENTE);

    // uni = uniao(&c, &d);
    // mostraConjunto(&uni, CRESCENTE);

    // inter = interseccao(&c, &d);
    // mostraConjunto(&inter, CRESCENTE);

    //copiarConjunto(&c, &d);
    //ostraConjunto(&d, CRESCENTE);

    // mostraConjunto(&c, CRESCENTE);
    // mostraConjunto(&c, DECRESCENTE);

    // if(!criaConjunto(&c)) {
    //     printf("Erro ao criar um novo conjunto\n");
    //     return 0;
    // }

    //if(subconjunto(&d, &c)) printf("d é subconjuto de c\n");
    //if(!subconjunto(&c, &d)) printf("c não é subconjuto de d\n");

    // printf("Tamanho do conjunto: %d\n", tamanhoConjunto(&c));

    // if(conjuntosIdenticos(&c, &d)) printf("Conjuntos identicos\n");
    // else printf("Conjuntos diferentes\n");
    // if(conjuntosIdenticos(&c, &d)) printf("Conjuntos identicos\n");
    // else printf("Conjuntos diferentes\n");

    //if(!excluirElementoConjunto(&c, 10)) printf("Erro ao excluir elemento\n");
    //if(!excluirElementoConjunto(&c, 10)) printf("Erro ao excluir elemento\n");

    //if(pertenceConjunto(&c, teste)) printf("O número %d pertence ao conjunto\n", teste);
    //else printf("O número %d não pertence ao conjunto\n", teste);
    //if(pertenceConjunto(&c, teste)) printf("O número %d pertence ao conjunto\n", teste);
    //else printf("O número %d não pertence ao conjunto\n", teste);
    //if(!insereElementoConjunto(&c, 10)) printf("Erro ao inserir o elemento\n");

    destroiConjunto(&c);
    destroiConjunto(&d);
    // destroiConjunto(&dif);
    // destroiConjunto(&comp);
    // destroiConjunto(&uni);
    // destroiConjunto(&inter);
    for(i = 0; i < nc; i++) {
        destroiConjunto(&cp[i]);
    }
    free(cp);

    return 0;
}