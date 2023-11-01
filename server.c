#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
#define PORT "8888"
int main(int argc, char const* argv[])
{
    int server_fd, new_socket;
    ssize_t valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = { 0 };
    char* hello = "Hello from server";
    struct addrinfo hints;
    struct addrinfo *servinfo;
    char sendbuff[2048] = {0};
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;
    getaddrinfo(NULL,PORT,&hints, &servinfo);
    int count = 0;
    char zeros[1024] = {0};

    if ((server_fd = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol)) < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (bind(server_fd, servinfo->ai_addr, servinfo->ai_addrlen) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    if ((new_socket = accept(server_fd, (struct sockaddr*)&address, &addrlen)) < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    while(1){
        memset(buffer,0,sizeof(buffer));
        valread = read(new_socket, buffer, 1023);
        printf("%s\n",buffer);
        if(strcmp(buffer,"exit") == 0){
            printf("exit received\n");
            close(new_socket);
            close(server_fd);
            return 0;
        }
        if(memcmp(buffer, zeros,sizeof(buffer))) {
        memset(sendbuff,0,sizeof(sendbuff));
        sprintf(sendbuff,"%s rx ", buffer);
        send(new_socket, sendbuff, sizeof(sendbuff), 0);
        }
    }
    close(new_socket);
    close(server_fd);
    return 0;
}
