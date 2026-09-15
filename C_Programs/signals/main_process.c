#include<stdio.h>
#include<unistd.h>
#include<signal.h>
void handler(int sig){
    return;
}
int main(){
    while(1){
        printf("Hello I am the main process\n");
        sleep(2);
    }           
}
