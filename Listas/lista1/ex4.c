#include <stdio.h>

int main(void) {
    double initial_application, interest_rate, commission, amount, income;
    int years, i;

    scanf("%lf", &initial_application);
    if(initial_application <= 0) {
        printf("O valor do capital inicial deve ser maior do que 0 – programa cancelado\n");
        return 0;
    }

    scanf("%d", &years);
    if(years <= 0) {
        printf("O valor do número de anos deve ser inteiro e maior do que 0 – programa cancelado\n");
        return 0;
    }

    scanf("%lf", &interest_rate);
    if(interest_rate <= 0 || interest_rate >= 100) {
        printf("O valor da taxa de juros deve ser maior do que 0 e menor do que 100 – programa cancelado\n");
        return 0;
    }

    scanf("%lf", &commission);
    if(commission <= 0 || commission >= 100) {
        printf("O valor da taxa de administracao deve ser maior do que 0 e menor do que 100 – programa cancelado\n");
        return 0;
    }

    amount = initial_application;
    for(i = 1; i <= years; i++) {
        income = amount * interest_rate/100;
        amount += income;
        amount -= income * commission/100;
        printf("Capital resultante no final do ano %d: R$ %.2lf\n", i, amount);
    }
    
    return 0;
}