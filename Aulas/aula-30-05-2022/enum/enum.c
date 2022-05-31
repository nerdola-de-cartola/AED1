#include <stdio.h>

int main(void) {
    typedef enum {Seg, Ter, Qua, Qui, Sex, Sab, Dom} Semana;

    Semana s;

    printf("%ld\n", sizeof s);

    s = Seg;
}