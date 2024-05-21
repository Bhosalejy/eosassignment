
#include <stdio.h>
#include <pthread.h>

#define ARRAY_SIZE 10

void selection_sort(int arr[]) { 
	int i, j, min_index, temp;

	for (i = 0; i < ARRAY_SIZE - 1; i++) {
    min_index = i;
    
    for (j = i + 1; j < ARRAY_SIZE; j++) {
        if (arr[j] < arr[min_index]) {
            min_index = j;
        }
    }
    
    // Swap the found minimum element with the first element
    temp = arr[min_index];
    arr[min_index] = arr[i];
    arr[i] = temp;
}

}

void *sort_thread(void *arg) { int *arr = (int *)arg;

 
	selection_sort(arr);

	pthread_exit(0);

}

int main() { 
	int arr[ARRAY_SIZE] = { 4, 2, 7, 1, 9, 3, 5, 8, 6, 10 }; 
	pthread_t tid;

	pthread_create(&tid, NULL, sort_thread, &arr);
	pthread_join(tid, NULL);

	// Print the sorted array
	printf("Sorted Array: ");
	for (int i = 0; i < ARRAY_SIZE; i++) {
    printf("%d ", arr[i]);
}
	printf("\n");

return 0;

}
