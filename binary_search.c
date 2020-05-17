#include <stdio.h>

int binary_search(int guess, int arr[], int size);

int main() {
    int arr[6] = {1, 2, 3, 4, 5, 6};
    int guess = binary_search(5, arr, 6);
    printf("guess = %d\n", guess);
    return 0;
}

int binary_search(int guess, int arr[], int size) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {   // 终止条件，包括等于
        int mid_index = (high + low) / 2;   // 是+而不是-
        int mid = arr[mid_index];
        if (guess == mid) {
            return mid_index;
        } else if (guess < mid) {
            high = mid_index - 1;
        } else if (guess > mid) {
            low = mid_index + 1;
        }
    }

    return -1;
}