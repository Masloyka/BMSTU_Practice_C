#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <stdlib.h>
typedef int socket_t;
#define IP "51.250.91.149"
#define PORT 80

int HttpGet(char** out_body) {
    *out_body = NULL;

    // 1. Создать TCP-сокет
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1){
        perror("socket");
        return -1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = inet_addr(IP);

    if (inet_pton(AF_INET, IP, &addr.sin_addr) <= 0){
        close(sock);
        return -1;
    }
    // 2. Подключиться к серверу c IP и 80 портом
    if (connect(sock, (struct sockaddr*) &addr, sizeof(addr)) == -1){
        close(sock);
        return -1;
    }

    // 3. Сформировать корректный HTTP-запрос (сообщение для HTTP-сервера)

    // Корректрый HTTP-запрос выглядит вот так:
    char request[512];
    snprintf(request, sizeof(request), "GET / HTTP/1.1\r\nHost: 51.250.91.149\r\nConnection: close\r\n\r\n");
    // Вы можете смело сделать иначе (например, через snprintf)

    // 3. Отправить запрос серверу используя сокет
    if (send(sock, request, strlen(request), 0) < 0){
        close(sock);
        return -1;
    }

    // 4. Прочитать весь ответ от сервера до закрытия соединения
    char buffer[4096];
    char* responce = NULL;
    size_t total_size = 0;
    size_t buffer_size = 0;
    while (1) {
        ssize_t bytes_read = recv(sock, buffer, sizeof(buffer) - 1, 0);
        if (bytes_read <= 0) {
            break;
        }
        
        // Увеличиваем буфер ответа при необходимости
        if (total_size + bytes_read + 1 > buffer_size) {
            buffer_size = (total_size + bytes_read + 1) * 2;
            char* new_response = realloc(responce, buffer_size);
            if (!new_response) {
                free(responce);
                close(sock);
                return -1;
            }
            responce = new_response;
        }
        
        memcpy(responce + total_size, buffer, bytes_read);
        total_size += bytes_read;
        responce[total_size] = '\0';
    }
    close(sock);

    if (!responce){
        return -1;
    }
    // 5. Отделить HTTP-заголовки от тела ответа (Тело начинается после первой последовательности \r\n\r\n)
    char* body_start = strstr(responce, "\r\n\r\n");
    if (!body_start) {
        free(responce);
        return -1;
    }

    body_start += 4;

    size_t body_len = strlen(body_start);
    *out_body = malloc(body_len + 1);
    if (!*out_body){
        free(responce);
        return -1;
    } 

    strcpy(*out_body, body_start);
    free(responce);
    // 6. Вернуть только тело ответа через out_body. Память под out_body выделяется динамически.
    // 7. При любой ошибке возвращать -1. При успехе - 0.
    return 0;
}


int main() {
    printf("Начало теста HTTP GET...\n");
    
    char* body = NULL;
    
    // Вызываем функцию
    int result = HttpGet(&body);
    
    if (result == 0 && body != NULL) {
        printf("✅ Успех! Получено %zu байт\n", strlen(body));
        printf("\nТело ответа (первые 500 символов):\n");
        printf("-----------------------------------\n");
        
        // Выводим первые 500 символов
        size_t len = strlen(body);
        if (len > 500) {
            body[500] = '\0';
        }
        printf("%s\n", body);
        printf("-----------------------------------\n");
        
        // Освобождаем память
        free(body);
    } else {
        printf("❌ Ошибка! Результат: %d\n", result);
    }
    
    return 0;
}