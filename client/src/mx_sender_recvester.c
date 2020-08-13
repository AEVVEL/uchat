#include "../inc/uchat.h"

void mx_sender(int new_fd, char *message) {
    int sended_now;
    int sended = 0;
    int message_len = strlen(message);
    char *message_len_str = mx_itoa(message_len);
    int s;

    if ((s = send(new_fd, message_len_str, strlen(message_len_str), 0)) == -1 || s == 0) {
        perror("send");
        exit(1);
    }
    while (sended < message_len) {
        if ((sended_now = send(new_fd, message, message_len - sended, 0)) == -1 || sended_now == 0) {
            perror("send");
            exit(1);
        }
        sended += sended_now;
        message += sended_now;
    }
    free(message_len_str);
}

int messege_len(int new_fd) {
    char buf[100];
    int len;

    if (recv(new_fd, buf, 100, 0) == -1) {
        perror("recv");
        close(new_fd);
        exit(1);
    }
    len = atoi(buf);
    return len;
}
