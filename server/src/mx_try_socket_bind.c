#include "../inc/uchat.h"

static void check_bind(struct addrinfo *p, struct addrinfo **servinfo) {
    if (p == NULL)  { 
        fprintf(stderr, "server: failed to bindn");
        exit(2);
    }
    freeaddrinfo(*servinfo);
}

void mx_trybind(struct addrinfo **servinfo, int *sockfd) {
    int yes = 1;
    struct addrinfo *p;

    for(p = *servinfo; p != NULL; p = (p)->ai_next) { 
        if ((*sockfd = socket((p)->ai_family, (p)->ai_socktype, (p)->ai_protocol)) == -1) { 
            perror("server: socket"); 
            continue; 
        }
        if (setsockopt(*sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) { 
            perror("setsockopt"); 
            exit(1); 
        }
        if (bind(*sockfd, (p)->ai_addr, (p)->ai_addrlen) == -1) { 
            close(*sockfd); 
            perror("server: bind"); 
            continue; 
        }
        break;
    }
    check_bind(p, servinfo);
}
