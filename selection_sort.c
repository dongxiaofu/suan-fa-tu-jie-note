#include <stdio.h>
#include <stdlib.h>

int find_smallest(int *arr, int start, int size);

int *selection_sort(int arr[], int size);

int main() {
    int arr[4] = {9, 3, 10, 5};
    int *new_arr = selection_sort(arr, 4);
    for (int i = 0; i < 4; i++) {
        printf("%d\t", new_arr[i]);
    }
    return 0;
}

int find_smallest(int *arr, int start, int size) {
    int min = arr[start];
    int min_index = start;
    for (int i = start; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
            arr[i] = arr[min_index];
            min_index = i;
        }
    }
    return min;
}

int *selection_sort(int arr[], int size) {
    int *new_arr = (int *) malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        int min = find_smallest(arr, i, size);
        new_arr[i] = min;
    }
    return new_arr;
}