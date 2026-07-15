#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>


// File holes is a feature of sparse files which makes it veru useful

// read about sparse files and also the seek
int main(int argc,char* argv[]){
    size_t len;
    off_t offset;
    int fd;
    char *buf;
    size_t numRead,numWritten;

    if(argc < 3){
        printf("Usage %s <file> {r<length>|w<string>|s<offset> ...}\n",argv[0]);
        exit(EXIT_FAILURE);
    }

    fd = open(argv[1], O_RDWR | O_CREAT ,S_IWUSR | S_IRUSR | S_IRGRP|S_IWGRP | S_IROTH);

    if(fd == -1){
        printf("Opening file failed\n");
        exit(EXIT_FAILURE);
    }

    for(int i = 2 ; i< argc ; i++){
        switch(argv[i][0]){
            case 'w':
                //char* data = &argv[i][1];
                //printf("%s",&argv[i][1]);
                numWritten =  write(fd,&argv[i][1],strlen(&argv[i][1]));
                printf("Number of bytes written %ld\n",numWritten);
                break;
            case 'r':
                len = atoi(&argv[i][1]);
                buf = malloc(len);
                numRead = read(fd,buf,len);
                if(numRead == 0) {
                    free(buf);
                    printf("Nothing to read");
                    exit(-1);
                }
                for(int j = 0 ; j < numRead ; j++){
                    printf("%c",buf[j]);
                }
                printf("\n");
                free(buf);
                break;
            case 's':
                offset = atoi(&argv[i][1]);
                if((lseek(fd,offset,SEEK_SET) == -1)){
                    printf("Seek failed\n");
                }
                else printf("Seek successfull\n");
                break;
            // case 'l':
            //     int pos = lseek(fd, 0, SEEK_CUR);
            //     printf("Current position is %d\n",fd);
            //     break;
            default:
                printf("Arguments must be one of [wsr]\n");
                exit(EXIT_FAILURE);
        }
    }



    exit(EXIT_SUCCESS);

}