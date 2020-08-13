#include "../inc/uchat.h"


void mx_add_log_in_user(int userfd) {
    char *userfd_str = mx_itoa(userfd);
    char *tmp;
    
    tmp = online;
    online = mx_strcat(tmp, "\n");
    mx_strdel(&tmp);
    tmp = online;
    online = mx_strcat(online, userfd_str);
    mx_strdel(&userfd_str);
    mx_strdel(&tmp);
}

void mx_del_log_in_user(int userfd) {
    char *userfd_str = mx_itoa(userfd);
    char *tmp = mx_replace_substr(online, userfd_str, "");

    mx_strdel(&userfd_str);
    mx_strdel(&online);
    online = tmp;
}
