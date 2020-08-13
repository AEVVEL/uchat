#include "../inc/uchat.h"

void prepare_struct(char *argv[], struct addrinfo **servinfo) {
    struct addrinfo hints;
    int rv = 0;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    if ((rv = getaddrinfo(argv[1], argv[2], &hints, servinfo)) != 0) { 
        fprintf(stderr, "getaddrinfo: %sn", gai_strerror(rv));
        exit(1); 
    }
}
