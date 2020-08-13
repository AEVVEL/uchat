#include "../inc/uchat.h"

char *mx_new_message_id() {
    char *file = mx_file_to_str(MESSAGES);
    int count_messages = mx_count_words(file, '\v');
    char *new_id;

    if (count_messages == -1)
        count_messages = 0;
    new_id = mx_itoa(count_messages + 1);
    mx_strdel(&file);
    return new_id;
}

void mx_add_message(char *message, char *login) {
    char *str;
    char *tmp = "\t";
    char *buf;
    long t;
    int fd;

    str = mx_replace_substr(message, "\t", " ");
    message = str;
    str = mx_replace_substr(message, "\v", " ");
    mx_strdel(&message);
    message = str;

    str = mx_strcat(tmp, login); // \tlogin
    tmp = str;
    str = mx_strcat(tmp, "\t"); // \t login \t
    mx_strdel(&tmp);
    tmp = str;
    str = mx_strcat(tmp, message); // \t login \t message
    mx_strdel(&tmp);
    tmp = str;
    str = mx_strcat(tmp, "\t"); // \t login \t message \t
    mx_strdel(&tmp);
    tmp = str;
    t = time(NULL);
    buf = ctime(&t);
    tmp = mx_strnew(24);
    for (int i = 0; i < 24; i++)
        tmp[i] = buf[i];
    str = mx_strcat(str, tmp); // \t login \t message \t time
    mx_strdel(&tmp);
    tmp = str;
    buf = mx_new_message_id();
    str = mx_strcat(buf, tmp); // m_id \t login \t message \t time
    mx_strdel(&buf);
    mx_strdel(&tmp);
    fd = open(MESSAGES, O_WRONLY|O_APPEND);
    write(fd, str, strlen(str));
    write(fd, "\v", 1);
    close(fd);
    mx_strdel(&str);
}

void mx_send_message_first(int sockfd) {
    char *messages = mx_file_to_str(MESSAGES);

    if (messages != NULL)
        //mx_sender(sockfd, messages);
        write(sockfd, messages, strlen(messages));
}

// void mx_mailing_messages(char *message, char *login) {
//     char *messages;
//     char **fd_mas = NULL;
//     int i = 0;
//     int count = mx_count_words(online, '\n');
//     char *tmp;

//     mx_add_message(message, login);
//     messages = mx_file_to_str(MESSAGES);
//     fd_mas = mx_strsplit(online, '\n');
//     if (count > 1) {
//         for (i = 0; fd_mas[i] != NULL; i++) {
//             mx_sender(atoi(fd_mas[i]), messages);
//         }
//     }
//     else {
//         tmp = mx_del_extra_spaces(online);
//         mx_sender(atoi(tmp), messages);
//     }
    
//     mx_printstr("Sended\n");
//     mx_strdel(&messages);
//     mx_del_strarr(&fd_mas);
// }
void mx_mailing_messages(char *message, char *login, int *sended) {
    // pthread_mutex_lock(&mutex);
    char *messages;
    char **fd_mas = NULL;
    int i = 0;
    int count = mx_count_words(online, '\n');
    char *tmp;

    mx_add_message(message, login);
    messages = mx_file_to_str(MESSAGES);

    char **mes = mx_strsplit(messages, '\v');
    int fd = open(UNSEND, O_WRONLY);
    int j = 0;

    while (mes[j] != NULL) {
        if (j >= *sended) {
            write(fd, mes[j], strlen(mes[j]));
            write(fd, "\v", 1);
        }
        j++;
    }
    close(fd);
    mx_del_strarr(&mes);
    mx_strdel(&messages);
    messages = mx_file_to_str(UNSEND);
    *sended = j;

    fd_mas = mx_strsplit(online, '\n');
    if (count > 1) {
        for (i = 0; fd_mas[i] != NULL; i++) {
            // mx_sender(atoi(fd_mas[i]), messages);
            write(atoi(fd_mas[i]), messages, strlen(messages));
        }
    }
    else {
        tmp = mx_del_extra_spaces(online);
        //mx_sender(atoi(tmp), messages);
        write(atoi(tmp), messages, strlen(messages));
    }
    
    mx_printstr("Sended\n");
    mx_strdel(&messages);
    mx_del_strarr(&fd_mas);
    // pthread_mutex_unlock(&mutex);
    fd = open(UNSEND, O_WRONLY);
    write(fd, "", 0);
    close(fd);
}
