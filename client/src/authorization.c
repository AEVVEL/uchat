#include "../inc/uchat.h"

static bool signup(int sockfd, char **answer) {
    char *data;
    char *buf;
    char *pass_buf;

    //free(answer);
    data = mx_strnew(100);
    strcat(data, "signup:");
    printf("%s\n", "Print your Login: ");
    buf = lsh_read_line();
    strcat(data, buf);
    strcat(data, ":");
    free(buf);
    printf("%s\n", "Print your Password: ");
    buf = lsh_read_line();
    printf("%s\n", "Print your Password again: ");
    pass_buf = lsh_read_line();
    if (strcmp(buf, pass_buf) == 0) {
        free(pass_buf);
        pass_buf = md5_string(buf);
        strcat(data, pass_buf);
        free(buf);
        free(pass_buf);
        mx_send(sockfd, data);
        free(data);
        //*answer = mx_recvester(sockfd);
        *answer = mx_strnew(25000);
        read(sockfd, *answer, 25000);
        //
        if (strcmp(*answer, "yes") == 0) {
            printf("%s\n", "You are loged ");
            return true;
        }
        else {
            printf("%s\n", "Incorrect login or password ");
            return false;
        }
    }
    else {
        printf("%s\n", "Incorrect password ");
        return false;
    }
}

static bool signin(int sockfd, char **answer) {
    char *data;
    char *buf;
    char *pass_buf;

    //free(answer);
    data = mx_strnew(100);
    strcat(data, "signin:");
    printf("%s\n", "Print your Login: ");
    buf = lsh_read_line();
    strcat(data, buf);
    strcat(data, ":");
    free(buf);
    printf("%s\n", "Print your Password: ");
    buf = lsh_read_line();
    pass_buf = md5_string(buf);
    strcat(data, pass_buf);
    free(buf);
    free(pass_buf);
    mx_send(sockfd, data);
    free(data);
    //*answer = mx_recvester(sockfd);
    *answer = mx_strnew(25000);
    read(sockfd, *answer, 25000);
    //
    if (strcmp(*answer, "yes") == 0) {
        printf("%s\n", "You are loged ");
        return true;
    }
    else {
        printf("%s\n", "Incorrect login or password ");
        return false;
    }
}

bool mx_autirization(int sockfd) {
    char *answer;

    while (1) {
        printf("%s\n", "Signin or Signup ?");
        answer = lsh_read_line();
        if (strcmp(answer, "Signup") == 0) {
            if (signup(sockfd, &answer) == true)
                return true;
        }
        else if(strcmp(answer, "Signin") == 0) {
           if (signin(sockfd, &answer) == true)
                return true;
        }
    }
}





