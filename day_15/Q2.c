#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct {
    int *arr;
    int size;
} array;

void *bubble_sort(void *arg) {
    array *arr_struct = (array *)arg;
    int *arr = arr_struct->arr;
    int n = arr_struct->size;
    
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    
    pthread_exit(0);
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    array arr_struct;
    arr_struct.size = n;
    arr_struct.arr = (int *)malloc(n * sizeof(int));
    
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr_struct.arr[i]);
    }
    
    pthread_t tid;
    pthread_create(&tid, NULL, bubble_sort, (void *)&arr_struct);
    pthread_join(tid, NULL);
    
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr_struct.arr[i]);
    }
    printf("\n");
    
    free(arr_struct.arr);
    
    return 0;
}

