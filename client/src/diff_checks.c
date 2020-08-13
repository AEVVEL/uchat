#include "../inc/uchat.h"

void check_for_cont_par(int argc) {
    if (argc != 3) { 
        fprintf(stderr,"usage: client hostname port\n");
        exit(1); 
    }
}

void check_for_connect(struct addrinfo **p) {
     if (*p == NULL) { 
        fprintf(stderr, "client: failed to connect\n");
        exit(2); 
    }
}
