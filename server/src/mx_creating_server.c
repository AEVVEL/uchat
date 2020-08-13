#include "../inc/uchat.h"

int mx_creating_server(char *port) {
    int sockfd = 0;
    struct addrinfo *servinfo = NULL;

	mx_check_addrinfo(&servinfo, port);
	mx_trybind(&servinfo, &sockfd);
    // freeaddrinfo(servinfo);
	mx_trysigaction(&sockfd);
    return sockfd;
}
