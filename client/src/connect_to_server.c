#include "../inc/uchat.h"

void connect_to_server(int *sockfd, struct addrinfo **servinfo, struct addrinfo **p) {
   for(*p = *servinfo; *p != NULL; *p = (*p)->ai_next) { 
        if ((*sockfd = socket((*p)->ai_family, (*p)->ai_socktype, (*p)->ai_protocol)) == -1) { 
            perror("client: socket"); 
            continue; 
        }
        if (connect(*sockfd, (*p)->ai_addr, (*p)->ai_addrlen) == -1) { 
            close(*sockfd); 
            perror("client: connect"); 
            continue;
        }
        break;
    }
    check_for_connect(p);
}
