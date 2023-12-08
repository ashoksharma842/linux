#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void sigint()
{
    signal(SIGINT, sigint);
    printf("sigint received\n");
}
void main ()
{
    int pid;
    pid = fork();
//    printf("pid = %d:", pid);
    if (!pid) {
        printf("child pid = %d(%d)\n", getpid(), pid);
        signal(SIGINT, sigint);
        while(1);
    } else {
        printf("parent pid = %d\n", getpid());
        printf("sending SIGINT\n");
        kill(pid, SIGINT);
    }
}
