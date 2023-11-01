#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
#define PORT "8888"

int main(int argc, char const* argv[])
{
    int status, valread, client_fd;
    struct sockaddr_in serv_addr;
    char buffer[1024] = { 0 };
    struct addrinfo hints, *res;
    int counts = 0;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    getaddrinfo("localhost", PORT, &hints, &res);
    char str[100];
    printf("client started.\nEnter message to send: ");
    scanf("%[^\n]s",str);

    if ((client_fd = socket(res->ai_family, res->ai_socktype, res->ai_protocol)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    if ((status
        = connect(client_fd, res->ai_addr,res->ai_addrlen))
        < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }
    send(client_fd, str, sizeof(str), 0);

    while(read(client_fd, buffer, 1023)){
        printf("%s", buffer);
        memset(buffer, 0, sizeof(buffer));
        sprintf(buffer,"ping:%d",counts);
        if(counts++ >5) {
            send(client_fd, "exit",4,0);
            printf("exit sent");
            break;
        } else {
            send(client_fd, buffer, sizeof(buffer), 0);
        }
        printf("sending :%s\n", buffer);
        usleep(500);
    }

    close(client_fd);
    return 0;
}
