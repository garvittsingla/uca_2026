#include "stdio.h"

int size = 0;
int size_of(){ return size;}
void swap(int a[],int i,int j){
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
void swim(int a[],int i){
    if( i == 0) return;
    int parent = (i-1)/2;
    if(a[parent] > a[i]){
        swap(a,parent,i);
        swim(a,parent);
    }

}
int get_min(int a[]){
    if(size_of() == 0){
        printf("No element");
        return -1;
    }
    return a[0];
}
void sink(int a[],int i){
    if(i >= size) return;
    int min = i;
    int L = i*2+1;
    int R = i*2 + 2;
    if(L<size && a[L] < a[min]){
        min = L;
    }
    if(R < size && a[R] < a[min]){
        min =R;
    }
    if(min != i){
        swap(a,i,min);
        sink(a,min);
    }

}
int delelet_min(int a[]){
    int res = get_min(a);
    size--;
    swap(a,0,size);
    sink(a, 0);
    return res;

}

void insert(int a[],int ele){
    a[size] = ele;
    swim(a,size);
    size++;
}
int main(){
    int a[10];

    insert(a,5);
    insert(a,2);
    insert(a,3);
    insert(a,1);
    insert(a,5);
    insert(a,50);
    insert(a,0);
    int min = get_min(a); //0
    printf("Current min is this %d\n",min);
    min = delelet_min(a); //0
    printf("Current min is this %d\n",min);

    min = delelet_min(a); //1
    printf("Current min is this %d\n",min);

    min = delelet_min(a); //2
    printf("Current min is this %d\n",min);

    min = delelet_min(a); //3
    printf("Current min is this %d\n",min);



}