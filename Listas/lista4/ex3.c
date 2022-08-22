#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void error(const char *function_name) {
    printf("Erro na função %s\n", function_name);
    exit(0);
}

int main(void) {
    int qtd_anoes, qtd_cores, qtd_fotos, qtd_anoes_na_foto;
    int primeiro_anao, ultimo_anao, cor_mais_frequente;
    int *anoes = NULL;
    int *cores = NULL;
    int i, j;

    scanf("%d%d", &qtd_anoes, &qtd_cores);

    anoes = (int *) malloc(qtd_anoes * sizeof(int));
    if(anoes == NULL) error("main");

    cores = (int *) malloc(qtd_cores * sizeof(int));
    if(cores == NULL) error("main");

    for(i = 0; i < qtd_anoes; i++) {
        scanf("%d", &anoes[i]);
    }

    scanf("%d", &qtd_fotos);

    for(i = 0; i < qtd_fotos; i++) {
        scanf("%d%d", &primeiro_anao, &ultimo_anao);

        memset(cores, 0, qtd_cores * sizeof(int));

        for(j = primeiro_anao-1; j < ultimo_anao; j++) {
            cores[anoes[j]-1]++;
        }

        cor_mais_frequente = 0;
        for(j = 1; j < qtd_cores; j++) {
            if(cores[j] > cores[cor_mais_frequente]) cor_mais_frequente = j;
        }

        qtd_anoes_na_foto = ultimo_anao - primeiro_anao + 1;

        if(cores[cor_mais_frequente] > qtd_anoes_na_foto / 2.0) printf("bonita %d\n", cor_mais_frequente+1);
        else printf("feia\n");
    }

    free(anoes);
    free(cores);

    return 0;
}