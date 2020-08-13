#include "../inc/uchat.h"

char *online;
pthread_mutex_t mutex;

int main(int argc, char **argv) {
    int sockfd;

    if (argc != 2) {
        printf("usage: uchat_server port\n");
        exit(0);
    }
    online = mx_strnew(1);
    //mx_add_message("nuirnuinr", "anovotarsk");
    sockfd = mx_creating_server(argv[1]);
    pthread_mutex_init(&mutex, NULL);
    mx_accept_loop(sockfd);
}
