#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MENOR -1
#define IGUAL 0
#define MAIOR 1

enum Meses {Jan = 1, Fev, Mar, Abr, Mai, Jun, Jul, Ago, Set, Out, Nov, Dez};
enum DiasSemana {Dom = 1, Seg, Ter, Qua, Qui, Sex, Sab};

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

Data *criaData(int dia, int mes, int ano);

void erro(char *erro_msg);

Data *copiaData(Data *d);

void liberaData(Data *d);

Data *somaDiasData(Data *d, int dias);

int limiteMes(Data *d);

bool bissextoData(Data *d);

Data *subtrairDiasData(Data *d, int dias);

int obtemDiaData(Data *d);

int obtemMesData(Data *d);

int obtemAnoData(Data *d);

int comparaData(Data *d1, Data *d2);

int numeroDiasDatas(Data *d1, Data *d2);

int numeroMesesDatas(Data *d1, Data *d2);

int numeroAnosDatas(Data *d1, Data *d2);

void atribuirData(Data *d, int dia, int mes, int ano);

bool dataValida(int dia, int mes, int ano);

int obtemDiaSemanaData(Data *d);

char *imprimeData(Data *d, char *formato);

void printData(Data *d, char *formato);