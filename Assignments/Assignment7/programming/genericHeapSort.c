#include <stdio.h>
#include <string.h>
#include "genericHeapSort.h"

struct Student{
    float marks;
    int rollno;
    char* name;
};


// can print any type
void print(void* arr, char* format, int n){

    if(strcmp(format,"int") == 0){

        for(int i = 0; i < n; i++){
            printf("%d ", *(int*)((char*)arr + i * sizeof(int)));
        }

    }else if(strcmp(format, "float") == 0){

        for(int i = 0; i < n; i++){
            printf("%.2f ", *(float*)((char*)arr + i * sizeof(float)));
        }

    }else{

        for(int i = 0; i < n; i++){

            struct Student* student =
                (struct Student*)((char*)arr + i * sizeof(struct Student));

            printf("Marks of %d %s are %.2f\n",
                   student->rollno,
                   student->name,
                   student->marks);
        }
    }

    printf("\n");
}


// compare 2 elements
// first > second -> 1
// first < second -> -1
// equal -> 0
int compare(void* arr, int i, int j, char *type){

    if(strcmp(type,"int") == 0){

        int first =
            *(int*)((char*)arr + i * sizeof(int));

        int second =
            *(int*)((char*)arr + j * sizeof(int));

        if(first > second) return 1;
        else if(first < second) return -1;

        return 0;

    }else if(strcmp(type,"float") == 0){

        float first =
            *(float*)((char*)arr + i * sizeof(float));

        float second =
            *(float*)((char*)arr + j * sizeof(float));

        if(first > second) return 1;
        else if(first < second) return -1;

        return 0;

    }else{

        struct Student first =
            *(struct Student*)((char*)arr +
                               i * sizeof(struct Student));

        struct Student second =
            *(struct Student*)((char*)arr +
                               j * sizeof(struct Student));

        if(first.marks > second.marks) return 1;
        else if(first.marks < second.marks) return -1;

        return 0;
    }
}


int getElementInt(void* arr, int index){
    return *(int*)((char*)arr + index * sizeof(int));
}


float getElmentFloat(void* arr, int index){
    return *(float*)((char*)arr + index * sizeof(float));
}


// Get size of one element
int getElementSize(char* type){

    if(strcmp(type, "int") == 0)
        return sizeof(int);

    if(strcmp(type, "float") == 0)
        return sizeof(float);

    return sizeof(struct Student);
}


// Swap two elements of any type
void swap(void* arr, int i, int j, int elementSize){

    char temp[elementSize];

    memcpy(temp,
           (char*)arr + i * elementSize,
           elementSize);

    memcpy((char*)arr + i * elementSize,
           (char*)arr + j * elementSize,
           elementSize);

    memcpy((char*)arr + j * elementSize,
           temp,
           elementSize);
}


// Maintain max heap
void heapify(void* arr, int index, int n, char* type){

    int largest = index;

    int left = 2 * index + 1;
    int right = 2 * index + 2;

    // left > root
    if(left < n && compare(arr, left, largest, type) > 0){
        largest = left;
    }

    // right > largest
    if(right < n && compare(arr, right, largest, type) > 0){
        largest = right;
    }

    // If root is not largest
    if(largest != index){

        int elementSize = getElementSize(type);

        swap(arr, index, largest, elementSize);

        // Heapify affected subtree
        heapify(arr, largest, n, type);
    }
}


void heapSort(void* arr, int n, char* type){

    // Build max heap
    for(int i = n / 2 - 1; i >= 0; i--){
        heapify(arr, i, n, type);
    }

    // Extract elements one by one
    for(int i = n - 1; i > 0; i--){

        int elementSize = getElementSize(type);

        // Move maximum element to the end
        swap(arr, 0, i, elementSize);

        // Restore heap
        heapify(arr, 0, i, type);
    }
}


int main(void){

    int intArr[7] = {
        32, 21, 32, 43, 12, 43, 12
    };

    printf("Integer Array before sorting:\n");
    print((char*)intArr, "int", 7);

    heapSort((void*)intArr, 7, "int");

    printf("Integer Array after sorting:\n");
    print((char*)intArr, "int", 7);


    float floatArr[7] = {
        32.0, 32.2, 65.2, 0.2, 14.0, 69.90, 45
    };

    printf("\nFloat Array before sorting:\n");
    print((char*)floatArr, "float", 7);

    heapSort((void*)floatArr, 7, "float");

    printf("Float Array after sorting:\n");
    print((char*)floatArr, "float", 7);


    struct Student studentArr[5] = {
        {90.0, 1, "garvit"},
        {30.0, 2, "ram"},
        {30.4, 3, "charan"},
        {50.0, 4, "thor"},
        {10.0, 5, "gogi"},
    };

    printf("\nStudent Array before sorting:\n");
    print((char*)studentArr, "student", 5);

    heapSort((void*)studentArr, 5, "student");

    printf("Student Array after sorting:\n");
    print((char*)studentArr, "student", 5);

    return 0;
}