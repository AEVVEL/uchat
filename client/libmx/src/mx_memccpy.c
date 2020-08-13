#include "libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n) {
	unsigned char *pdst = dst;
	unsigned const char *psrc = src;
	size_t i = 0;

	while (i < n) {
		pdst[i] = psrc[i];
		if (pdst[i] == (unsigned char) c)
		{
			return (void *) ((unsigned char) dst + i + 1);
		}
		i++;
	}
	return NULL;
}
