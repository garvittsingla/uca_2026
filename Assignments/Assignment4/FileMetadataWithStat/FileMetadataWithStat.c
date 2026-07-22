#include "stdio.h"
#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
#include "string.h"
#include "time.h"
int main(int argc,char*argv[]){


    struct stat sb;
    if(argc < 2){
        printf("Incorrect Usage : .exe <path-to-file>");
        return 1;
    }

    int status = stat(argv[1],&sb);
    if(status == -1 ){
        printf("Something went wrong\n");
        return 1;
    }

    printf("=== File Attributes for: %s ===\n",argv[1]);
    printf("File Type:    ");
    switch (sb.st_mode & S_IFMT) {
        case S_IFDIR:  printf("directory\n");               break;
        case S_IFREG:  printf("Regular file\n");            break;
        default:       printf("unknown?\n");                break;
    }

    printf("Permissions:          %04o\n", sb.st_mode & 0777);

    printf("File Size:            %lld bytes\n",sb.st_size);

    printf("Hard Links Count:     %hu\n",sb.st_nlink);

    printf("Owner (UID):          %d\n",sb.st_uid);

    printf("Group (GID):          %d\n",sb.st_gid);

    printf("Last access time:     %s", ctime(&sb.st_atime));

    printf("Last Modification:    %s\n",ctime(&sb.st_mtime));

    printf("Status Change Time:   %s\n",ctime(&sb.st_ctime));



}