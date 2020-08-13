#include "libmx.h"
//ищет с начала строки символ needle и возвращает этот символ и остаток строчки после него до самого конца
char *mx_strstr(const char *haystack, const char *needle){
    const char *save = haystack;
    int len = mx_strlen(needle);
    
    if (!len) {
        return (char *) haystack;
    }
    for (int i = 0; i <= mx_strlen(save) - len; i++) {
        if (!mx_strncmp(haystack, needle, len)) {
            return (char *) haystack;
        }
        haystack++;
    }

    return NULL;
}
