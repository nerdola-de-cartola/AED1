#include "data.h"

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