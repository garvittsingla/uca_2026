#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Generates an array of random integers of given size.
int *generateArrayRandom(int size) {
  int *arr = malloc(size * sizeof(int));
  for (int i = 0; i < size; i++) {
    arr[i] = rand() % 100;
  }
  return arr;
};

int *generateIncreasing(int size){
  int number = 1;
  int* arr = malloc(size*sizeof(int));
  for(int i = 0 ; i < size ; i++){
    arr[i] = number;
    number++;
  }

  return arr;
}

int *generateDecreasing(int size){
  int number = size-1;
  int* arr = malloc(size*sizeof(int));
  for(int i = 0 ; i < size ; i++){
    arr[i] = number;
    number--;
  }

  return arr;
}

void merge(int arr[],int left,int right,int mid){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *lArr = malloc(n1*sizeof(int));
    int *rArr = malloc(n2*sizeof(int));

    for(int i = 0 ; i < n1 ; i++){
        lArr[i] = arr[left + i];
    }

    for(int j = 0 ; j < n2 ; j++){
        rArr[j] = arr[mid + 1 + j];
    }

    int i = 0 , j = 0 , k = left;
    while(i < n1 && j < n2){
        if(lArr[i] <= rArr[j]){
            arr[k] = lArr[i];
            i++;
        }else{
            arr[k] = rArr[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        arr[k] = lArr[i];
        i++;
        k++;
    }

    while(j < n2){
        arr[k] = rArr[j];
        j++;
        k++;
    }

    free(lArr);
    free(rArr);
}
void Mymergesort(int arr[],int left,int right){

    if(left < right){
        int mid = left + (right - left)/2;
        Mymergesort(arr,left,mid);
        Mymergesort(arr,mid+1,right);
        merge(arr,left,right,mid);
    }

}
// Sorts the given array using merge Sort.
void applyMergeSort(int arr[], int size) {
    if(size <= 0) return;
    Mymergesort(arr,0,size-1);
};

// Returns true if the array is sorted, otherwise false.
bool verifySort(int arr[], int size) {
  for (int i = 1; i < size; i++) {
    if (arr[i - 1] > arr[i]) {
      return false;
    }
  }
  return true;
};

void performSorting(int arr[], int size) {
  // Start timer
  clock_t start = clock();

  // Apply sorting algorithm
  applyMergeSort(arr, size);

  // Stop timer
  clock_t end = clock();

  // Calculate execution time
  double executionTime = (double)(end - start) / CLOCKS_PER_SEC;

  //Verify correctness
  if (!verifySort(arr, size)) {
    printf("Sorting failed!\n");
    return;
  }

  printf("%.3f ms\n",executionTime * 1000);
  // printf("Execution Time: %.3f milliseconds\n", executionTime * 1000);
}
int main() {

  // Seed random number generator
  int sizes[] = {0, 8000, 12000, 16000, 20000, 24000, 28000,32000,36000};

  printf("Random numbers\n");
  for(int i = 0 ; i < sizeof(sizes)/sizeof(int) ; i++){
    int size = sizes[i];
    int* arr = generateArrayRandom(size);
    performSorting(arr, size);
    free(arr);
  }

    printf("Descending numbers\n");
   for(int i = 0 ; i < sizeof(sizes)/sizeof(int) ; i++){
    int size = sizes[i];
    int* arr = generateDecreasing(size);
    performSorting(arr, size);
    free(arr);
  }

  printf("Ascending numbers\n");
  for(int i = 0 ; i < sizeof(sizes)/sizeof(int); i++){
    int size = sizes[i];
    int* arr = generateIncreasing(size);
    performSorting(arr, size);
    free(arr);
  }

  return 0;
}
