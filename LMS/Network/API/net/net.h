#ifndef NET_H
#define NET_H

#include <stdint.h>

typedef int socket_t;

socket_t NetListenIP(const char* ip, uint16_t port, int backlog);

socket_t NetAccept(socket_t listen_sock);

void NetClose(socket_t sock);

#endif // DEBUG