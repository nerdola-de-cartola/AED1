#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int gold;
    int silver;
    int bronze;
} Medal;

typedef struct {
    Medal p;
    int number;
} Country;

void swap(Country arr[], int i, int j) {
    Country tmp;

    tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

bool compareMedals(Medal a, Medal b) {
    if(a.gold > b.gold) return true;

    if(a.gold == b.gold) {
        if(a.silver > b.silver) return true;

        if(a.silver == b.silver) {
            if(a.bronze > b.bronze) return true;
        }
    }

    return false;
}

void bubbleSort(Country arr[], int size) {
    int i, step, tmp;
    
    for(step = 0; step < size - 1; step++) {
        for(i = 0; i < size - step - 1; i++) {      
            if(!compareMedals(arr[i].p, arr[i + 1].p)) swap(arr, i, i+1);
        }
    }
}

int main(void) {
    Country *countries = NULL;
    Medal winner;
    int num_countries, num_modalities;
    int i;

    scanf("%d%d", &num_countries, &num_modalities);
    
    countries = (Country *) malloc(num_countries * sizeof(Country));
    if(countries == NULL) return 1;

    for(i = 0; i < num_countries; i++) {
        countries[i].number = i+1;
        countries[i].p.gold = 0;
        countries[i].p.silver = 0;
        countries[i].p.bronze = 0;
    }

    for(i = 0; i < num_modalities; i++) {
        scanf("%d%d%d", &winner.gold, &winner.silver, &winner.bronze);
        countries[winner.gold - 1].p.gold++;
        countries[winner.silver - 1].p.silver++;
        countries[winner.bronze - 1].p.bronze++;
    }

    bubbleSort(countries, num_countries);

    for(i = 0; i < num_countries; i++) printf("%d ", countries[i].number);
    printf("\n");

    return 0;
}