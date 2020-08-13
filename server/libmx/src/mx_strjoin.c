#include "libmx.h"

char *mx_strjoin(char const *s1, char const *s2) {
    char *res = NULL;

    if (!s1 && !s2) {
        return NULL;
    }
    if (!s1) {
        res = mx_strnew(mx_strlen(s2));
        return mx_strcpy(res, s2);
    }
    if (!s2) {
        res = mx_strnew(mx_strlen(s1));
        return mx_strcpy(res, s1);
    }
    res = mx_strnew(mx_strlen(s1) + mx_strlen(s2));
    mx_strcat(res, s1);
    mx_strcat(res, s2);
    return res;
}
