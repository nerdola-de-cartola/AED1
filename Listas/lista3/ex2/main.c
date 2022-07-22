#include "data.h"

int main(void) {
    Data *d, *cd, *prox, *anterior;
    int w;

    d = criaData(28, 12, 2002);
    // printData(d, "ddmmaaaa");
    // printData(d, "dd");
    // printData(d, "mm");
    // printData(d, "aaaa");
    // printData(d, "ddmm");

    // cd = copiaData(d);
    // printData(cd, "aaaammdd");

    prox = somaDiasData(d, 150);
    imprimeData(prox, "ddmmaaaa");
    liberaData(prox);

    // anterior = subtrairDiasData(d, 1);
    // imprimeData(anterior, "ddmmaaaa");
    // liberaData(anterior);

    // printf("%d\n", obtemDiaData(d));
    // printf("%d\n", obtemMesData(d));
    // printf("%d\n", obtemAnoData(d));

    // if(comparaData(d, cd) == IGUAL) printf("Data igual\n");
    // else if(comparaData(d, cd) == MAIOR) printf("Data maior\n");
    // else if(comparaData(d, cd) == MENOR) printf("Data menor\n");

    // atribuirData(cd, 17, 1, 2018);
    // imprimeData(cd, "ddmmaaaa");

    // printf("Diferença de dias: %d\n", numeroDiasDatas(cd, d));
    // printf("Diferença de meses: %d\n", numeroMesesDatas(cd, d));
    // printf("Diferença de anos: %d\n", numeroAnosDatas(cd, d));

    // w = obtemDiaSemanaData(d);
    // if(w == Dom) printf("Domingo\n");
    // else if(w == Seg) printf("Segunda-feira\n");
    // else if(w == Ter) printf("Terça-feira\n");
    // else if(w == Qua) printf("Quarta-feira\n");
    // else if(w == Qui) printf("Quinta-feira\n");
    // else if(w == Sex) printf("Sexta-feira\n");
    // else if(w == Sab) printf("Sábado\n");
    // else erro("obtemDiaSemanaData\n");

    liberaData(d);
    //liberaData(cd);

    return 0;
}