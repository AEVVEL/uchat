#include "../inc/uchat.h"

void memcpy_reverse(char **dst, const char *src, size_t n, size_t m) {
    int i;
    int counter = 0;

    for (i = 0; i < (int)n; i++) {
        ((unsigned char*)dst)[counter] = ((unsigned char*)src)[counter + m];
        counter++;
    }
}
