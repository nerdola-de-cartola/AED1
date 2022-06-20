#include <stdio.h>

int main(void) {
    int consumer, type;
    double consumption, price;

    scanf("%d", &consumer);
    if(consumer <= 0 || consumer >= 100000000) {
        printf("O numero da conta deve estar entre 1 e 999999999 – programa cancelado\n");
        return 0;
    }

    scanf("%d", &type);
    if(type <= 0 || type >= 4) {
        printf("O tipo de consumidor deve ser 1 ou 2 ou 3 – programa cancelado\n");
        return 0;
    }

    scanf("%lf", &consumption);
    if(consumption < 0) {
        printf("O consumo deve ser maior ou igual a zero – programa cancelado\n");
        return 0;
    }

    if(type == 1) {
        price = 5.0 + (0.05*consumption);
    } else if(type == 2) {
        if(consumption <= 80) {
            price = 500.0;
        } else {
            price = 500.0;
            price += 0.03*(consumption-80);
        }
    } else if(type == 3) {
        if(consumption <= 100) {
            price = 800.0;
        } else {
            price = 800;
            price += 0.04*(consumption-100);
        }
    }

    printf("Valor a ser pago para a conta informada: R$ %.2lf\n", price);
    return 0;
}