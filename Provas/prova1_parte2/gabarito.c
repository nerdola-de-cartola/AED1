#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int x;
    int y;
    int largura;
    int altura;
} Estado_Janela;

typedef struct Janela {
    int x;
    int y;
    int largura;
    int altura;
    int qtd_estados;
    Estado_Janela *estados;
} Janela;

bool AbrirJanela(Janela **w);
void imprimeJanela(Janela *w, int c);
bool FecharJanela(Janela **w);
bool RedimensionarJanela(Janela *w, int largura, int altura);
bool MoverJanela(Janela *w, int x, int y);
bool adicionaEstado(Janela *w);
bool DesfazerUltimaOperacao(Janela *w);
bool retiraEstado(Janela *w);
void menu();
void imprimeJanelas(Janela **v, int qtd);

int main(void) {
    Janela **v = NULL;
    Janela **tmp = NULL;
    int m, input1, input2, i, qtd, j, k;

    v = (Janela **) malloc(sizeof(Janela *));
    qtd = 1;
    AbrirJanela(&v[qtd-1]);

    while(true) {
        imprimeJanelas(v, qtd);
        menu();
        scanf("%d", &m);

        switch (m) {
        case 0:
            tmp = (Janela **) realloc(v, (qtd+1) * sizeof(Janela *));
            if(tmp == NULL) {
                printf("Não é possível criar mais janelas\n");
                break;
            }

            v = tmp;
            qtd++;
            AbrirJanela(&v[qtd-1]);
            break;
        case 1:
            printf("Digite qual janela deseja escolher\n");
            scanf("%d", &i);
            if(i < 0 || i >= qtd) {
                printf("Escolha inválida\n");
                break;
            }
            printf("Digite a nova largura e depois a nova altura da janela\n");
            scanf("%d%d", &input1, &input2);
            if(!RedimensionarJanela(v[i], input1, input2)) printf("Não foi possível redimensionar a janela\n");
            break;
        case 2:
            printf("Digite qual janela deseja escolher\n");
            scanf("%d", &i);
            if(i < 0 || i >= qtd) {
                printf("Escolha inválida\n");
                break;
            }
            printf("Digite a nova posição no eixo x e depois a nova posição no eixo y da janela\n");
            scanf("%d%d", &input1, &input2);
            if(!MoverJanela(v[i], input1, input2)) printf("Não foi possível mover a janela\n");
            break;
        case 3:
            printf("Digite qual janela deseja escolher\n");
            scanf("%d", &i);
            if(i < 0 || i >= qtd) {
                printf("Escolha inválida\n");
                break;
            }
            if(!DesfazerUltimaOperacao(v[i])) printf("Não foi possível desfazer a última operação\n");
            break;
        case 4:
            printf("Digite qual janela deseja escolher\n");
            scanf("%d", &i);
            if(i < 0 || i >= qtd) {
                printf("Escolha inválida\n");
                break;
            }

            FecharJanela(&v[i]);

            k = 0;
            for(j = 0; j < qtd; j++) {
                if(j == i) continue;
                v[k] = v[j];
                k++;
            }

            tmp = (Janela **) realloc(v, (qtd-1) * sizeof(Janela *));
            if(tmp == NULL) {
                printf("Não é possível fechar a janelas\n");
                break;
            }

            v = tmp;
            qtd--;

            break;
        case 5:
            for(i = 0; i < qtd; i++) {
                FecharJanela(&v[i]);
            }
            free(v);
            printf("Obrigado por utilizar o sistema\n");
            return 0;
        }
    }
}

bool AbrirJanela(Janela **w) {
    *w = (Janela *) malloc(sizeof(Janela));
    if(*w == NULL) return false;

    (*w)->x = 0;
    (*w)->y = 0;
    (*w)->largura = 0;
    (*w)->altura = 0;
    (*w)->qtd_estados = 0;
    (*w)->estados = NULL;

    return true;
}

void imprimeJanela(Janela *w, int c) {
    if(w == NULL) return;
    printf("\n");
    printf("-------------------------------\n");
    printf("Código da janela: %d\n", c);
    printf("Posição: (%d, %d)\n", w->x, w->y);
    printf("Largura: %d\n", w->largura);
    printf("Altura: %d\n", w->altura);
    printf("-------------------------------\n");
    printf("\n");
}

bool FecharJanela(Janela **w) {
    if((*w) == NULL) return false;
    if((*w)->qtd_estados == -1) return false;

    if((*w)->estados != NULL) free((*w)->estados);
    (*w)->qtd_estados = 0;

    free(*w);
    
    *w = NULL;
    return true;
}

bool RedimensionarJanela(Janela *w, int largura, int altura) {
    if(w == NULL) return false;
    if(largura < 0 || altura < 0) return false;

    adicionaEstado(w);
    w->largura = largura;
    w->altura = altura;

    return true;
}

bool MoverJanela(Janela *w, int x, int y) {
    if(w == NULL) return false;

    if(x < 0 || y < 0) return false;

    adicionaEstado(w);
    w->x = x;
    w->y = y;

    return true;
}

bool adicionaEstado(Janela *w) {
    Estado_Janela *tmp = NULL;

    if(w == NULL) return false;

    if(w->qtd_estados == 0) {
        w->estados = (Estado_Janela *) malloc(sizeof(Estado_Janela));
        if(w->estados == NULL) return false;
    } else {
        tmp = (Estado_Janela *) realloc(
            w->estados,
            (w->qtd_estados+1) * sizeof(Estado_Janela)
        );
        if(tmp == NULL) return false;
        w->estados = tmp;
    }

    w->qtd_estados++;
    w->estados[w->qtd_estados-1].x = w->x;
    w->estados[w->qtd_estados-1].y = w->y;
    w->estados[w->qtd_estados-1].largura = w->largura;
    w->estados[w->qtd_estados-1].altura = w->altura;

    return true;
}

bool DesfazerUltimaOperacao(Janela *w) {
    if(w == NULL) return false;
    if(w->qtd_estados <= 0) return false;

    w->x = w->estados[w->qtd_estados-1].x;
    w->y = w->estados[w->qtd_estados-1].y;
    w->largura = w->estados[w->qtd_estados-1].largura;
    w->altura = w->estados[w->qtd_estados-1].altura;

    return retiraEstado(w);
}

bool retiraEstado(Janela *w) {
    Estado_Janela *tmp = NULL;

    if(w == NULL) return false;
    if(w->qtd_estados <= 0) return false;

    if(w->qtd_estados == 1) {
        free(w->estados);
        w->estados = NULL;
    } else {
        tmp = (Estado_Janela *) realloc(
            w->estados,
            (w->qtd_estados-1) * sizeof(Estado_Janela)
        );
        if(tmp == NULL) return false;
        w->estados = tmp;
    }

    w->qtd_estados--;
    return true;

}

void menu() {
    printf("\n");
    printf("-------------------------------\n");
    printf("Digite a opção desejada\n\n");
    printf("0 - Criar nova janela\n");
    printf("1 - Redimensionar janela\n");
    printf("2 - Reposicionar janela\n");
    printf("3 - Desfazer última operação\n");
    printf("4 - Fechar janela\n");
    printf("5 - Sair\n");
    printf("-------------------------------\n");
    printf("\n");
}

void imprimeJanelas(Janela **v, int qtd) {
    int i;

    for(i = 0; i < qtd; i++) {
        imprimeJanela(v[i], i);
    }
}