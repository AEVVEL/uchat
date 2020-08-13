#include "../inc/uchat.h"

static void *get_in_addr(struct sockaddr *sa) { 
    if (sa->sa_family == AF_INET) { 
        return &(((struct sockaddr_in*)sa)->sin_addr); 
    } 
    return &(((struct sockaddr_in6*)sa)->sin6_addr); 
}

static int do_accept(struct sockaddr_storage *their_addr, int sockfd) {
    int new_fd = 0;
    socklen_t sin_size;
    struct sockaddr_storage tmp;

    sin_size = sizeof *their_addr;
    new_fd = accept(sockfd, (struct sockaddr *)&tmp, &sin_size);
    *their_addr = tmp;
    if (new_fd == -1)
        perror("accept");
    return new_fd;
}

static int sended_messages() {
    char *messages = mx_file_to_str(MESSAGES);
    int sended = mx_count_words(messages, '\v');

    mx_strdel(&messages);
    return sended;
}


static void *send_recv_loop(void* new_fd) {
    char *recvest;
    char *login;
    long t = time(NULL);
    int sended;

    struct sockaddr peer;
    int peer_len;

    login = mx_login_reg(*(int*)new_fd);
    printf("user %s signin\n", login);
    printf("%s\n", online);
    while (time(NULL) - t < 4);
    mx_send_message_first(*(int*)new_fd);
    sended = sended_messages();
    while (1) {
        peer_len = sizeof(peer);
        if (getpeername(*(int*)new_fd, &peer, (socklen_t*)&peer_len) == -1) {
            perror("Peername");
            close(*(int*)new_fd);
            pthread_exit(0);
        }
        //recvest = mx_recvester(*(int*)new_fd);
        recvest = mx_strnew(25000);
        read(*(int*)new_fd, recvest, 25000);
        //
        printf("message - %s\n", recvest);
        mx_mailing_messages(recvest, login, &sended);
        mx_strdel(&recvest);
    }
}

pthread_mutex_t mutex;

void mx_accept_loop(int sockfd) {
    struct sockaddr_storage their_addr;
    int new_fd = 0;
    char s[INET6_ADDRSTRLEN];
    pthread_t thread;

    while (1) {
        new_fd = do_accept(&their_addr, sockfd);
        if (new_fd == -1)
            continue;
        inet_ntop(their_addr.ss_family,
                  get_in_addr((struct sockaddr *)&their_addr), s, sizeof s);
        printf("server: got connection from %s\n", s);
        pthread_mutex_init(&mutex, NULL);
        pthread_create(&thread, NULL, send_recv_loop, (void*)&new_fd);
    }
}
