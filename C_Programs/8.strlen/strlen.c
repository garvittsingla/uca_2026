#include<stdio.h>
#include <stdlib.h>
int my_strlen(const char *str){
    int length = 0;
    char ch = str[0];
    int index = 0;
    while(ch!='\0'){
        length++;
        ch = str[++index];
    }

    return length;
}
int main(int argc,char* argv[]){

    if(argc < 2){
        printf("incorrect usage  : strlen <string> ");
        exit(-1);
    }


    int len = my_strlen(argv[1]);

    printf("The length of string is %d\n" , len);


}