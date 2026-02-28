#include <stdio.h>
#include <string.h>

#include "net/net.h"
#include "http/http.h"

#define SERVER_IP "0.0.0.0"
#define SERVER_PORT 8080

static void Handler(socket_t client_sock){
    HttpRequest req;
    if (!HTTPReadRequest(client_sock, &req)) {
        const char* body = "{\"error\":\"bad request\"}\n";
        HTTSendResponse(client_sock, 400, "Bad Request", "application/json", body);
        return;
    }

    printf("Request: %s %s?%s\n", req.method, req.path, req.query[0] ? req.query : "");

    if (strcmp(req.method, "GET") != 0){
        const char* body = "{\"error\":\"method not allowed\"}\n";
        HTTSendResponse(client_sock, 405, "Method Not Allowed", "application/json", body);
        return;
    }

    // EndPoint
    if (strcmp(req.path, "/api/health") == 0){
        const char* body = "{\"status\":\"ok\"}\n";
        HTTSendResponse(client_sock, 200, "OK", "application/json", body);
    } else {
        const char* body = "{\"error\":\"Not Found\"}\n";
        HTTSendResponse(client_sock, 404, "Not Found", "application/json", body);
    }
}

int main(){
    socket_t server_sock = NetListenIP(SERVER_IP, SERVER_PORT, 16);
    if (server_sock == -1){
        return 1;
    }

    printf("HTTP-сервер запущен на %s:%d\n", SERVER_IP, SERVER_PORT);
    printf("Эндпоинт: GET /api/health\n");

    for (;;){
        socket_t client_sock = NetAccept(server_sock);
        if (client_sock == -1){
            continue;
        }

        Handler(client_sock);
        NetClose(client_sock);
    }

    NetClose(server_sock);
}