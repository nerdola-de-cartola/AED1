#include <stdio.h>
#include <stdlib.h>

void selectionSort(int *arr, int size, int *changes) {
    int i, j;

    for(i = 0; i < size - 1; i++) {
        int menor = i;

        for(j = i+1; j < size; j++) {
            if(arr[j] < arr[menor]) menor = j;
        }

        if(menor != i) {
            int tmp = arr[i];
            arr[i] = arr[menor];
            arr[menor] = tmp;
            (*changes)++;
        }
    }
}

void insertionSort(int *arr, int size, int value, int *changes) {
    int i, j, tmp1, tmp2;

    for(i = 0; i < size; i++) {
        if(arr[i] > value) {
            for(j = size; j >= i; j--) {
                arr[j] = arr[j-1];
                (*changes)++;
            }
            arr[i] = value;

            return;
        }
    }

    arr[size] = value;
    (*changes)++;
}

int main(void) {
    int n, i;
    scanf("%d", &n);

    int select[n];
    int select_changes = 0;
    for(i = 0; i < n; i++) scanf("%d", &select[i]);

    int insert[n];
    int insert_changes = 0;
    for(i = 0; i < n; i++) insertionSort(insert, i, select[i], &insert_changes);

    selectionSort(select, n, &select_changes);
    
    printf("%d\n", insert_changes - select_changes - 1);

    return 0;
}
