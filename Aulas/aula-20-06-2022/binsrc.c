#include <stdio.h>

#define SIZ 6

int binSrc(int target, int * v, int start, int end);

int main(void) {
    int arr[SIZ] = {1, 2, 3, 4, 5, 6};
    int x = 0;
    printf("Encontrado o valor %d, na posição %d\n", x, binSrc(x, arr, 0, SIZ));
    return 0;
}

int binSrc(int target, int * v, int start, int end) {
    int mid;

    if(start == end && v[start != target]) return -1;
    mid = (end + start)/2;

    if(v[mid] == target) return mid;
    else if(v[mid] < target) {
        return binSrc(target, v, mid+1, end);
    } else {
        return binSrc(target, v, start, mid-1);
    }
}