#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>

#include "net.h"
// net не знает об остальных вещах
socket_t NetListenIP(const char* ip, uint16_t port, int backlog){
    socket_t sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1){
        perror("socket");
        return -1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = ip ? inet_addr(ip) : htonl(INADDR_ANY);

    if (bind(sock, (struct sockaddr*) &addr, sizeof(addr)) == 1){
        perror("bind");
        close(sock);
        return -1;
    }

    if (listen(sock, backlog) == -1){
        perror("listen");
        return -1;
    }

    return sock;
}

socket_t NetAccept(socket_t listen_sock){
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);

    socket_t client_sock = accept(
        listen_sock,
        (struct sockaddr*) &client_addr,
        &client_len
    );
    if (client_sock == -1){
        perror("accept");
        return -1;
    }

    return client_sock;
}

void NetClose(socket_t sock){
    if (sock >= 0){
        close(sock);
    }
}