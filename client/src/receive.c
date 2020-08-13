#include "../inc/uchat.h"

char *mx_mess_recvester(int new_fd, int *last) {
    // char *recv_buf;
    // int recvested = 0;
    // int recvested_now = 0;
    // char *message_buf = mx_strnew(25000);
    // int len = messege_len(new_fd);
    char *message;
    *last = 0;

    // if (len == 0) {
    //     close(new_fd);
    //     printf("Exit !");
    //     exit(1);
    // }
    // while (recvested < len) {
    //     recv_buf = mx_strnew(250000);
    //     if ((recvested_now = recv(new_fd, recv_buf, 250000, 0)) == -1) {
    //         perror("recv");
    //         close(new_fd);
    //         exit(1);
    //     }
    //     for (int i = 0; i < recvested_now; i++)
    //         message_buf[recvested + i] = recv_buf[i];
    //     free(recv_buf);
    //     recv_buf = NULL;
    //     recvested += recvested_now;
    // }
    // message = strdup(message_buf);
    // free(message_buf);
    message = mx_strnew(25000);
    read(new_fd, message, 25000);
    //


    //*last = pars_and_print(message, *last);
/////////////////////////////////////////////////////////
    char **buf_of_mess = NULL;
    buf_of_mess = mx_strsplit(message, '\v');
    mx_print_strarr(buf_of_mess, "\n");
///////////////////////////////////////////////////////

    return message;
}

char *mx_recvester(int new_fd) {
    char *recv_buf;
    int recvested = 0;
    int recvested_now = 0;
    char *message_buf = mx_strnew(25000);
    int len = messege_len(new_fd);
    char *message;

    if (len == 0) {
        close(new_fd);
        exit(1);
    }
    while (recvested < len) {
        recv_buf = mx_strnew(250000);
        if ((recvested_now = recv(new_fd, recv_buf, 250000, 0)) == -1) {
            perror("recv");
            close(new_fd);
            exit(1);
        }
        for (int i = 0; i < recvested_now; i++)
            message_buf[recvested + i] = recv_buf[i];
        free(recv_buf);
        recv_buf = NULL;
        recvested += recvested_now;
    }
    message = strdup(message_buf);
    free(message_buf);
    printf("client: received '%s'\n\n", message);
    return message;
}
