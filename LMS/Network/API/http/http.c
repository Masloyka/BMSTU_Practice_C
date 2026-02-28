#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include "http.h"

bool HTTPReadRequest(socket_t client_sock, HttpRequest* req){
    char line[1024];

    ssize_t len = ReadLine(client_sock, line, sizeof(line));
    if (len <= 0){
        return false;
    }

    if (!ParseRequest(line, req)){
        return false;
    }

    for (;;) {
        ssize_t hlen = ReadLine(client_sock, line, sizeof(line));
        if (hlen < 0){
            return false;
        }
        if (hlen == 0){
            break;
        }
    }
    return true;

}

void HTTSendResponse(socket_t client_socket,
    int status_code,
    const char* status_text,
    const char* content_type,
    const char* body
){
    char header[256];
    size_t body_len = body ? strlen(body) : 0;

    int header_len = snprintf(
        header, sizeof(header),
        "HTTP/1.1 %d %s\r\n"
        "Content-Type: %s\r\n"
        "Content-Length: %zu\r\n"
        "Connection: close\r\n"
        "\r\n",
        status_code,
        status_text,
        content_type ? content_type : "text/plain",
        body_len
    );

    if (header_len < 0 || (size_t)header_len >= sizeof(header)){
        return;
    }

    send(client_socket, header, (size_t)header_len, 0);

    if (body_len > 0){
        send(client_socket, body, body_len, 0);
    }
}