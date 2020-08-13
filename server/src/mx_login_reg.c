#include "../inc/uchat.h"

// static int arr_len(char **arr) {
//     int len = 0;

//     while (arr[len] != NULL) {
//         arr++;
//     }
//     return len;
    
// }

char **mx_get_user(char *login) {
    char *pas_to_file = NULL;
    char *tmp;
    char **user;
    
    asprintf(&pas_to_file, "./server/helpful_files/users/%s", login);
    if (access(pas_to_file, 00) == -1)
        return NULL;
    tmp = mx_file_to_str(pas_to_file);
    user = mx_strsplit(tmp, '\n');
    mx_strdel(&tmp);
    return user;
}

bool mx_signin(char **signin, int sockfd) {
    char **user = mx_get_user(signin[1]);

    if (user == NULL)
        return false;
    if ((strcmp(user[0], signin[1]) == 0 && strcmp(user[1], signin[2]) == 0) == 1) {
        mx_add_log_in_user(sockfd);
        printf("%d\n", sockfd);
        mx_del_strarr(&user);

        return true;
    }
    mx_del_strarr(&user);
    return false;
}

bool mx_signup(char **signup, int sockfd) {
    char **user = mx_get_user(signup[1]);
    char *pas_to_file;
    int fd;

    if (user != NULL) {
        mx_del_strarr(&user);
        return false;
    }
    asprintf(&pas_to_file, "./server/helpful_files/users/%s", signup[1]);
    FILE * fp = fopen(pas_to_file, "a+");
    fclose(fp);
    fd = open(pas_to_file, O_WRONLY);
    write(fd, signup[1], strlen(signup[1]));
    write(fd, "\n", 1);
    write(fd, signup[2], strlen(signup[2]));
    close(fd);
    mx_add_log_in_user(sockfd);
    printf("%d\n", sockfd);
    mx_strdel(&pas_to_file);
    return true;
}

char *mx_login_reg(int sockfd) {
    char *str;
    char **mas;
    bool try;
    char *login;

    int r;

    while(1) {
        //str = mx_recvester(sockfd);
        str = mx_strnew(25000);
        if ((r = read(sockfd, str, 25000)) == -1 || r == 0)
            pthread_exit(0); 
        //
        mas = mx_strsplit(str, ':');
        mx_printstr(str);
        mx_printstr("\n");
        login = strdup(mas[1]);
        if (strcmp(mas[0], "signin") == 0)
            try = mx_signin(mas, sockfd);
        if (strcmp(mas[0], "signup") == 0)
            try = mx_signup(mas, sockfd);
        mx_strdel(&str);
        mx_del_strarr(&mas);
        if (try == true) {
            //mx_sender(sockfd, "yes");
            write(sockfd, "yes", strlen("yes"));
            printf("Yes\n");
            return login;
        }
        else {
            //mx_sender(sockfd, "no");
            write(sockfd, "no", strlen("no"));
            printf("No\n");
        }
        mx_strdel(&login);
    }
    return "FAIL";
}
