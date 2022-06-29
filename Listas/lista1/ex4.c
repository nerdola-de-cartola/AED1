#include <stdio.h>

int main(void) {
    double initial_application, interest_rate, commission, amount, income;
    int years, i;

    scanf("%lf", &initial_application);
    if(initial_application <= 0) {
        printf("erro\n");
        return 0;
    }

    scanf("%d", &years);
    if(years <= 0) {
        printf("erro\n");
        return 0;
    }

    scanf("%lf", &interest_rate);
    if(interest_rate <= 0 || interest_rate >= 100) {
        printf("erro\n");
        return 0;
    }

    scanf("%lf", &commission);
    if(commission <= 0 || commission >= 100) {
        printf("erro\n");
        return 0;
    }

    amount = initial_application;
    for(i = 1; i <= years; i++) {
        income = amount * interest_rate/100;
        amount += income;
        amount -= income * commission/100;
        printf("%.2lf\n", amount);
    }
    
    return 0;
}