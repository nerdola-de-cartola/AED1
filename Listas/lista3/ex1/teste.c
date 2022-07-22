#include "conjuntos.h"

int main(void) {
    Conjunto c, d, cc, dif, comp, uni, inter;
    Conjunto * cp;
    long long int nc;
    int teste = 3, i;

    criaConjunto(&c);
    criaConjunto(&d);

    insereElementoConjunto(&c, 1);
    insereElementoConjunto(&c, 2);
    insereElementoConjunto(&c, 3);
    insereElementoConjunto(&c, 4);
    
    insereElementoConjunto(&d, 1);
    insereElementoConjunto(&d, 5);

    printf("Elementos maiores do que %d: %d\n", teste, maior(&c, teste));
    printf("Elementos menores do que %d: %d\n", teste, menor(&c, teste));

    printf("Diferença entre C e D\n");
    dif = diferenca(&c, &d);
    mostraConjunto(&dif, CRESCENTE);

    printf("Complemento entre C e D\n");
    comp = complemento(&c, &d);
    mostraConjunto(&comp, CRESCENTE);

    printf("União entre C e D\n");
    uni = uniao(&c, &d);
    mostraConjunto(&uni, CRESCENTE);

    printf("Intersecção entre C e D\n");
    inter = interseccao(&c, &d);
    mostraConjunto(&inter, CRESCENTE);

    printf("O conjunto C e sua cópia CC\n");
    copiarConjunto(&c, &cc);
    mostraConjunto(&c, CRESCENTE);
    mostraConjunto(&cc, CRESCENTE);

    printf("Conjunto das partes:\n");
    cp = conjuntoPartes(&c);
    nc = pow(2, c.size);
    for(i = 0; i < nc; i++) {
        mostraConjunto(&cp[i], CRESCENTE);
    }

    if(subconjunto(&d, &c)) printf("D é subconjuto de C\n");
    else printf("D não é subconjuto de C\n");

    if(subconjunto(&c, &d)) printf("C é subconjuto de D\n");
    else printf("C não é subconjuto de D\n");

    printf("Tamanho do conjunto C: %d\n", tamanhoConjunto(&c));

    if(conjuntosIdenticos(&c, &d)) printf("Conjuntos identicos\n");
    else printf("Conjuntos diferentes\n");

    if(excluirElementoConjunto(&c, teste)) printf("Sucesso ao excluir o elemento %d do conjunto C\n", teste);
    else printf("Erro ao excluir o elemento %d do conjunto C\n", teste);
    if(excluirElementoConjunto(&c, teste)) printf("Sucesso ao excluir o elemento %d do conjunto C\n", teste);
    else printf("Erro ao excluir o elemento %d do conjunto C\n", teste);

    if(pertenceConjunto(&c, teste)) printf("O número %d pertence ao conjunto C\n", teste);
    else printf("O número %d não pertence ao conjunto C\n", teste);

    destroiConjunto(&c);
    destroiConjunto(&d);
    destroiConjunto(&cc);
    destroiConjunto(&dif);
    destroiConjunto(&comp);
    destroiConjunto(&uni);
    destroiConjunto(&inter);
    for(i = 0; i < nc; i++) {
        destroiConjunto(&cp[i]);
    }
    free(cp);

    return 0;
}
