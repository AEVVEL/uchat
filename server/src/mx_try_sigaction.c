#include "../inc/uchat.h"

void sigchld_handler() {
    while(waitpid(-1, NULL, WNOHANG) > 0);
}

void mx_trysigaction(int *sockfd) {
    struct sigaction sa; 

    if (listen(*sockfd, BACKLOG) == -1) { 
        perror("listen"); 
        exit(1);
    }
    sa.sa_handler = sigchld_handler;  
    sigemptyset(&sa.sa_mask); 
    sa.sa_flags = SA_RESTART; 
    if (sigaction(SIGCHLD, &sa, NULL) == -1) { 
        perror("sigaction"); 
        exit(1); 
    }
    printf("server: waiting for connections...\n");
}
