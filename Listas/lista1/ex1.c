#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double pos;
    double vel;
} Carro;

void erro();

int main(void) {
    Carro a, b;
    double tempo_encontro, pos_encontro;

    scanf("%lf", &b.pos);
    if(b.pos <= 0) erro();

    scanf("%lf", &a.vel);
    if(a.vel <= 0) erro();
    a.pos = 0;

    scanf("%lf", &b.vel);
    if(b.vel <= 0) erro();
    b.vel = -b.vel;

    tempo_encontro = (b.pos - a.pos) / (a.vel - b.vel);
    pos_encontro = a.pos + (a.vel * tempo_encontro);

    printf("%.2lf\n", tempo_encontro);
    printf("%.1lf\n", pos_encontro);
    
    return 0;
}

void erro() {
    printf("erro\n");
    exit(0);
}