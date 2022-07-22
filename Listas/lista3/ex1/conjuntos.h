#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define sucesso true
#define falha false
#define CRESCENTE 0
#define DECRESCENTE 1

typedef int Ordem;

typedef struct {
    unsigned int * vet;
    unsigned int size;
} Conjunto;

bool criaConjunto(Conjunto * c);

bool conjuntoVazio(Conjunto * c);

bool insereElementoConjunto(Conjunto * c, unsigned int value);

bool pertenceConjunto(Conjunto * c, unsigned int value);

bool excluirElementoConjunto(Conjunto * c, unsigned int value);

bool conjuntosIdenticos(Conjunto * c1, Conjunto * c2);

unsigned int tamanhoConjunto(Conjunto * c);

bool subconjunto(Conjunto * c1, Conjunto * c2);

Conjunto diferenca(Conjunto * c1, Conjunto * c2);

void mostraConjunto(Conjunto * c, Ordem o);

void ordenaConjunto(Conjunto * c, Ordem o);

bool destroiConjunto(Conjunto * c);

bool copiarConjunto(Conjunto * c1, Conjunto * c2);

Conjunto complemento(Conjunto * c1, Conjunto * c2);

Conjunto uniao(Conjunto * c1, Conjunto * c2);

Conjunto interseccao(Conjunto * c1, Conjunto * c2);

int maior(Conjunto * c, unsigned int value);

int menor(Conjunto * c, unsigned int value);

Conjunto * conjuntoPartes(Conjunto * c);

void criaParte(Conjunto * cp, Conjunto * c, bool * regra, unsigned int parte);

void mudaCombinacao(bool * regra, unsigned int size);
