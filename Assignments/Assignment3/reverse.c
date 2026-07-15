#include<stdio.h>
#include <stdlib.h>
#include<string.h>

void reverse_string(char *str){
    int i = 0;
    int j = strlen(str) - 1;

    while(i<j){
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }

}
int main(int argc,char* argv[]){

    if(argc < 2){
        printf("Incorrect usage : reverse <string>  \n" );
        exit(-1);
    }

    reverse_string(argv[1]);

    printf("The resultant string is : %s\n",argv[1]);

}