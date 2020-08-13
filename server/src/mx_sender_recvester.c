#include "../inc/uchat.h"

void mx_sender(int new_fd, char *message) {
    pthread_mutex_lock(&mutex);
    int sended_now;
    int sended = 0;
    int message_len = strlen(message);
    char *message_len_str = mx_itoa(message_len);

    if (send(new_fd, message_len_str, strlen(message_len_str), 0) == -1) {
        perror("send");
        close(new_fd);
        mx_del_log_in_user(new_fd);
        pthread_mutex_unlock(&mutex);
        pthread_exit(0);
    }
    while (sended < message_len) {
        if ((sended_now = send(new_fd, message, message_len - sended < MAXDATASIZE ? message_len - sended : MAXDATASIZE, 0)) == -1 || sended_now == 0) {
            perror("send");
            close(new_fd);
            mx_del_log_in_user(new_fd);
            pthread_mutex_unlock(&mutex);
            pthread_exit(0);
        }
        sended += sended_now;
        message += sended_now;
    }
    mx_strdel(&message_len_str);
    pthread_mutex_unlock(&mutex);
}

int messege_len(int new_fd) {
    char buf[100];
    int len;
    int r;

    if ((r = recv(new_fd, buf, 100, 0)) == -1 || r == 0) {
        perror("recv");
        close(new_fd);
        mx_del_log_in_user(new_fd);
        pthread_mutex_unlock(&mutex);
        pthread_exit(0);
    }
    len = atoi(buf);
    return len;
}

char *mx_recvester(int new_fd) {
    pthread_mutex_lock(&mutex);
    char *recv_buf;
    int recvested = 0;
    int recvested_now = 0;
    char *message_buf = mx_strnew(25000);
    int len = messege_len(new_fd);
    char *message;

    if (len == 0) {
        close(new_fd);
        mx_del_log_in_user(new_fd);
        pthread_mutex_unlock(&mutex);
        pthread_exit(0);
    }
    while (recvested < len) {
        recv_buf = mx_strnew(25000);
        if ((recvested_now = recv(new_fd, recv_buf, MAXDATASIZE, 0)) == -1 || recvested_now == 0) {
            perror("recv");
            close(new_fd);
            mx_del_log_in_user(new_fd);
            pthread_mutex_unlock(&mutex);
            pthread_exit(0);
        }
        for (int i = 0; i < recvested_now; i++)
            message_buf[recvested + i] = recv_buf[i];
        mx_strdel(&recv_buf);
        recv_buf = NULL;
        recvested += recvested_now;
    }
    message = strdup(message_buf);
    mx_strdel(&message_buf);
    pthread_mutex_unlock(&mutex);
    return message;
}
