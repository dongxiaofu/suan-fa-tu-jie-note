## 快速排序

```
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
    if (size <= 1) {
        return arr;
    } else {
        int pivot = arr[0];
        // 如何存储大小未知的数组呢？我使用这种浪费内存的方法
        int *less = (int *) malloc(size * sizeof(int));
        int less_counter = 0;
        int *greater = (int *) malloc(size * sizeof(int));
        int greater_couter = 0;
        for (int i = 1; i < size; i++) {
            if (arr[i] > pivot) {
                greater[greater_couter++] = arr[i];
            } else {
                less[less_counter++] = arr[i];
            }
        }
        less = quick_sort(less, less_counter);
        greater = quick_sort(greater, greater_couter);
        return merge_arr(less, less_counter, greater, greater_couter, pivot);
    }
}

int *merge_arr(int less[], int less_size, int greater[], int greater_size, int pivot) {
    int size = less_size + greater_size + 1;
    int *new_arr = (int *) malloc(sizeof(int) * size);
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
```

将数组分为大小两堆的时候，需要存储这两堆数组，若是在C++中，可使用vector，在PHP或其他语言中，更好处理。在c中，不能使用数组存储，因为这两堆数据的个数未知。C中，不能使用非定长数组，更严格，不能在声明或创建数组时使用变量定义大小。

我使用了浪费内存的方法，即创建一块远大于所需要的容量的内存。

看到别人用了一种不需要存储大小堆数据的方法，但我看一次理解不了。后面再学习这种方法。