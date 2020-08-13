#include "libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
	const unsigned char *s1_1 = s1;
    const unsigned char *s2_2 = s2;

    while (n--) {
        if (*s1_1 != *s2_2) {
            return *s1_1 - *s2_2;
        }
        s1_1++;
        s2_2++;
    }
    return 0;
}
