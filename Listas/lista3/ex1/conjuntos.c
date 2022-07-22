#include "conjuntos.h"

bool criaConjunto(Conjunto * c) {
    c->size = 0;
    c->vet = NULL;

    return true;
}

bool conjuntoVazio(Conjunto * c) {
    if(c->size == 0) return true;
    return false;
}

bool insereElementoConjunto(Conjunto * c, unsigned int value) {
    unsigned int * tmp = NULL;
    
    if(pertenceConjunto(c, value)) return falha;

    tmp = (unsigned int *) realloc(c->vet, (c->size+1) * (sizeof(unsigned int)));
    if(tmp == NULL) return falha;
    c->vet = tmp;
    c->size++;
    c->vet[c->size-1] = value;

    return sucesso;
}

bool pertenceConjunto(Conjunto * c, unsigned int value) {
    int i;

    for(i = 0; i < c->size; i++) {
        if(c->vet[i] == value) return true;
    }

    return false;
}

bool excluirElementoConjunto(Conjunto * c, unsigned int value) {
    Conjunto new;
    int i, j;
    
    if(!pertenceConjunto(c, value)) return falha;

    criaConjunto(&new);
    new.vet = (unsigned int *) malloc((c->size - 1) * sizeof(unsigned int));
    if(new.vet == NULL) return falha;
    new.size = c->size - 1;
    
    for(i = 0, j = 0; j < new.size; i++) {
        if(c->vet[i] == value) continue;

        new.vet[j] = c->vet[i];
        j++;
    }

    free(c->vet);
    c->vet = new.vet;
    c->size = new.size;

    return sucesso;
}

bool conjuntosIdenticos(Conjunto * c1, Conjunto * c2) {
    if(c1->size != c2->size) return false;

    int i;
    for(i = 0; i < c1->size; i++) {
        if(c1->vet[i] != c2->vet[i]) return false;
    }

    return true;
}

unsigned int tamanhoConjunto(Conjunto * c) {
    return c->size;
}

bool subconjunto(Conjunto * c1, Conjunto * c2) {
    int i;
    for(i = 0; i < c1->size; i++) {
        if(!pertenceConjunto(c2, c1->vet[i])) return false;
    }

    return true;
}

Conjunto diferenca(Conjunto * c1, Conjunto * c2) {
    Conjunto dif;
    unsigned int * tmp = NULL;
    int i;

    criaConjunto(&dif);

    dif.vet = (unsigned int *) malloc(c1->size * sizeof(unsigned int));
    if(dif.vet == NULL) {
        printf("Erro no malloc, função diferença\n");
        exit(0);
    }

    for(i = 0; i < c1->size; i++) {
        if(pertenceConjunto(c2, c1->vet[i])) continue;

        dif.size++;
        dif.vet[dif.size-1] = c1->vet[i];
    }

    if(dif.size == 0) {
        destroiConjunto(&dif);
        return dif;
    }

    tmp = (unsigned int *) realloc(dif.vet, dif.size * sizeof(unsigned int));
    if(tmp == NULL) {
        printf("Erro em realloc, função: diferença\n");
        exit(0);
    }
    dif.vet = tmp;

    return dif;
}

void mostraConjunto(Conjunto * c, Ordem o) {
    ordenaConjunto(c, o);

    int i;
    for(i = 0; i < c->size; i++) {
        printf("%d ", c->vet[i]);
    }

    printf("\n");
}

void ordenaConjunto(Conjunto * c, Ordem o) { 
    int i, j, min, max, tmp;

    if(conjuntoVazio(c)) return;

    if(o == CRESCENTE) {
        for(i = 0; i < c->size-1; i++) {
            // Coloca o elemento atual como o mínimo
            min = i;

            // Encontra o verdadeiro mínimo
            for(j = i+1; j < c->size; j++) {
                if(c->vet[j] < c->vet[min]) min = j;
            }

            // Troca o mínimo de lugar com o elemento atual
            if(min != i) {
                tmp = c->vet[i];
                c->vet[i] = c->vet[min];
                c->vet[min] = tmp;
            }
        }
    } else if(o == DECRESCENTE) {
        for(i = 0; i < c->size-1; i++) {
            // Coloca o elemento atual como o máximo
            max = i;

            // Encontra o verdadeiro máximo
            for(j = i+1; j < c->size; j++) {
                if(c->vet[j] > c->vet[max]) max = j;
            }

            // Troca o máximo de lugar com o elemento atual
            if(max != i) {
                tmp = c->vet[i];
                c->vet[i] = c->vet[max];
                c->vet[max] = tmp;
            }
        }
    }
}

bool destroiConjunto(Conjunto * c) {
    free(c->vet);
    c->vet = NULL;
    c->size = 0;

    return sucesso;
}

bool copiarConjunto(Conjunto * c1, Conjunto * c2) {
    criaConjunto(c2);

    unsigned int * tmp = NULL;

    tmp = (unsigned int *) malloc(c1->size * sizeof(unsigned int));
    if(tmp == NULL) return falha;

    c2->vet = tmp;
    for(c2->size = 1; c2->size <= c1->size; c2->size++) {
        c2->vet[c2->size-1] = c1->vet[c2->size-1];
    }
    
    c2->size--;
    tmp = NULL;

    return sucesso;
}

