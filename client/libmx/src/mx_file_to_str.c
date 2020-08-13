#include "libmx.h"

char *mx_file_to_str(const char *file) {
    int read_file = 0;
    int size_read = 0;
    int size_file = 0;
    char buf[128];
    char *res = NULL;
    char *tmp_str = NULL;

    read_file = open(file, O_RDONLY);
    if (read_file < 0)
        return NULL;

    while ((size_read = read(read_file, buf, sizeof(buf) - 1)) > 0) {
        buf[size_read] = '\0';
        size_file += size_read;
        tmp_str = mx_strjoin(res, buf);
        mx_strdel(&res);
        res = mx_strdup(tmp_str);
        mx_strdel(&tmp_str);
    }
    if (close(read_file) < 0) {
        return NULL;
    }

    return res;
}
