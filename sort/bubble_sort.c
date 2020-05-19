#include <stdio.h>

void bubble_sort(int *arr, int size);

int main() {
    int arr[4] = {2, 1, 3, 5};
    for (int i = 0; i < 4; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
    bubble_sort(arr, 4);
    for (int i = 0; i < 4; i++) {
        printf("%d\t", arr[i]);
    }
    return 0;
}

void bubble_sort(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[i]) {
                int tmp = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp;
            }
        }
    }
}