#include <stdio.h>

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int partition(int arr[], int first, int last) {
	int i, pivot, greater;

	pivot = last;
	greater = first;

	for(i = first; i < last; i++) {
		if(arr[i] <= arr[pivot]) {
			swap(&arr[i], &arr[greater]);
			greater++;
		}
	}

	swap(&arr[pivot], &arr[greater]);
	return greater;
}

void quickSort(int arr[], int first, int last) {
	if(first >= last) return;

	int pivot = partition(arr, first, last);

	quickSort(arr, first, pivot-1);
	quickSort(arr, pivot+1, last);
}

int main(void) {
	int l, k, n, i, sum;

	scanf("%d", &n);
	int arr[n];

	for(i = 0; i < n; i++) scanf("%d", &arr[i]);

	quickSort(arr, 0, n-1);

	scanf("%d%d", &l, &k);
	printf("%d\n", arr[l-1] + arr[k-1]);

	return 0;
}