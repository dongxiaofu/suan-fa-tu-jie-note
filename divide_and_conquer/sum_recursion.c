#include <stdio.h>
#include <stdlib.h>

int sum_recursion(int arr[], int size);

int *get_new_arr(int arr[], int size, int end);

int main() {
    int arr[4] = {5, 9,1,4};
    int sum = sum_recursion(arr, 4);
    printf("sum = %d\n", sum);
    return 0;
}

int sum_recursion(int arr[], int size) {
    if (size == 1) {
        return arr[0];
    } else {
        int *new_arr = get_new_arr(arr, size - 1, size);
        return arr[0] + sum_recursion(new_arr, size - 1);
    }
}

// 注意 size 和 end 的使用，可以去掉一个
int *get_new_arr(int arr[], int size, int end) {
    int *new_arr = (int *)malloc(sizeof(int)*(end-1));
    for(int i=1;i<end;i++){
        new_arr[i-1]=arr[i];
    }
    return new_arr;
}