    
#include "../inc/uchat.h"

void print_IP(struct addrinfo *p) { 
    char s[INET6_ADDRSTRLEN];

    inet_ntop(p->ai_family, get_in_addr(p->ai_addr), s, sizeof s);
    printf("client: connecting to %s\n", s);
}
