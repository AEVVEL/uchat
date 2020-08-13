#include "libmx.h"
//берет кол-во символов len с начала строки src и перезаписывает на такое же к-во символов в строку dst (просто зпаменяет одни символы на другие)
char *mx_strncpy(char *dst, const char *src, int len) {
    char *sv = dst;

    while (len-- && *src) {
        *dst++ = *src++;
    }
    while (len-- + 1) {
        *dst = '\0';
        dst++;
    }
    return sv;
}
