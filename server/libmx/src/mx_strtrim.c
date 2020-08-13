#include "libmx.h"

char *mx_strtrim(const char *str) {
    if (!str)
        return NULL;

    int left = 0;
    int right = 0;
    int len = mx_strlen(str);
    char *res = NULL;

    for (int i = 0; i < len; i++) {
        if (mx_isspace(str[i])) {
            left++;
            continue;
        }
        break;
    }
    for (int i = len - 1; i >= 0; i--) {
        if (mx_isspace(str[i])) {
            right++;
            continue;
        }
        break;
    }
    if (left == len) {
        return mx_strnew(0);
    }
    res = mx_strnew(len - left - right);
    return mx_strncpy(res, str + left, len - left - right);
}
