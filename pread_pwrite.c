#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void main(int argc, char* argv[]) {
    char filename[20];
    char buff[50];
    int offset = atoi(argv[3]);
    int count = atoi(argv[4]);
    int fd;
    strcpy(filename,argv[1]);
    printf("file: %s\n", filename);
    printf("offset : %d, count :%d\n", offset, count);
    if(strcmp(argv[2],"read")==0) {
        fd = open(filename, O_RDONLY);
        pread(fd, buff, count, offset);
        printf("fd: %d,read at %d = %s\n", fd, offset, buff);
    } else if( strcmp(argv[2],"write")==0) {
        fd = open(filename, O_WRONLY);
        strcpy(buff,argv[5]);
        printf("printing : %s\n",buff);
        pwrite(fd, buff, count, offset);
        printf("fd: %d,write at %d\n", fd, offset);
    } else {
        printf("unknown\n");
    }
    close(fd);
}
