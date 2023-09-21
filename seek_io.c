#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int fd;
void main (int argc, char* argv[]) {
        int fd, num;
        int mode, len, offset;
        char* buff = NULL;
        char buf[20];
        printf("file provided : %s\n", argv[1]);
        fd = open(argv[1], O_RDWR, 0777);
        for(int i = 2; i < argc; i++) {
                switch(argv[i][0]){
                        case 'w':
                                //mode = O_WRONLY;
                                //fd = open(argv[1], mode, 0777);
                                num = write(fd, argv[i]+1, strlen(argv[i]));
                                if(num != -1) {
                                        printf("write : %s\n", argv[i]+1);
                                } else {
                                        printf("write error %d\n", num);
                                }
                                //close(fd);
                                break;
                        case 'r':
                                //mode = O_RDONLY;
                                len = atoi(argv[i]+1);
                                buff = malloc(len);
                                //fd = open(argv[1], mode, 0777);
                                num = read(fd, buff, len);
                                if(num != -1) {
                                        printf("read %d: %s\n", num, buff);
                                } else {
                                        printf("read error %d\n", num);
                                }
                                free(buff);
                                //close(fd);
                                break;
                        case 's':
                                //mode = O_RDWR;
                                //fd = open(argv[1], mode, 0777);
                                offset = atoi(argv[i]+1);
                                lseek(fd,offset, SEEK_SET);
                                printf("seek set: %d\n", offset);
                        default :
                                mode = -1;
                                break;
                }
        }
}
