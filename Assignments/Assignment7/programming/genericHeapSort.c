#include <stdio.h>
#include <string.h>
#include "genericHeapSort.h"

struct Student{
    float marks;
    int rollno;
    char* name;
};


int main(void){
    int intArr[7] = {32,21,32,43,12,43,12};
    printf("%s","Integer Array before sorting : \n");
    print((char*)intArr,"int",7);
   


    float floatArr[7] = {32.0,32.2,65.2,0.2,14.0,69.90,45};
    printf("%s","Float Array before sorting : \n");
    print((char*)floatArr,"float",7);
   

    struct Student studentArr[5] = {
        {90.0,1,"garvit"},
        {30.0,2,"ram"},
        {30.4,3,"charan"},
        {50.0,4,"thor"},
        {10.0,5,"gogi"},
    };
    printf("%s","Student Array before sorting : \n");
    print((char*)studentArr,"student",5);






}
//can print any type
void print(void* arr,char* format,int n){

    if(strcmp(format,"int") == 0){
        for(int i = 0 ; i < n ; i++){
            printf("%d ",*(int*)((char*)arr + i* sizeof(int)));
        }
    }else if(strcmp(format, "float") == 0){
        for(int i = 0 ; i < n ; i++){
            printf("%.2f ",*(float*)((char*)arr + i* sizeof(float)));
        }
    }else{
        for(int i = 0 ; i < n ; i++){
            struct Student* student = (struct Student*)((char*)arr + i * sizeof(struct Student));
            printf("Marks of %d %s are %.2f \n",student->rollno,student->name,student->marks);
        }
    }
    
    printf("\n");

}
//compare 2 numbers , if first is less than return 1, otherwise -1 , if equal 0
int compare(void*arr,int i,int j,char *type){
    if(strcmp(type,"int") == 0){
        int first = *(int*)((char*)arr + (i * sizeof(int)));
        int second = *(int*)((char*)arr + (j * sizeof(int)));
        if(first > second)return 1;
        else if(second > first) return -1;
        return 0;
    }else if(strcmp(type,"float")==0){
        float first = *(float*)((char*)arr + (i*sizeof(float)));
        float second = *(float*)((char*)arr + (j*sizeof(float)));
        if(first > second)return 1;
        else if(second > first) return -1;
        return 0;
    }else{
        struct Student first = *(struct Student*)((char*)arr + (i * sizeof(struct Student)));
        struct Student second = *(struct Student*)((char*)arr + (j * sizeof(struct Student)));
        if(first.marks > second.marks)return 1;
        else if(second.marks > first.marks) return -1;
        return 0;

    }
}
int getElementInt(void* arr,int index){
    return *(int*)((char*)arr + (index*sizeof(int)));
}
float getElmentFloat(void* arr,int index){
    return *(float*)((char*)arr + (index*sizeof(int)));
}

void heapSort(void* arr,int n,char* type){
    
}
// void heapify(void* arr,int index,int n,char*type){
//     if(index == 0) return;

//     int left = index*2+1;
//     int right = index*2+2;

//     int leftElement = 
//     if(left < n && )
// }