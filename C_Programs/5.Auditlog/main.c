#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <fcntl.h>
#include <unistd.h>

enum Command{
    ADD,
    VIEW
};


int main(int argc,char* argv[]){
    
    char* LOGFILE = "auditlogs";
    int fileFd,openFlags,numRead;
    mode_t mode;
    char buffer[1024];

    if(argc < 2){
        printf("Usage : \n 1. --add 'log to add' \n 2. --view\n" );
        return 1;
    }

    enum Command cmd;

    if(strcmp(argv[1],"--add") == 0){
        if(argc < 3){
            printf("Please provide log to add\n");
            return 1;
        }
        cmd = ADD;

    }else if(strcmp(argv[1],"--view") == 0){
        cmd = VIEW;
    }else {
        printf("Invalid Command\n");
        return 1;
    }

    if(cmd == ADD){
        openFlags = O_CREAT | O_WRONLY | O_APPEND; 
        mode = 0777;
    }else{
        openFlags = O_RDONLY;
    }


    if(cmd == ADD){
        fileFd = open(LOGFILE,openFlags,mode);
        write(fileFd, argv[2], strlen(argv[2]));
        write(fileFd,"\n",1);
        close(fileFd);
    }else{
        fileFd = open(LOGFILE,openFlags);
        int linenumber = 0;
        char* lastline = malloc(1024);
        int idx = 0;
        while((numRead = read(fileFd, buffer, 1024)) > 0){
            for(int i = 0 ; i < numRead ; i++){
                if(buffer[i] == '\n'){
                    lastline[idx] = '\0';
                    printf("%d: %s\n", linenumber, lastline);
                    idx = 0;
                    linenumber++;
                }else{
                    lastline[idx++] = buffer[i];
                }
               
            }  
        }

        if(idx > 0){
            printf("%d: %s\n", linenumber, lastline);
        }
        
        close(fileFd);
    }
   

    return 0;
   
    
        
    

}