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

void imprimeMenu();

void leData(Data *d);

int main(void) {
    int opcao, input;
    Data *a = criaData(1, 1, 1900), *b = criaData(1, 1, 1900);
    char *str = str = (char *) malloc(20*sizeof(char));;

    while(true) {
        imprimeMenu();
        strcpy(str, "ddmmaaaa");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            leData(a);

            printf("Digite uma quantidade de dias\n");
            scanf("%d", &input);

            liberaData(b);
            b = somaDiasData(a, input);
            printf("Data apos %d dias:\n", input);
            printData(b, str);

            break;
        case 2:
            leData(a);

            printf("Digite uma quantidade de dias\n");
            scanf("%d", &input);

            liberaData(b);
            b = subtrairDiasData(a, input);
            printf("Data %d dias antes:\n", input);
            printData(b, str);

            break;
        case 3:
            leData(a);

            if(bissextoData(a)) printf("O ano de %d foi bissexto\n", a->ano);
            else printf("O ano de %d não foi bissexto\n", a->ano);

            break;
        case 4:
            leData(a);
            leData(b);

            if(comparaData(a, b) == IGUAL) printf("Datas iguais\n");
            else if(comparaData(a, b) == MENOR) printf("A primeira data é a mais recente\n");
            else printf("A primeira data é a mais antiga\n");

            break;
        case 5:
            printf("Digite primeiro uma data mais recente e depois uma mais antiga\n");
            leData(a);
            leData(b);

            if(comparaData(a, b) == MAIOR) {
                printf("A primeira data tem que ser mais recente que a segunda\n");
                break;
            }

            printf("Diferença de dias: %d\n", numeroDiasDatas(a, b));

            break;
        case 6:
            printf("Digite primeiro uma data mais recente e depois uma mais antiga\n");
            leData(a);
            leData(b);

            if(comparaData(a, b) == MAIOR) {
                printf("A primeira data tem que ser mais recente que a segunda\n");
                break;
            }

            printf("Diferença de meses: %d\n", numeroMesesDatas(a, b));

            break;
        case 7:
            printf("Digite primeiro uma data mais recente e depois uma mais antiga\n");
            leData(a);
            leData(b);

            if(comparaData(a, b) == MAIOR) {
                printf("A primeira data tem que ser mais recente que a segunda\n");
                break;
            }

            printf("Diferença de anos: %d\n", numeroAnosDatas(a, b));

            break;
        case 8:
            leData(a);

            input = obtemDiaSemanaData(a);
            if(input == Dom) printf("Domingo\n");
            else if(input == Seg) printf("Segunda-feira\n");
            else if(input == Ter) printf("Terça-feira\n");
            else if(input == Qua) printf("Quarta-feira\n");
            else if(input == Qui) printf("Quinta-feira\n");
            else if(input == Sex) printf("Sexta-feira\n");
            else printf("Sábado\n");
    
            break;
        case 9:
            leData(a);

            printf("Digite o formato desejado\n");
            printf("ddmmaaaa\n");
            printf("aaaammdd\n");
            printf("dd\n");
            printf("mm\n");
            printf("aaaa\n");
            printf("ddmm\n");
            scanf("%s", str);

            printData(a, str);
    
            break;
        case 10:
            liberaData(a);
            liberaData(b);
            free(str);

            printf("Obrigado!\n");
    
            return 0;
        }
    }
}

void imprimeMenu() {
    printf("\n");
    printf("-------------------------------------\n");
    printf("1 - Soma dias a uma data\n");
    printf("2 - Subtrai dias a uma data\n");
    printf("3 - Verifique se uma data está em ano bissexto\n");
    printf("4 - Compara duas datas\n");
    printf("5 - Número de dias entre duas datas\n");
    printf("6 - Número de meses entre duas datas\n");
    printf("7 - Número de anos entre duas datas\n");
    printf("8 - Verifica o dia da semana de uma data\n");
    printf("9 - Imprime data\n");
    printf("10 - Sair\n");
    printf("-------------------------------------\n");
    printf("\n");
}

void leData(Data *d) {
    Data input; 
    printf("Digite uma data no formato \"dd mm aaaa\"\n");
    scanf("%d%d%d", &input.dia, &input.mes, &input.ano);

    if(!dataValida(input.dia, input.mes, input.ano)) {
        printf("Data inválida\n");
        leData(d);
    }

    atribuirData(d, input.dia, input.mes, input.ano);
}

Data *criaData(int dia, int mes, int ano) {
    Data *d = NULL;

    d = (Data *) malloc(sizeof(Data));
    if(d == NULL) erro("criaData");
    d->dia = dia;
    d->mes = mes;
    d->ano = ano;

    return d;
}

void erro(char *erro_msg) {
    printf("Erro na função %s\n", erro_msg);
    exit(0);
}

Data *copiaData(Data *d) {
    Data *copia = criaData(d->dia, d->mes, d->ano);
    return copia;
}

void liberaData(Data *d) {
    if(d == NULL) erro("liberaData");
    free(d);
}

Data *somaDiasData(Data *d, int dias) {
    Data *new = copiaData(d);
    Data *r = NULL;
    int limite_mes = limiteMes(d);

    if((d->dia + dias) <= limite_mes) {
        new->dia += dias;
        return new;
    }

    dias -= limite_mes - d->dia + 1;
    new->dia = 1;

    if(d->mes == Dez) {
        new->mes = Jan;
        new->ano++;
    } else new->mes++;

    r = somaDiasData(new, dias);
    liberaData(new);
    return r;
}

