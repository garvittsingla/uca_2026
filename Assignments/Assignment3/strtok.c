#include <stdio.h>
#include<stdlib.h>
#include <string.h>

int main(int argc,char* argv[]){

    if(argc < 2){
        printf("Incorrect Usage : strtok 'string' ");
        exit(-1);
    }
    char * sep = ",";
    char *token = strtok(argv[1],sep);

    while(token!=NULL){
        printf("%s\n",token);
        token = strtok(NULL,sep);
    }
    return 0;

}