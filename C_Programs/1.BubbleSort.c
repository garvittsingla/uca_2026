#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Generates an array of random integers of given size.
int* generateArray(int size) {
  int* arr = malloc(size * sizeof(int));
  for (int i = 0; i < size; i++) {
    arr[i] = rand() % 100;
  }
  return arr;
};

// Sorts the given array using Bubble Sort.
void applyBubbleSort(int arr[], int size) {
  for (int i = 0; i < size - 1; i++) {
    bool swapped = false;
    for (int j = 0; j < size - i - 1; j++) {
      if (arr[j + 1] < arr[j]) {
        int temp = arr[j + 1];
        arr[j + 1] = arr[j];
        arr[j] = temp;
        swapped = true;
      }
    }

    if (!swapped) return;
  }
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

int main() {
  int size;

  // Seed random number generator
  srand(time(NULL));

  printf("Enter the size of the array: ");
  scanf("%d", &size);

  // Generate random array
  int* arr = generateArray(size);

  // Start timer
  clock_t start = clock();

  // Apply sorting algorithm
  applyBubbleSort(arr, size);

  // Stop timer
  clock_t end = clock();

  // Calculate execution time
  double executionTime = (double)(end - start) / CLOCKS_PER_SEC;

  // Verify correctness
  if (verifySort(arr, size)) {
    printf("Array is sorted successfully.\n");
  } else {
    printf("Sorting failed!\n");
  }

  printf("Execution Time: %.6f seconds\n", executionTime);
  printf("Execution Time: %.3f milliseconds\n", executionTime * 1000);

  // Free dynamically allocated memory
  free(arr);

  return 0;
}
