#include "libmx.h"

 void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {
 	char *dp = dst;
 	const char *sp = src;

 	while(n--) {
 		*dp++ = *sp++;
 	}
 	return dst;
 }