Conjunto complemento(Conjunto * c1, Conjunto * c2) {
    return diferenca(c2, c1);
}

Conjunto uniao(Conjunto * c1, Conjunto * c2) {
    Conjunto uni;
    unsigned int * tmp = NULL;
    int i;

    criaConjunto(&uni);

    uni.vet = (unsigned int *) malloc((c1->size + c2->size) * sizeof(unsigned int));
    if(uni.vet == NULL) {
        printf("Erro no malloc, função união\n");
        exit(0);
    }

    for(i = 0; i < c1->size; i++) {
        uni.size++;
        uni.vet[uni.size-1] = c1->vet[i];
    }

    for(i = 0; i < c2->size; i++) {
        if(pertenceConjunto(&uni, c2->vet[i])) continue;

        uni.size++;
        uni.vet[uni.size-1] = c2->vet[i];
    }

    if(uni.size == 0) {
        destroiConjunto(&uni);
        return uni;
    }

    tmp = (unsigned int *) realloc(uni.vet, uni.size * sizeof(unsigned int));
    if(tmp == NULL) {
        printf("Erro em realloc, função: união\n");
        exit(0);
    }
    uni.vet = tmp;

    return uni;
}

Conjunto interseccao(Conjunto * c1, Conjunto * c2) {
    Conjunto inter;
    unsigned int * tmp = NULL;
    int i, menor;
    bool c1_menor;

    criaConjunto(&inter);

    menor = c1->size;
    c1_menor = true;
    if(c2->size < menor) {
        menor = c2->size;
        c1_menor = false;
    }

    inter.vet = (unsigned int *) malloc(menor * sizeof(unsigned int));
    if(inter.vet == NULL) {
        printf("Erro no malloc, função intersecção\n");
        exit(0);
    }
    
    if(c1_menor) {
        for(i = 0; i < c1->size; i++) {
            if(!pertenceConjunto(c2, c1->vet[i])) continue;

            inter.size++;
            inter.vet[inter.size-1] = c1->vet[i];
        }
    } else {
        for(i = 0; i < c2->size; i++) {
            if(!pertenceConjunto(c1, c2->vet[i])) continue;

            inter.size++;
            inter.vet[inter.size-1] = c2->vet[i];
        }
    }

    if(inter.size == 0) {
        destroiConjunto(&inter);
        return inter;
    }

    tmp = (unsigned int *) realloc(inter.vet, inter.size * sizeof(unsigned int));
    if(tmp == NULL) {
        printf("Erro em realloc, função: intersecção\n");
        exit(0);
    }
    inter.vet = tmp;

    return inter;
}

int maior(Conjunto * c, unsigned int value) {
    int i, count;

    for(i = 0, count = 0; i < c->size; i++) {
        if(c->vet[i] > value) count++;
    }

    if(count == 0) return -1;
    else if(count == c->size) return 0;
    return count;
}

int menor(Conjunto * c, unsigned int value) {
    int i, count;

    for(i = 0, count = 0; i < c->size; i++) {
        if(c->vet[i] < value) count++;
    }

    if(count == 0) return -1;
    else if(count == c->size) return 0;
    return count;
}

Conjunto * conjuntoPartes(Conjunto * c) {
    Conjunto * cp = NULL;
    bool * regra = NULL;
    long long int num_comb;
    int i;
    
    regra = (bool *) malloc(c->size * sizeof(bool));
    if(regra == NULL) {
        printf("Erro em malloc, função conjuntoPartes\n");
        exit(0);
    }
    for(i = 0; i < c->size; i++) {
        regra[i] = false;
    }

    num_comb = pow(2, c->size);
    cp = (Conjunto *) malloc(num_comb * sizeof(Conjunto));
    if(cp == NULL) {
        printf("Erro em malloc, função conjuntoPartes\n");
        exit(0);
    }

    criaParte(cp, c, regra, 0);
    free(regra);

    return cp;
}

void criaParte(Conjunto * cp, Conjunto * c, bool * regra, unsigned int parte) {
    if(parte == pow(2, c->size)) return;

    Conjunto p;
    int i, j;

    criaConjunto(&p);
    for(i = 0; i < c->size; i++) {
        if(regra[i]) p.size++;
    }

    if(p.size != 0) {
        p.vet = (unsigned int *) malloc(p.size * sizeof(unsigned int));
        if(p.vet == NULL) {
            printf("Erro em malloc, função criaParte\n");
            exit(0);
        }

        for(i = 0, j = 0; j < p.size; i++) {
            if(regra[i]) {
                p.vet[j] = c->vet[i];
                j++;
            }
        }
    }

    cp[parte] = p;
    mudaCombinacao(regra, c->size);
    criaParte(cp, c, regra, parte+1);
}

void mudaCombinacao(bool * regra, unsigned int size) {
    int i;
    int ultima_posicao_inativa = 0;

    //Encontra a última posicao inativa
    for(i = size-1; i >= 0; i--) {
        if(!regra[i]) {
            ultima_posicao_inativa = i;
            break;
        }
    }

    //Ativa a última posicao inativa
    regra[ultima_posicao_inativa] = true;

    //Ativa as posições posteriores
    for(i = ultima_posicao_inativa + 1; i < size; i++) {
        regra[i] = false;
    }
}