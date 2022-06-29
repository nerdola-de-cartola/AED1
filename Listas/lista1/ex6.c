#include <stdio.h>

int main(void) {
    int consumer, type;
    double consumption, price;

    scanf("%d", &consumer);
    if(consumer <= 0 || consumer >= 100000000) {
        printf("erro\n");
        return 0;
    }

    scanf("%d", &type);
    if(type <= 0 || type >= 4) {
        printf("erro\n");
        return 0;
    }

    scanf("%lf", &consumption);
    if(consumption < 0) {
        printf("erro\n");
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

    printf("%.2lf\n", price);
    return 0;
}