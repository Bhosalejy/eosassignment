#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

//	Q1. Create a thread to sort given array of 10 integers using selection sort. Main thread should print the result after sorting is completed.

// step 1: implement thread function
void* sort_array(void *param){
int n=10, *arr = (int*)param, i, j, size=10;  
      for (i = 0; i < n-1; i++)
      {
         for (j = i+1; j < n; j++)
         {
              if (arr[i] > arr[j]){
                 int temp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = temp;
              }
          }
      }
      
	  printf("sorted array....\n");
      for(i=0; i<size; i++){
         printf("%d ",arr[i]);	
		}
	printf("\n");
	return NULL;
}


int main() {
	int ret,i,arr[10]={22,40,55,5,16,26,90,101,37,80};
	pthread_t t1;
	// step 2: call pthread_create()
	ret = pthread_create(&t1, NULL, sort_array, arr);
	pthread_join(t1, NULL);
	printf("t1 array...\n");
	for(i=0; i<10; i++)
            printf("%d ",arr[i]);
	printf("\n");
	printf("press enter to exit...\n");
	getchar();
	return 0;
}

