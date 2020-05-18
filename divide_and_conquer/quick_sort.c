#include <stdlib.h>
#include <stdio.h>

int *quick_sort(int arr[], int size);

int *merge_arr(int less[], int less_size, int greater[], int greater_size, int pivot);

int main() {
    int arr[4] = {9, 10, 5, 100};
    printf("arr:\t");
    for (int i = 0; i < 4; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\nsorted arr:\t");
    int *new_arr = quick_sort(arr, 4);
    for (int i = 0; i < 4; i++) {
        printf("%d\t", new_arr[i]);
    }
    return 0;
}

int *quick_sort(int arr[], int size) {
    int *less = (int *) malloc(sizeof(int) * size);
    int less_couter = 0;
    int *greater = (int *) malloc(sizeof(int) * size);
    int greater_counter = 0;
    int pivot;
    if (size < 2) {
        return arr;
    } else {
        pivot = arr[0];
        // todo 若i的初始值是0，会出现错误。逻辑上确实如此。但究竟为何、在哪里导致了错误，我不能心算出来。
        // 有时间再理会
        for (int i = 1; i < size; i++) {
            if (arr[i] > pivot) {
                greater[greater_counter++] = arr[i];
            } else {
                less[less_couter++] = arr[i];
            }
        }
    }

    less = quick_sort(less, less_couter);
    greater = quick_sort(greater, greater_counter);

    return merge_arr(less, less_couter, greater, greater_counter, pivot);
}

int *merge_arr(int less[], int less_size, int greater[], int greater_size, int pivot) {
    int size = less_size + greater_size + 1;
    int *new_arr = (int *) malloc(size);
    int k = 0;
    for (int i = 0; i < less_size; i++) {
        new_arr[k++] = less[i];
    }
    new_arr[k++] = pivot;
    for (int i = 0; i < greater_size; i++) {
        new_arr[k++] = greater[i];
    }
    return new_arr;
}