int limiteMes(Data *d) {
    if(
        d->mes == Jan ||
        d->mes == Mar ||
        d->mes == Mai ||
        d->mes == Jul ||
        d->mes == Ago ||
        d->mes == Out ||
        d->mes == Dez
    ) return 31;
    else if(
        d->mes == Abr ||
        d->mes == Jun ||
        d->mes == Set ||
        d->mes == Nov

    ) return 30;
    else if(bissextoData(d)) return 29;
    else return 28;
}

bool bissextoData(Data *d) {
    if(d->ano%400 == 0) return true;
    else if(d->ano%4 == 0 && d->ano%100 != 0) return true;
    return false;
}

Data *subtrairDiasData(Data *d, int dias) {
    Data *new = copiaData(d);
    Data *r = NULL;
    int limite_mes;

    if((d->dia - dias) >= 1) {
        new->dia -= dias;
        return new;
    }

    if(d->mes == Jan) {
        new->mes = Dez;
        new->ano--;
    } else new->mes--;

    limite_mes = limiteMes(new);
    dias -= d->dia;
    new->dia = limite_mes;

    r = subtrairDiasData(new, dias);
    liberaData(new);
    return r;
}

int obtemDiaData(Data *d) {
    return d->dia;
}

int obtemMesData(Data *d) {
    return d->mes;
}

int obtemAnoData(Data *d) {
    return d->ano;
}

int comparaData(Data *d1, Data *d2) {
    if(d1->ano > d2->ano) return MENOR;
    else if(d1->ano < d2->ano) return MAIOR;
    if(d1->mes > d2->mes) return MENOR;
    else if(d1->mes < d2->mes) return MAIOR;
    if(d1->dia > d2->dia) return MENOR;
    else if(d1->dia < d2->dia) return MAIOR;
    return IGUAL;
}

int numeroDiasDatas(Data *d1, Data *d2) {
    Data *new = NULL;
    int dif = 0;

    if(comparaData(d1, d2) == MAIOR) erro("numeroDiasDatas");

    if(d1->mes == d2->mes && d1->ano == d2->ano) {
        dif += d1->dia - d2->dia;
        return dif;
    }

    new = subtrairDiasData(d1, d1->dia);
    dif += d1->dia;
    dif += numeroDiasDatas(new, d2);
    liberaData(new);
    return dif;
}

int numeroMesesDatas(Data *d1, Data *d2) {
    Data *new = NULL;
    int dif = 0;

    if(comparaData(d1, d2) == MAIOR) erro("numeroMesesDatas");

    if(d1->ano == d2->ano) {
        dif += d1->mes - d2->mes;
        return dif;
    }

    new = criaData(31, 12, d1->ano - 1);
    dif += d1->mes;
    dif += numeroMesesDatas(new, d2);
    liberaData(new);
    return dif;
}

int numeroAnosDatas(Data *d1, Data *d2) {
    if(comparaData(d1, d2) == MAIOR) erro("numeroAnosDatas");
    return d1->ano - d2->ano;
}

void atribuirData(Data *d, int dia, int mes, int ano) {
    if(!dataValida(dia, mes, ano)) { 
        d = NULL;
        return;
    }

    d->dia = dia;
    d->mes = mes;
    d->ano = ano;
}

bool dataValida(int dia, int mes, int ano) {
    Data *d = criaData(dia, mes, ano);;
    bool valida = true;
    
    if(ano < 0) valida = false;
    else if(mes < Jan || mes > Dez) valida = false;
    else if(dia < 1 || dia > limiteMes(d)) valida = false;

    liberaData(d);
    return valida;
}

int obtemDiaSemanaData(Data *d) {
    Data *tmp = NULL;
    int w, dif, i;

    tmp = criaData(1, 1, 1900);
    if(comparaData(d, tmp) == MAIOR) erro("obtemDiaSemanaData");

    dif = numeroDiasDatas(d, tmp);
    liberaData(tmp);
    w = Seg;
    for(i = 0; i < dif; i++) {
        if(w == Sab) w = Dom;
        else w++;
    }

    return w;
}

char *imprimeData(Data *d, char *formato) {
    char *str = NULL;

    str = (char *) malloc(20*sizeof(char));
    if(formato == NULL) erro("imprimeData");
    else if(strcmp(formato, "ddmmaaaa") == 0) sprintf(str, "%02d/%02d/%04d", d->dia, d->mes, d->ano);
    else if(strcmp(formato, "aaaammdd") == 0) sprintf(str, "%04d/%02d/%02d", d->ano, d->mes, d->dia);
    else if(strcmp(formato, "aaaa") == 0) sprintf(str, "%04d", d->ano);
    else if(strcmp(formato, "mm") == 0) sprintf(str, "%02d", d->mes);
    else if(strcmp(formato, "dd") == 0) sprintf(str, "%02d", d->dia);
    else if(strcmp(formato, "ddmm") == 0) sprintf(str, "%02d/%02d", d->dia, d->mes);
    else erro("imprimeData");

    return str;
}

void printData(Data *d, char *formato) {
    char *str = NULL;

    str = imprimeData(d, formato);
    printf("%s\n", str);
    free(str);
}