#include<string.h>
#include<stdio.h>
#include<stdlib.h>

void url_encode(char *str, int true_length);

int main(int argc,char* argv[]){
    if(argc < 2){
        printf("Incorrect usage : encode <string> \n");
        exit(-1);
    }

    int truelength = strlen(argv[1]);
    url_encode(argv[1],truelength);
    printf("%s",argv[1]);
}

void url_encode(char *str, int true_length){
    int spaces = 0;
    for(int i = 0 ; i < true_length; i++){
        if(str[i] == ' ' ) spaces++;
    }
    int new_length = true_length + 2*spaces;
    char *temp = malloc(new_length + 1);

    int j = 0;

    for (int i = 0; i < true_length; i++) {
        if (str[i] == ' ') {
            temp[j++] = '%';
            temp[j++] = '2';
            temp[j++] = '0';
        } else {
            temp[j++] = str[i];
        }
    }
    temp[j] = '\0';
    strcpy(str, temp);
    free(temp);
};