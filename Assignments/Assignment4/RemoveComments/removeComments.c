#include <stdio.h>
#include<fcntl.h>
#include <stdlib.h>
#include<string.h>
#include <unistd.h>
#include <sys/stat.h>

#define Buffer 1024

int main(int argc,char* argv[]){
    int fd,numRead;
    char buff[Buffer];
    
   


    if(argc < 2){
        printf("Incorrect usage : ./a.out <filename>");
        return 1;
    }

    fd = open(argv[1],O_RDONLY);
    
    if(fd == -1) {
        printf("Error opening file %s\n",argv[1]);
       return 1;
    } 

    struct stat sb;
    
    if (fstat(fd, &sb) == -1) {
        close(fd);
        return 1;
    }

    int file_size = sb.st_size;
    char* output = malloc(file_size+1);
    int k =0;

  

    int inLineComment = 0;
    int inBlockComment = 0;
    int inString = 0;

    while((numRead = read(fd,buff,Buffer)) > 0){
        int i = 0;
        while(i < numRead){
            char ch = buff[i];

            if(inLineComment){
                if(ch == '\n'){
                    inLineComment = 0;
                    output[k++] = ch;
                }
                i++;
                continue;
            }

            if(inBlockComment){
                if (ch == '*' && i + 1 < numRead && buff[i + 1] == '/') {
                    inBlockComment = 0;
                    i += 2;
                } else {
                    i++;
                }
                continue;
            }

            if (!inString && ch == '/' && i + 1 < numRead && buff[i + 1] == '*') {
                inBlockComment = 1;
                i += 2;
                continue;
            }
            
            if (!inString && ch == '/' && i + 1 < numRead && buff[i + 1] == '/') {
                inLineComment = 1;
                i += 2;
                continue;
            }

            if(ch == '"'){
                if(inString) inString = 0;
                else inString = 1;
            }
            
            output[k++] = ch;
            i++;
            
        }
    }


    printf("%s", output);


}