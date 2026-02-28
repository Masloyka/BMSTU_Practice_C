#ifndef HTTP_H
#define HTTP_H

#include <stdbool.h>
#include "../net/net.h"

typedef struct {
    char method[8];
    char path[256];
    char query[256];
} HttpRequest;

ssize_t ReadLine(int socket, char* buffer, size_t max_len);
int ParseRequest(const char* line, HttpRequest* req);

bool HTTPReadRequest(socket_t client_sock, HttpRequest* req);

void HTTSendResponse(socket_t client_socket,
    int status_code,
    const char* status_text,
    const char* content_type,
    const char* body
);

#endif // !HTTP_H

