#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(void){
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    int opt = 1;
    setsockopt(server_sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    bind(server_sock, (struct sockaddr*)&addr, sizeof(addr));
    listen(server_sock, 10);
    printf("Server started at 0.0.0.0:8080\n");

    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);

    int client_sock = accept(
        server_sock,
        (struct sockaddr*)&client_addr,
        &client_len
    );

    char ip_str[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &client_addr.sin_addr, ip_str, sizeof(ip_str));
    printf("Подключение от %s:%d\n", ip_str, ntohs(client_addr.sin_port));

    char buffer[1024];
    ssize_t n = recv(client_sock, buffer, sizeof(buffer) - 1, 0);
    buffer[n] = '\0';
    printf("Клиент отправил: %s\n", buffer);

    char reply[2048];
    snprintf(reply, sizeof(reply), "Круто! Ты отправил: %s", buffer);
    send(client_sock, reply, strlen(reply), 0);
    close(client_sock);
    printf("Клиент отключился\n");

    close(server_sock);
    return 0;
}