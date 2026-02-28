#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <signal.h>

int main(){
    signal(SIGPIPE, SIG_IGN);
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0){
        perror("socket");
        return 1;
    }
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    connect(sock, (struct sockaddr*) &addr, sizeof(addr));
    const char* msg = "Hello, server!\n";
    send(sock, msg, strlen(msg), 0);
    char buf[1024];
    int n = recv(sock, buf, sizeof(buf)-1, 0);
    buf[n] = '\0';
    printf("Resp: %s\n", buf);
    close(sock);
    return 0;
}