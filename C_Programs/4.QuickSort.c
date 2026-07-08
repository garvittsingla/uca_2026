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


int partition(int arr[], int low, int high) {
    int pivot = arr[low + (high - low) / 2];
    int i = low - 1;
    int j = high + 1;
    while (1) {
        do {
            i++;
        } while (arr[i] < pivot);
        do {
            j--;
        } while (arr[j] > pivot);
        if (i >= j)
            return j;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void Myquicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        Myquicksort(arr, low, pi);
        Myquicksort(arr, pi + 1, high);
    }
}

// Sorts the given array using Quick Sort.
void applyQuickSort(int arr[], int size) {
    if (size <= 0) return;
    Myquicksort(arr, 0, size - 1);
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
  applyQuickSort(arr, size);

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
