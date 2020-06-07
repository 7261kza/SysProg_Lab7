#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "erproc.h"
#include <string.h>

int main() {
    int server = Socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr;
    addr.sin_addr.s_addr = inet_addr("192.168.56.101");
    addr.sin_family = AF_INET;
    addr.sin_port = htons(34543);
    Bind(server, (struct sockaddr *) &addr, sizeof addr);
    Listen(server, 5);
    socklen_t adrlen = sizeof addr;
    int fd = Accept(server, (struct sockaddr *) &addr, &adrlen);
    
    char msg[256] = "Hello from server!";
    send(fd, msg, sizeof(msg), NULL);

    close(fd);
    close(server);
    return 0;
}
