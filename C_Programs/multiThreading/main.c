#include <pthread.h>
#include<stdio.h>

void* foo(void *arg){
    printf("thread is running");
    return NULL;
}

int main(){
    pthread_t thread;
    pthread_create(&thread, NULL, foo, NULL);
    pthread_join(thread, NULL);
    return 0;
}