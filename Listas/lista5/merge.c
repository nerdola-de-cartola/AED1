/**
 * @brief Merge two subarrays left[first... middle] and rigth[middle+1... last] into arr 
 * 
 * @param arr Array to be merged
 * @param first First index of the left array
 * @param middle Middle is the last index of left array and middle+1 is the first index of right array
 * @param last Last index of right array
 */
void merge(int arr[], int first, int middle, int last) {
    // Create left[first... middle]
    int size_left = middle - first + 1;
    int left[size_left];
    for(int i = 0; i < size_left; i++) left[i] = arr[first + i];

    // Create right[middle+1... last]
    int size_right = last - middle;
    int right[size_right];
    for(int i = 0; i < size_right; i++) right[i] = arr[middle + 1 + i];


    // Maintain current index of sub-arrays and main array
    int index_left = 0;
    int index_right = 0;
    int index_arr = first;

    // Until we reach either end of either left or right, pick larger among
    // elements left and right and place them in the correct position at A[first..last]
    while (index_left < size_left && index_right < size_right) {
        if (left[index_left] <= right[index_right]) {
            arr[index_arr] = left[index_left];
            index_left++;
        } else {
            arr[index_arr] = right[index_right];
            index_right++;
        }

        index_arr++;
    }

    // When we run out of elements in either left or right,
    // pick up the remaining elements and put in A[first..last]
    while (index_left < size_left) {
        arr[index_arr] = left[index_left];
        index_left++;
        index_arr++;
    }

    while (index_right < size_right) {
        arr[index_arr] = right[index_right];
        index_right++;
        index_arr++;
    }
}

/**
 * @brief Divide the array into two subarrays, sort them and merge them
 * 
 * @param arr Array to be sorted 
 * @param first First index of arr
 * @param last Last index of arr
 */
void mergeSort(int *arr, int first, int last) {
    if(first < last) {
        // middle is the point where the array is divided into two subarrays
        int middle = first + (last - first) / 2;

        mergeSort(arr, first, middle);
        mergeSort(arr, middle + 1, last);

        // Merge the sorted subarrays
        merge(arr, first, middle, last);
    }
}