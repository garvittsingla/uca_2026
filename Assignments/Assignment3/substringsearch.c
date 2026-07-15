#include <stdio.h>
#include <stdlib.h>

int find_substring(const char *haystack, const char *needle){
    int i = 0;
    while(haystack[i] != '\0'){
        if(haystack[i] == needle[0]){
            int ptr = i;
            int j = 0;
            while (needle[j]!='\0') {
                if(haystack[ptr] == needle[j]){
                    ptr++;
                    j++;
                }else break;
            }

            if(needle[j] == '\0') return i;
        }
        i++;
    }
    return -1;
}
int main(int argc,char* argv[]){
    if(argc <= 2){
        printf("Incorrect usage : substringsearch <string> <target> \n");
        exit(-1);
    }

    int index = find_substring(argv[1], argv[2]);


    printf("The index of the substring is : %d \n" , index);
    


}