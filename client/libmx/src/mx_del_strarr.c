#include "libmx.h"

void mx_del_strarr (char ***arr) {
    char **d_arr = *arr;

    while (*d_arr) {
        mx_strdel(d_arr);
        d_arr++;
    }
    free(*arr);
    *arr = NULL;
}
