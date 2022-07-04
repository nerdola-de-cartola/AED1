#include <stdio.h>

int main()
{

    double valor_inicial, taxa_juros, taxaadm, auxvalori, diferenca;
    int year = 1;
    int anos;

    // printf("Entre com o valor do capital inicial investido:\n");
    scanf("%lf", &valor_inicial);
    if (valor_inicial <= 0)
    {
        printf("erro\n");
        return 0;
    }
    // printf("Entre com o numero de anos em que o capital sera investido:\n");
    scanf("%d", &anos);
    if (anos <= 0)
    {
        printf("erro\n");
        return 0;
    }
    // printf("Entre com a taxa de juros anual (percentual):\n");
    scanf("%lf", &taxa_juros);
    if ((taxa_juros <= 0) || (taxa_juros >= 100)){ //Troquei as verificações
        printf("erro\n");
        return 0;
    }
    // printf
    scanf("%lf", &taxaadm);
    if ((taxaadm <= 0) || (taxaadm >= 100)){ //Troquei as verificações
        printf("erro\n");
        return 0;
    }

    while (year <= anos)
    {   
        auxvalori=valor_inicial;
        valor_inicial+=(valor_inicial*taxa_juros)/100;
        diferenca=(valor_inicial-auxvalori)*(taxaadm/100);
        valor_inicial=valor_inicial-diferenca;
        printf("%.2lf\n", valor_inicial); //Tinha um caracter de espaço aqui e eu tirei

        year++;
    }

    return 0;
}